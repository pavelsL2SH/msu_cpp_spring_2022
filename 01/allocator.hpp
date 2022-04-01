#pragma once
#include <stddef.h>

class Allocator
{
  private:
    size_t offset;
    size_t memorySize;
    char *ptr_;
  public:
    void makeAllocator(size_t maxSize);
    char* alloc(size_t size);
    void reset();
    // Это деструктор!
    ~Allocator();
};
