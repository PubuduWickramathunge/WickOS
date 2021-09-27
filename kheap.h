#ifndef INCLUDE_KHEAP_H
#define INCLUDE_KHEAP_H

#pragma once
#include "type.h"

#define KHEAP_START 0xC0000000
#define KHEAP_INITIAL_SIZE 0x100000
#define KHEAP_MAX_ADDRESS 0xCFFFF000

#define HEAP_INDEX_SIZE 0x20000
#define HEAP_MAGIC 0xC0DED00D
#define HEAP_MIN_SIZE 0x70000


void set_physical_address_top(u32int phyAddress);

/* create_kernel_heap:
 *  Create a new kernel heap.
 *
 *  @param  startAddr      Physical Address where we want to create heap
 *  @param  endAddr        Physical end address of heap
 *  @param  maxAddr        Physical address beyond which heap would not expand.
 */
void create_kernel_heap(u32int startAddr, u32int endAddr, u32int maxAddr);

/* kmalloc_int:
 *  Allocate a chunk of memory, size in size. If align == 1,
 *  the chunk must be page-aligned. If pAddrPtr != 0, the physical
 *  location of the allocated chunk will be stored into phys.
 *
 *  @param size      Size of memory to be allocated
 *  @param align     Align allocated memory at 4kb address
 *  @param pAddrPtr  Store the physical address of the page
 */
u32int kmalloc_int(u32int size, u32int align, u32int *pAddrPtr);

u32int kmalloc_a(u32int size);

/* kmalloc_p:
 *  Allocate a chunk of memory, size in size. The physical address
 *  is returned in pAddrPtr. pAddrPtr MUST be a valid pointer to u32int!
 *
 *  @param pAddrPtr  Pointer to store the physical address of
 *  the page
 */
u32int kmalloc_p(u32int sz, u32int *pAddrPtr);


u32int kmalloc_ap(u32int size, u32int *pAddrPtr);

/* kmalloc:
 *  Generic function to allocate chunk of memory, size in size.
 *
 *  @param size Size of memory to be allocated
 */
u32int kmalloc(u32int size);

void kfree(void *ptr);

#endif /* INCLUDE_KHEAP_H */