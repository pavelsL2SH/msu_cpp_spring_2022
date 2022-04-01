#include "allocator.hpp"

Allocator::~Allocator()
{
  delete ptr_;
}

void Allocator::makeAllocator(size_t maxSize)
{
  if (ptr_ != nullptr) delete ptr_;
  offset = 0;
  memorySize = maxSize;
  ptr_ = new char[maxSize];
}

char* Allocator::alloc(size_t size)
{
  if (offset + size > memorySize) return nullptr;
  char* temp = ptr_ + offset;
  offset += size;
  return temp;
}

void Allocator::reset()
{
  offset = 0;
  memorySize = 0;
}
