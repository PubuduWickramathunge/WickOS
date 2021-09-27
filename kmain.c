#include "serial.c"
#include "memory_segments.h"
#include "interrupts.h"
#include "multiboot.h"
#include "type.h"
#include "paging.h"
#include "kheap.h"
#include "user_mode.h"
#include "hardware_interrupt_enabler.h"


void init(u32int kernelPhysicalEnd) {
  /* Initialize segment descriptor tables */
  init_gdt();

  /* Configure serial port */
  serial_configure(SERIAL_COM1_BASE, Baud_115200);
  
  /* Initialize paging */
  init_paging(kernelPhysicalEnd);
  

  interrupts_install_idt();
  
}

/* Kernel Main */
int kmain(u32int kernelPhysicalEnd){

  	init(kernelPhysicalEnd);
  	
  	disable_hardware_interrupts();

   	switch_to_user_mode();
   	
	 
  	return 0;
}
