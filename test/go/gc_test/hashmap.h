/*
 * hashmap.h 
 * 
 */

#ifndef HASHMAP_H
#define HASHMAP_H

#define HMAP_PRESET_SIZE     2 <<23  // use a power of 2 for faster array access
#define HMAP_GROWTH_RATE     2

#define HMAP_MAKE_HASHFN    // build a few hash functions 
#define HMAP_THREAD_SAFE     // add "-lrt" to your GCC compile flags
#define HMAP_DESTRUCTORS    // require destructors for value clean-up

#define NEED 1 //需要做成hashCode
#define NOTNEED 0 //不需要做成hashCode

#ifdef HMAP_MAKE_HASHFN
    #include <string.h>
#endif

#ifdef HMAP_THREAD_SAFE
    #include <semaphore.h>
#endif
#include <stdint.h>
#include <stdbool.h>
// it may be a good idea to redefine key and val if the size of either is less
// than sizeof(void*). keep in mind that the default hash functions assume that
// key and val are void pointers, and will not work properly if they are changed
// to other (non-pointer) types.
 
typedef void* key;
typedef void* val;
typedef int int32;

typedef struct key_val_pair key_val_pair;
typedef struct hashmap hashmap;

// create a hashmap
hashmap* mk_hmap(uint32_t (*hash_fn)(key),
                 bool (*eq_fn)(key, key)
#ifdef HMAP_DESTRUCTORS
                 , void (*del_fn)(val)
#endif
                 ,uint32_t isNeedCalcHashCode
    );
// create a hashmap ,Specify memory Size Settings
hashmap* mk_hmap2(uint32_t (*hash_fn)(key),
                 bool (*eq_fn)(key, key)
#ifdef HMAP_DESTRUCTORS
                 , void (*del_fn)(val)
#endif
                 ,uint32_t isNeedCalcHashCode
                 ,uint32_t set_size
    );

// delete the hashmap (and if destructors are enabled, destroy all values)
void free_hmap(hashmap*);

// add a value (with a given key) to the hashmap
// returns true on success and false on failure
bool __hmap_add(hashmap* hmap, key in, val out);
#define hmap_add(hmap, in, out) __hmap_add(hmap, (key) in, (val) out)

// retrieve a value using a given key from the hashmap
// returns your value if successful and NULL if not
val __hmap_get(hashmap* hmap, key in);
#define hmap_get(hmap, obj) __hmap_get(hmap, (key) obj)

#ifdef HMAP_MAKE_HASHFN
// integer-as-key hash functions
uint32_t int_hash_fn(key);
bool int_eq_fn(key, key);
void int_del_fn(val);

// char*-as-key hash functions
uint32_t str_hash_fn(key);
bool str_eq_fn(key, key);
void str_del_fn(val);
#endif

#endif
