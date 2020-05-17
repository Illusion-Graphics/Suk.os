# Tools
export CCLANG		:= clang
export CPPCLANG		:= clang++
export LD			:= ld.lld
export OBJCOPY		:= llvm-objcopy-6.0


# Platform
export ARCH			:= aarch64-elf
export ARCH-LD		:= aarch64elf
export CPU			:= cortex-a53+nosimd


export INCLUDE		:= ${PWD}/include/

.PHONY: all clean run drivers boot kernel

SRCS = $(wildcard *.c)
OBJS = $(wildcard $(BUILD_DIR)*.o)

export BUILD_DIR	:= ${PWD}/out/

export COMPILATION_FLAGS = -I${INCLUDE} -I${PWD} -mcpu=cortex-a53+nosimd 
export ERROR_FLAGS = -Wall -Wextra
export FEATURE_FLAGS = -ffreestanding -nostdinc -nostdlib
export FEATURE_CPP_FLAGS = -fno-exceptions -fno-rtti
export OPTIMIZATION_FLAGS = -O3

export CFLAGS = ${COMPILATION_FLAGS} ${ERROR_FLAGS} ${FEATURE_FLAGS} ${OPTIMIZATION_FLAGS} -g
export CPPFLAGS = ${COMPILATION_FLAGS} ${ERROR_FLAGS} ${FEATURE_FLAGS} ${FEATURE_CPP_FLAGS} ${OPTIMIZATION_FLAGS} -g

all: clean checkdirs boot drivers kernel ext kernel.img

boot:
	@$(MAKE) -C boot

# Build the drivers
drivers:
	@$(MAKE) -C drivers

kernel:
	@$(MAKE) -C kernel

ext:
	@$(MAKE) -C ext

kernel.img:
	$(LD) -m aarch64elf -nostdlib $(OBJS) -T boot/link.ld -o $(BUILD_DIR)kernel.elf
	$(OBJCOPY) -O binary $(BUILD_DIR)kernel.elf $(BUILD_DIR)kernel.img

clean:
	@rm -rf out/

checkdirs: $(BUILD_DIR)

$(BUILD_DIR):
	@mkdir -p $@