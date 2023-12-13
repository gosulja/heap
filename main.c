#include <stddef.h>

#define HEAP_SIZE 10000

typedef struct
{
    size_t size;
    char *data;
} Block;

typedef struct
{
    char memory[HEAP_SIZE];
    size_t used;
} Allocator;

void init_allocator(Allocator *allocator) {
    allocator->used = 0;
}

void* allocate(Allocator *allocator, size_t size) {
    if (allocator-> used + size > HEAP_SIZE) {
        return NULL;
    }

    void *pointer = allocator->memory + allocator->used;
    allocator->used += size;

    Block *block = (Block*)pointer;
    block->size = size;
    block->data = (char*)pointer + sizeof(Block);

    return block->data;
}

void deallocate(Allocator *allocator, void *pointer) {
    // will implement soon
}

void reset_allocator(Allocator *allocator) {
    allocator->used = 0;
}

int main() {
    // example

    Allocator allocator;
    init_allocator(&allocator);

    // allocate sum memory
    int *int_pointer = (int*)allocate(&allocator, sizeof(int));
    if (int_pointer != NULL) {
        *int_pointer = 42;
        printf("allocated int: %d\n", *int_pointer);
    }

    // reset
    reset_allocator(&allocator);

    // allocate sum more data
    char *str = (char*)allocate(&allocator, 10);
    if (str != NULL) {
        strcpy(str, "hello");
        printf("allocated string: %s\n", str);
    }

    return 0;
}
