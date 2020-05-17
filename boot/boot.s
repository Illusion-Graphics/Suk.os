.section ".text.boot"

.global _start
.type _start, "function"
_start:
    // Warning!
    // Do not use registers x0-x4 as theya re used to pass args to
    // the kernel.
    //   - x0: 32bits DTB root pointer
    //   - x1: Reserved
    //   - x2: Reserved
    //   - x3: Reserved
    //   - x4: 32bits Kernel start address

    // Read CPU core ID to make sure we are on core 0 and send the others to spin
    // RPi should already send the other cores to spin
    mrs     x5, mpidr_el1
    and     x5, x5, #3
    cbz     x5, boot

spin: 
    wfe
    b       spin


boot:
    // Set the stack before the text section (arm descending growth)
    ldr     x5, = _start
    mov     sp, x5

clear_bss:
    // Clear the bss section
    ldr     x5, =__bss_start
    ldr     x6, =__bss_end
3:  cmp     x5, x6
    beq     _main
    str     wzr, [x6]
    sub     x6, x6, #1
    b       3b

_main:
    // Clear higher 32bits of the dtb address
    and     x0, x0, #0xFFFFFFFF

    // Jump to C++ kerenel code
    bl      kernel_main
    b       _main
