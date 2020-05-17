#ifndef __REGISTERS_H
#define __REGISTERS_H

#define MMIO_BASE       0x3F000000

// GPIO (offset = (MMIO_BASE+0x00200000)
#define REG_GPFSEL0             ((volatile unsigned int*)(MMIO_BASE+0x00200000))
#define REG_GPFSEL1             ((volatile unsigned int*)(MMIO_BASE+0x00200004))
#define REG_GPFSEL2             ((volatile unsigned int*)(MMIO_BASE+0x00200008))
#define REG_GPFSEL3             ((volatile unsigned int*)(MMIO_BASE+0x0020000C))
#define REG_GPFSEL4             ((volatile unsigned int*)(MMIO_BASE+0x00200010))
#define REG_GPFSEL5             ((volatile unsigned int*)(MMIO_BASE+0x00200014))

#define REG_GPSET0              ((volatile unsigned int*)(MMIO_BASE+0x0020001C))
#define REG_GPSET1              ((volatile unsigned int*)(MMIO_BASE+0x00200020))

#define REG_GPCLR0              ((volatile unsigned int*)(MMIO_BASE+0x00200028))
#define REG_GPCLR1              ((volatile unsigned int*)(MMIO_BASE+0x0020002C))

#define REG_GPLEV0              ((volatile unsigned int*)(MMIO_BASE+0x00200034))
#define REG_GPLEV1              ((volatile unsigned int*)(MMIO_BASE+0x00200038))

#define REG_GPEDS0              ((volatile unsigned int*)(MMIO_BASE+0x00200040))
#define REG_GPEDS1              ((volatile unsigned int*)(MMIO_BASE+0x00200044))

#define REG_GPREN0              ((volatile unsigned int*)(MMIO_BASE+0x0020004C))
#define REG_GPREN1              ((volatile unsigned int*)(MMIO_BASE+0x00200050))

#define REG_GPFEN0              ((volatile unsigned int*)(MMIO_BASE+0x00200058))
#define REG_GPFEN1              ((volatile unsigned int*)(MMIO_BASE+0x0020005C))

#define REG_GPHEN0              ((volatile unsigned int*)(MMIO_BASE+0x00200064))
#define REG_GPHEN1              ((volatile unsigned int*)(MMIO_BASE+0x00200068))

#define REG_GPHEN0              ((volatile unsigned int*)(MMIO_BASE+0x00200064))
#define REG_GPHEN1              ((volatile unsigned int*)(MMIO_BASE+0x00200068))

#define REG_GPLEN0              ((volatile unsigned int*)(MMIO_BASE+0x00200070))
#define REG_GPLEN1              ((volatile unsigned int*)(MMIO_BASE+0x00200074))

#define REG_GPAREN0             ((volatile unsigned int*)(MMIO_BASE+0x0020007C))
#define REG_GPAREN1             ((volatile unsigned int*)(MMIO_BASE+0x00200080))

#define REG_GPAFEN0             ((volatile unsigned int*)(MMIO_BASE+0x00200088))
#define REG_GPAFEN1             ((volatile unsigned int*)(MMIO_BASE+0x0020008C))

#define REG_GPPUD               ((volatile unsigned int*)(MMIO_BASE+0x00200094))
#define REG_GPPUDCLK0           ((volatile unsigned int*)(MMIO_BASE+0x00200098))
#define REG_GPPUDCLK1           ((volatile unsigned int*)(MMIO_BASE+0x0020009C))

// Auxiliary peripherals (offset = (MMIO_BASE+0x00215000)
#define REG_AUX_IRQ             ((volatile unsigned int*)(MMIO_BASE+0x00215000))
#define REG_AUX_ENABLES         ((volatile unsigned int*)(MMIO_BASE+0x00215004))

#define REG_AUX_MU_IO_REG       ((volatile unsigned int*)(MMIO_BASE+0x00215040))
#define REG_AUX_MU_IER_REG      ((volatile unsigned int*)(MMIO_BASE+0x00215044))
#define REG_AUX_MU_IIR_REG      ((volatile unsigned int*)(MMIO_BASE+0x00215048))
#define REG_AUX_MU_LCR_REG      ((volatile unsigned int*)(MMIO_BASE+0x0021504C))
#define REG_AUX_MU_MCR_REG      ((volatile unsigned int*)(MMIO_BASE+0x00215050))
#define REG_AUX_MU_LSR_REG      ((volatile unsigned int*)(MMIO_BASE+0x00215054))
#define REG_AUX_MU_MSR_REG      ((volatile unsigned int*)(MMIO_BASE+0x00215058))
#define REG_AUX_MU_SCRATCH      ((volatile unsigned int*)(MMIO_BASE+0x0021505C))
#define REG_AUX_MU_CNTL_REG     ((volatile unsigned int*)(MMIO_BASE+0x00215060))
#define REG_AUX_MU_STAT_REG     ((volatile unsigned int*)(MMIO_BASE+0x00215064))
#define REG_AUX_MU_BAUD_REG     ((volatile unsigned int*)(MMIO_BASE+0x00215068))




#endif // __REGISTERS_H