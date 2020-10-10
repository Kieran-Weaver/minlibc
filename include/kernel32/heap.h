#ifndef KERNEL32_HEAP_H
#define KERNEL32_HEAP_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  void* lpData;
  uint32_t cbData;
  uint8_t  cbOverhead;
  uint8_t  iRegionIndex;
  uint16_t  wFlags;
  union {
    struct {
      void* hMem;
      uint32_t  dwReserved[3];
    } Block;
    struct {
      uint32_t  dwCommittedSize;
      uint32_t  dwUnCommittedSize;
      void* lpFirstBlock;
      void* lpLastBlock;
    } Region;
  } DUMMYUNIONNAME;
} process_heap_entry_t;

typedef struct {
  uint32_t  cb;
  size_t cbAllocated;
  size_t cbCommitted;
  size_t cbReserved;
  size_t cbMaxReserve;
} heap_summary_t;

__declspec(dllimport) void* GetProcessHeap();
__declspec(dllimport) uint32_t GetProcessHeaps(uint32_t n, void** heaps);
__declspec(dllimport) void* HeapAlloc(void* heap, uint32_t flags, size_t uint8_ts);
__declspec(dllimport) size_t HeapCompact(void* heap, uint32_t flags);
__declspec(dllimport) void* HeapCreate(uint32_t options, size_t iSize, size_t maxSize);
__declspec(dllimport) int HeapDestroy(void* heap);
__declspec(dllimport) int HeapFree(void* heap, uint32_t flags, void* ptr);
__declspec(dllimport) int HeapLock(void* heap);
__declspec(dllimport) int HeapQueryInformation(void*, int, void*, size_t, size_t*);
__declspec(dllimport) void* HeapReAlloc(void*, uint32_t, void*, size_t);
__declspec(dllimport) int HeapSetInformation(void*, int, void*, size_t);
__declspec(dllimport) size_t HeapSize(void*, uint32_t, const void*);
__declspec(dllimport) int HeapSummary(void*, uint32_t, heap_summary_t*);
__declspec(dllimport) int HeapUnlock(void* heap);
__declspec(dllimport) int HeapValidate(void*, uint32_t, const void*);
__declspec(dllimport) int HeapWalk(void*, process_heap_entry_t*);

#ifdef __cplusplus
}
#endif

#endif
