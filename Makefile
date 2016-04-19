CROSS_COMPILE=arm-none-eabi-

IMG = kernel.img
ELF = kernel.elf
MAP = kernel.map

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
LFLAGS += -Wl,-T,rpi.x,-nostartfiles,-Map,$(MAP),--cref,--print-memory-usage


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

C_SOURCE 	:= $(foreach sdir,$(SOURCE_DIR),$(wildcard $(sdir)/*.c))
CXX_SOURCE 	:= $(foreach sdir,$(SOURCE_DIR),$(wildcard $(sdir)/*.cpp))
S_SOURCE 	:= $(foreach sdir,$(SOURCE_DIR),$(wildcard $(sdir)/*.S))
H_SOURCE 	:= $(foreach sdir,$(SOURCE_DIR),$(wildcard $(sdir)/*.h))
HXX_SOURCE 	:= $(foreach sdir,$(SOURCE_DIR),$(wildcard $(sdir)/*.hpp))

C_OBJ 		:= $(patsubst src/%.c,build/%.c.o,$(C_SOURCE))
CXX_OBJ 	:= $(patsubst src/%.cpp,build/%.cpp.o,$(CXX_SOURCE))
S_OBJ 		:= $(patsubst src/%.S,build/%.S.o,$(S_SOURCE))

INCLUDE += -Isrc

CFLAGS += $(DEFINE)
CFLAGS += $(INCLUDE)

vpath %.c $(SOURCE_DIR)
vpath %.cpp $(SOURCE_DIR)
vpath %.S $(SOURCE_DIR)

CC 		:= $(CROSS_COMPILE)gcc
AS 		:= $(CROSS_COMPILE)gcc
CXX 	:= $(CROSS_COMPILE)g++
LD 		:= $(CROSS_COMPILE)g++
OBJCOPY	:= $(CROSS_COMPILE)objcopy

.PHONY: all doc checkdirs clean tags

all: checkdirs $(IMG) tags

doc:
	doxygen

tags:
	ctags -R src/

$(IMG): $(ELF)
	$(OBJCOPY) $< -O binary $@
	
$(ELF): $(C_OBJ) $(S_OBJ)
	$(CC) $(LFLAGS) $(CFLAGS) -o $@ $^

checkdirs: $(BUILD_DIR)

$(BUILD_DIR):
	@mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(ELF) $(IMG)


define make-goal-c
$1/%.c.o: %.c $(H_SOURCE) Makefile
	$(CC) $(CFLAGS) -c -o $$@ $$<
endef

define make-goal-cxx
$1/%.cpp.o: %.cpp $(HXX_SOURCE) Makefile
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c -o $$@ $$<
endef

define make-goal-s
$1/%.S.o: %.S Makefile
	$(AS) $(CFLAGS) -c -o $$@ $$<
endef

$(foreach bdir,$(BUILD_DIR),$(eval $(call make-goal-c,$(bdir))))

$(foreach bdir,$(BUILD_DIR),$(eval $(call make-goal-cxx,$(bdir))))

$(foreach bdir,$(BUILD_DIR),$(eval $(call make-goal-s,$(bdir))))

