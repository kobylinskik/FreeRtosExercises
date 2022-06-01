TARGET = main.elf

CMSIS_DIR = ../CMSIS
CORE_SUPPORT_DIR = $(CMSIS_DIR)/CM3/CoreSupport
DEVICE_SUPPORT_DIR = $(CMSIS_DIR)/CM3/DeviceSupport/ST/STM32F10x
INC_DIR = ./inc
SRC_DIR = ./src
PARENT_INC_DIR = ../inc
PARENT_SRC_DIR = ../src
FREERTOS_SRC_DIR = ../FreeRTOS/Source
FREERTOS_INC_DIR = $(FREERTOS_SRC_DIR)/include
FREERTOS_PORT_DIR = $(FREERTOS_SRC_DIR)/portable
FREERTOS_MEM_DIR = $(FREERTOS_PORT_DIR)/MemMang
FREERTOS_ARM_CM3_DIR = $(FREERTOS_PORT_DIR)/GCC/ARM_CM3
FREERTOS_BUILD_DIR = ../FreeRTOS_Build
STDPERIPH_DIR = ../StdPeriph_Driver
STDPERIPH_SRC_DIR = $(STDPERIPH_DIR)/src
STDPERIPH_INC_DIR = $(STDPERIPH_DIR)/inc

CC = arm-none-eabi-gcc

CCFLAGS += -mcpu=cortex-m3
CCFLAGS += -mthumb
CCFLAGS += -I.
CCFLAGS += -I$(CORE_SUPPORT_DIR)
CCFLAGS += -I$(DEVICE_SUPPORT_DIR)
CCFLAGS += -I$(INC_DIR)
CCFLAGS += -I$(FREERTOS_INC_DIR)
CCFLAGS += -I$(FREERTOS_MEM_DIR)
CCFLAGS += -I$(FREERTOS_ARM_CM3_DIR)
CCFLAGS += -I$(PARENT_INC_DIR)
#CCFLAGS += -I$(STDPERIPH_INC_DIR)
CCFLAGS += -I..
CCFLAGS += --specs=nosys.specs
CCFLAGS += -nostdlib
CCFLAGS += -g
CCFLAGS += -c

CC_INPUT += $(wildcard $(SRC_DIR)/*.c)
CC_INPUT += $(wildcard $(PARENT_SRC_DIR)/*.c)
CC_INPUT += $(DEVICE_SUPPORT_DIR)/startup/gcc_ride7/startup_stm32f10x_ld.s
CC_INPUT += $(DEVICE_SUPPORT_DIR)/system_stm32f10x.c
CC_INPUT += $(CORE_SUPPORT_DIR)/core_cm3.c
#CC_INPUT += $(wildcard $(STDPERIPH_SRC_DIR)/*.c)

LD = arm-none-eabi-ld

LINKER_SCRIPT = ../LinkerScript.ld

LD_INPUT = $(wildcard ./*.o)
LD_INPUT += $(wildcard $(FREERTOS_BUILD_DIR)/*.o)

LD_OUTPUT = -o $(TARGET)

LDFLAGS = -T$(LINKER_SCRIPT)
LDFLAGS += -mcpu=cortex-m3
LDFLAGS += -mthumb
LDFLAGS += --specs=nosys.specs
LDFLAGS += -nostdlib
LDFLAGS += -g

main:
	$(CC) $(CCFLAGS) $(CC_INPUT)
	$(CC) $(LDFLAGS) $(LD_INPUT) $(LD_OUTPUT)