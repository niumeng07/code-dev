#include <stdio.h>
#include "hashmap.h"

int main()
{
    hashmap *pfilterMap;
    pfilterMap = mk_hmap(str_hash_fn, str_eq_fn, str_del_fn,NEED);

    if(!hmap_add(pfilterMap, (void*)"key", (void*)"value"))
        return 0;
    printf( "%s\n", (char*)hmap_get(pfilterMap, (void*)"key") );
    free_hmap(pfilterMap);
    pfilterMap = NULL;
    return 0;
}
