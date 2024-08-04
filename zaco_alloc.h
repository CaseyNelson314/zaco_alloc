#ifndef ZACO_ALLOC_H
#define ZACO_ALLOC_H


#ifndef ZACO_MALLOC_CAPACITY
#define ZACO_MALLOC_CAPACITY 4096
#endif


#include <stdlib.h>
#include <stdint.h>

/**
 * @brief Allocator assuming that it is not released.
 * @param size alloc size
 * @return allocated memory
 */
void* zaco_malloc(size_t size)
{
    static void* head;
    static void* curr;

    assert(size <= ZACO_MALLOC_CAPACITY);

    if (!head || (uint8_t*)curr + size >= (uint8_t*)head + ZACO_MALLOC_CAPACITY)
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

    void* p = curr;

    curr = (uint8_t*)curr + size;

    return p;
}

#endif

