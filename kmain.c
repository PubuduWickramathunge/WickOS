#include "serial_port.h"
#include "segments.h"
#include "interrupts.h"
#include "multiboot.h"
#include "paging.h"
#include "paging.h"

/* Function to initialize */
 void init(u32int kernelPhysicalStart, u32int kernelPhysicalEnd) {
  /* Initialize segment descriptor tables */
  init_gdt();

  /* Configure serial port */
  serial_configure(SERIAL_COM1_BASE, Baud_115200);
  
  /* Initialize paging */
  init_paging(kernelPhysicalStart, kernelPhysicalEnd);
  
  /* Initialize idt */
  interrupts_install_idt();
  
}

/* Kernel Main */
 s32int kmain(u32int kernelPhysicalStart, u32int kernelPhysicalEnd) {
	
    	// Initialize all modules
   	init(kernelPhysicalStart, kernelPhysicalEnd);
  	 
  	return 0;
}
