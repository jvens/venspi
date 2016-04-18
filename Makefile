CROSS_COMPILE=arm-none-eabi-

IMG = kernel.img
ELF = kernel.elf

# Flags for Raspberry Pi 2 B 
CFLAGS += -mfpu=neon-vfpv4
CFLAGS += -mfloat-abi=hard
CFLAGS += -march=armv7-a
CFLAGS += -mtune=cortex-a7
DEFINE += -DRPI2=1

# Flags to handle lack of OS
CFLAGS += -Wall
CFLAGS += -nostartfiles

# Use the custom linker script
LFLAGS += -T rpi.x
LFLAGS += -nostartfiles

#CFLAGS += -01
CFLAGS += -O4
CFLAGS += -g

RELEASE_CFLAGS += -O4

DIRS += arch
DIRS += kernel
DIRS += hal

SOURCE_DIR := $(addprefix src/,$(DIRS))
BUILD_DIR := $(addprefix build/,$(DIRS))

#VPATH := src/boot:src/kernel:src/hal

C_SOURCE := $(foreach sdir,$(SOURCE_DIR),$(wildcard $(sdir)/*.c))
S_SOURCE := $(foreach sdir,$(SOURCE_DIR),$(wildcard $(sdir)/*.S))
H_SOURCE := $(foreach sdir,$(SOURCE_DIR),$(wildcard $(sdir)/*.h))

C_OBJ := $(patsubst src/%.c,build/%.c.o,$(C_SOURCE))
S_OBJ := $(patsubst src/%.S,build/%.S.o,$(S_SOURCE))

INCLUDE += -Isrc

CFLAGS += $(DEFINE)
CFLAGS += $(INCLUDE)

vpath %.c $(SOURCE_DIR)
vpath %.S $(SOURCE_DIR)


.PHONY: all doc checkdirs clean

all: checkdirs $(IMG) tags

doc:
	doxygen

tags:
	ctags -R src/

$(IMG): $(ELF)
	$(CROSS_COMPILE)objcopy $< -O binary $@
	
$(ELF): $(C_OBJ) $(S_OBJ)
	$(CROSS_COMPILE)gcc -Wl,-T,rpi.x $(CFLAGS) -o $@ $^


define make-goal-c
$1/%.c.o: %.c $(H_SOURCE) Makefile
	$(CROSS_COMPILE)gcc $(CFLAGS) -c -o $$@ $$<
endef

define make-goal-s
$1/%.S.o: %.S Makefile
	$(CROSS_COMPILE)gcc $(CFLAGS) -c -o $$@ $$<
endef

checkdirs: $(BUILD_DIR)

$(BUILD_DIR):
	@mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(ELF) $(IMG)

$(foreach bdir,$(BUILD_DIR),$(eval $(call make-goal-c,$(bdir))))

$(foreach bdir,$(BUILD_DIR),$(eval $(call make-goal-s,$(bdir))))

