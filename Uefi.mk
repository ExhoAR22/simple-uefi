UEFILIB_C_SRCS := $(shell find uefi/ -name '*.c')

ifdef ARCH
UEFILIB_C_OBJS := $(patsubst uefi/%, obj/$(ARCH)/uefi/%.o, $(UEFILIB_C_SRCS))
else
UEFILIB_C_OBJS := $(patsubst uefi/%, obj/uefi/%.o, $(UEFILIB_C_SRCS))
endif

UEFILIB_OBJS := $(UEFILIB_C_OBJS)