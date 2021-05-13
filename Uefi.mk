UEFILIB_C_SRCS := $(shell find uefi/src/ -name '*.c')

ifdef ARCH
UEFILIB_C_OBJS := $(patsubst uefi/src/%, obj/$(ARCH)/uefi/%.o, $(UEFILIB_C_SRCS))
else
UEFILIB_C_OBJS := $(patsubst uefi/src/%, obj/uefi/%.o, $(UEFILIB_C_SRCS))
endif

UEFILIB_OBJS := $(UEFILIB_C_OBJS)