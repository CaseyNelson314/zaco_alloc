#ifndef ZACO_ALLOC_H
#define ZACO_ALLOC_H


#ifndef ZACO_MALLOC_CAPACITY
#define ZACO_MALLOC_CAPACITY 4096
#endif


#include <stdlib.h>
#include <stdint.h>

/**
 * @brief unfreeable memory allocator
 * @param size alloc size
 * @return allocated memory pointer
 */
void* zaco_malloc(size_t size)
{
    static void* head;
    static void* curr;

    if (!head || (uint8_t*)curr - (uint8_t*)head + size > ZACO_MALLOC_CAPACITY)
    {
        void* p = malloc(ZACO_MALLOC_CAPACITY);
        if (p)
        {
            head = p;
            curr = head;
        }
        else
        {
            return NULL;
        }
    }

    return curr;
}

#endif

