/*
 * hashmap.c
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <semaphore.h>
#include "hashmap.h"

struct key_val_pair {
    key k;
    val v;
};

struct hashmap {
    key_val_pair* map;
    uint32_t size;
    uint32_t capacity;
    uint32_t (*hash_fn)(key);
    bool (*eq_fn)(key, key);
#ifdef HMAP_DESTRUCTORS
    void (*del_fn)(val);
#endif
#ifdef HMAP_THREAD_SAFE
    sem_t lock;
    uint32_t isNeedCalcHashCode;
#endif
};

// hashmaps need a hash function, an equality function, and a destructor
hashmap* mk_hmap(uint32_t (*hash_fn)(key),
                bool (*eq_fn)(key, key)
            #ifdef HMAP_DESTRUCTORS
                , void (*del_fn)(val)
            #endif
                , uint32_t isNeedCalcHashCode
                ) {
                    
    hashmap* hmap = (hashmap*) calloc(sizeof(hashmap),1);
    //memset(hmap,0,sizeof(hashmap));
    hmap->map = (key_val_pair*) calloc(sizeof(key_val_pair) , HMAP_PRESET_SIZE);
    //memset(hmap->map,0,sizeof(key_val_pair) * HMAP_PRESET_SIZE);
    hmap->size = 0;
    hmap->capacity = HMAP_PRESET_SIZE;
    hmap->hash_fn = hash_fn;
    hmap->eq_fn = eq_fn;
#ifdef HMAP_DESTRUCTORS
    hmap->del_fn = del_fn;
#endif
#ifdef HMAP_THREAD_SAFE
    sem_init(&hmap->lock, 0, 1);
#endif
    hmap->isNeedCalcHashCode = isNeedCalcHashCode;
    return hmap;
}

hashmap* mk_hmap2(uint32_t (*hash_fn)(key),
                bool (*eq_fn)(key, key)
            #ifdef HMAP_DESTRUCTORS
                , void (*del_fn)(val)
            #endif
                , uint32_t isNeedCalcHashCode
                , uint32_t set_size
                ) {

    hashmap* hmap = (hashmap*) calloc(sizeof(hashmap),1);
    hmap->map = (key_val_pair*) calloc(sizeof(key_val_pair) , set_size);
    hmap->size = 0;
    hmap->capacity = set_size;
    hmap->hash_fn = hash_fn;
    hmap->eq_fn = eq_fn;
#ifdef HMAP_DESTRUCTORS
    hmap->del_fn = del_fn;
#endif
#ifdef HMAP_THREAD_SAFE
    sem_init(&hmap->lock, 0, 1);
#endif
    hmap->isNeedCalcHashCode = isNeedCalcHashCode;
    return hmap;
}

void free_hmap(hashmap* hmap) {
#ifdef HMAP_THREAD_SAFE
    sem_wait(&hmap->lock);
#endif

#ifdef HMAP_DESTRUCTORS
    static uint32_t it;
    for (it=0; it < hmap->size; ++it) {
        if (hmap->map[it].v != NULL) {
            hmap->del_fn(hmap->map[it].v);
        }
    }
#endif

    free(hmap->map);
    
#ifdef HMAP_THREAD_SAFE
    sem_post(&hmap->lock);
#endif

    free(hmap);
}

// open addressed hashmap insertion function
static void __oa_hmap_add(key_val_pair* map, uint32_t size, 
                          uint32_t (*hash_fn)(key),
                          key in, val out,int32 flag) {
    static uint32_t hash;
        //PRINT_INFO("add in=[%s]\n",(char *)in);
    //PRINT_INFO("flag=%d\n",flag);
    if(flag){
        hash = hash_fn(in) % size;
    }else{
        hash = *((uint32_t *)in) % size;
    }
    while (map[hash].v != NULL) {
        hash = (hash + 1) % size;
    }
    
    map[hash].k = in;
    //PRINT_INFO("add k in=[%s]\n",(char *)map[hash].k);
    map[hash].v = out;
}

bool __hmap_add(hashmap* hmap, key in, val out) {
#ifdef HMAP_THREAD_SAFE
    sem_wait(&hmap->lock);
#endif

    // performace degrades after a certain load
    if (((float) hmap->size) / hmap->capacity > 0.70) {
        key_val_pair* temp = (key_val_pair*) malloc(hmap->capacity * HMAP_GROWTH_RATE);
        //PRINT_INFO("hmap->capacity=%d",hmap->capacity);
        if (temp != NULL) {
            hmap->capacity *= HMAP_GROWTH_RATE;
        } else {
        #ifdef HMAP_THREAD_SAFE
            sem_post(&hmap->lock);
        #endif
            // we're out of memory
            return false;
        }
        
        // re-posn all elements
        static uint32_t it;
        for (it=0; it < hmap->capacity; ++it) {
            if (hmap->map[it].v != NULL) {
                __oa_hmap_add(temp, hmap->capacity, hmap->hash_fn, in, out ,hmap->isNeedCalcHashCode);
            }
        }
        
        // swap out the old map with the new one
        free(hmap->map);
        hmap->map = temp;
        //PRINT_INFO("hmap->capacity=%d",hmap->capacity);
    }
    
    __oa_hmap_add(hmap->map, hmap->capacity, hmap->hash_fn, in, out , hmap->isNeedCalcHashCode);
    hmap->size += 1;
    //PRINT_INFO("hmap->capacity=%d",hmap->capacity);
#ifdef HMAP_THREAD_SAFE
    sem_post(&hmap->lock);
#endif

    return true;
}

val __hmap_get(hashmap* hmap, key in) {
#ifdef HMAP_THREAD_SAFE
    sem_wait(&hmap->lock);
#endif

    static uint32_t hash;
    //PRINT_INFO("get in=[%s] aaaa hmap->capacity=%d",(char *)in,hmap->capacity);

    if(hmap->isNeedCalcHashCode){
        hash = hmap->hash_fn(in) % hmap->capacity;
    }else{
        //PRINT_INFO("%d %d",*((uint32_t *)in) , hmap->capacity);
        hash = *((uint32_t *)in) % hmap->capacity;
    }
    //PRINT_INFO("hash=%d",hash);
    while (hmap->map[hash].v != NULL) {
        if (hmap->eq_fn(in, hmap->map[hash].k)) {
        #ifdef HMAP_THREAD_SAFE
            //PRINT_INFO("HMAP_THREAD_SAFE");
            sem_post(&hmap->lock);
        #endif
            //PRINT_INFO("get in=[%s] bbbb",(char *)in);
            return hmap->map[hash].v;
        }

        hash = (hash + 1) % hmap->capacity;
    }


#ifdef HMAP_THREAD_SAFE
    sem_post(&hmap->lock);
#endif

    return NULL;
}

#ifdef HMAP_MAKE_HASHFN
// Robert Jenkins' 32 bit integer hash function
uint32_t int_hash_fn(key in) {
    static uint32_t a;
    a = *((uint32_t*) in);
    
    a = (a+0x7ed55d16) + (a << 12);
    a = (a^0xc761c23c) ^ (a >> 19);
    a = (a+0x165667b1) + (a << 5);
    a = (a+0xd3a2646c) ^ (a << 9);
    a = (a+0xfd7046c5) + (a << 3);
    a = (a^0xb55a4f09) ^ (a >> 16);
    
    return a;
}

bool int_eq_fn(key a, key b) {
    return *((int*) a) == *((int*) b) ? true : false;
}

void int_del_fn(val q) {};

// Dan Bernstein's string hash function (djb2)
uint32_t str_hash_fn(key in) {
    static uint32_t hash;
    //static unsigned char c;
    int c;
    ////PRINT_INFO("c:%c\n",c);
    hash = 5381;
    //c = *(unsigned char*) in++;
    //while (c != '\0') {
    while((c = *(unsigned char*)in++)){
    //    //PRINT_INFO("while\n");
    //    c = *(unsigned char*) in++;
        hash = ((hash << 5) + hash) + c;
    }
    ////PRINT_INFO("hash:%d\n",hash);
    return hash;
}

bool str_eq_fn(key a, key b) {
    return (strcmp((char*) a, (char*) b) == 0) ? true : false;
}

void str_del_fn(val q) {
    free(q);
};

#endif
