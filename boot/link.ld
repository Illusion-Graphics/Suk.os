SECTIONS
{
    . = 0x80000;

    /* Execution code */
    .text :
    {
        KEEP(*(.text.boot)) 
        *(.text .text.*)
    }

    /* Read only data */
    .rodata :
    {
        *(.rodata*)
    }

    /* Data section */
    PROVIDE(_data = .);
    .data :
    {
        *(.data .data.*)
    }

    /* Bss section */
    .bss (NOLOAD) :
    {
        . = ALIGN(8);
        __bss_start = .;
        *(.bss .bss.*)
        *(COMMON)
        __bss_end = .;
    }
}