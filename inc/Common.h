#ifndef _UEFI_COMMON_H
#define _UEFI_COMMON_H

/**
 * Basic integer types
 */

typedef signed char INT8;
typedef unsigned char UINT8;
typedef signed short INT16;
typedef unsigned short UINT16;
typedef signed int INT32;
typedef unsigned int UINT32;
typedef signed long long INT64;
typedef unsigned long long UINT64;
typedef signed long long INTN;
typedef unsigned long long UINTN;
typedef char CHAR8;
typedef unsigned short CHAR16;
typedef unsigned char BOOLEAN;

static_assert(sizeof(INT8) == 1, "Invalid INT8 size");
static_assert(sizeof(UINT8) == 1, "Invalid UINT8 size");
static_assert(sizeof(INT16) == 2, "Invalid INT16 size");
static_assert(sizeof(UINT16) == 2, "Invalid UINT16 size");
static_assert(sizeof(INT32) == 4, "Invalid INT32 size");
static_assert(sizeof(UINT32) == 4, "Invalid UINT32 size");
static_assert(sizeof(INT64) == 8, "Invalid INT64 size");
static_assert(sizeof(UINT64) == 8, "Invalid UINT64 size");
static_assert(sizeof(INTN) == 8, "Invalid INTN size");
static_assert(sizeof(UINTN) == 8, "Invalid UINTN size");

/**
 * Constants
 */

#define TRUE (1)
#define FALSE (0)
#define NULL ((void*)0)

/**
 * UEFI types
 */

typedef void VOID;

typedef struct _EFI_GUID {
    UINT32 Data1;
    UINT16 Data2;
    UINT16 Data3;
    UINT8 Data4[8];
} EFI_GUID;

typedef enum _EFI_STATUS : UINTN {
    EFI_SUCCESS,

    EFI_ERROR_MASK = 0x8000000000000000,
    EFI_LOAD_ERROR = EFI_ERROR_MASK | 1,
    EFI_INVALID_PARAMETER = EFI_ERROR_MASK | 2,
    EFI_UNSUPPORTED = EFI_ERROR_MASK | 3,
    EFI_BAD_BUFFER_SIZE = EFI_ERROR_MASK | 4,
    EFI_BUFFER_TOO_SMALL = EFI_ERROR_MASK | 5,
    EFI_NOT_READY = EFI_ERROR_MASK | 6,
    EFI_DEVICE_ERROR = EFI_ERROR_MASK | 7,
    EFI_WRITE_PROTECTED = EFI_ERROR_MASK | 8,
    EFI_OUT_OF_RESOURCES = EFI_ERROR_MASK | 9,
} EFI_STATUS;

typedef VOID* EFI_HANDLE;
typedef VOID* EFI_EVENT;

#define EVT_TIMER 0x80000000
#define EVT_RUNTIME 0x40000000
#define EVT_NOTIFY_WAIT 0x00000100
#define EVT_NOTIFY_SIGNAL 0x00000200
#define EVT_SIGNAL_EXIT_BOOT_SERVICES 0x00000201
#define EVT_SIGNAL_VIRTUAL_ADDRESS_CHANGE 0x60000202

typedef UINT64 EFI_PHYSICAL_ADDRESS;
typedef UINT64 EFI_VIRTUAL_ADDRESS;

static_assert(sizeof(EFI_GUID) == 16, "Invalid EFI_GUID size");
static_assert(sizeof(EFI_STATUS) == sizeof(UINTN), "Invalid EFI_STATUS size");
static_assert(sizeof(EFI_PHYSICAL_ADDRESS) == sizeof(UINT64), "Invalid EFI_PHYSICAL_ADDRESS size");

typedef struct _EFI_TIME {
    UINT16 Year;
    UINT8 Month;
    UINT8 Day;
    UINT8 Hour;
    UINT8 Minute;
    UINT8 Second;
    UINT8 Pad1;
    UINT32 Nanosecond;
    INT16 TimeZone;
    UINT8 Daylight;
    UINT8 Pad2;
} EFI_TIME;

typedef struct _EFI_TIME_CAPABILITIES {
    UINT32 Resolution;
    UINT32 Accuracy;
    BOOLEAN SetsToZero;
} EFI_TIME_CAPABILITIES;

typedef UINTN EFI_TPL;

#define TPL_APPLICATION 4
#define TPL_CALLBACK 8
#define TPL_NOTIFY 16
#define TPL_HIGH_LEVEL 31

typedef enum _EFI_ALLOCATE_TYPE {
    AllocateAnyPages,
    AllocateMaxAddress,
    AllocateAddress,
    MaxAllocateType
} EFI_ALLOCATE_TYPE;

typedef enum _EFI_MEMORY_TYPE {
    EfiReservedMemoryType,
    EfiLoaderCode,
    EfiLoaderData,
    EfiBootServicesCode,
    EfiBootServicesData,
    EfiRuntimeServicesCode,
    EfiRuntimeServicesData,
    EfiConventionalMemory,
    EfiUnusableMemory,
    EfiACPIReclaimMemory,
    EfiACPIMemoryNVS,
    EfiMemoryMappedIO,
    EfiMemoryMappedIOPortSpace,
    EfiPalCode,
    EfiPersistentMemory,
    EfiMaxMemoryType
} EFI_MEMORY_TYPE;

#define EFI_MEMORY_UC 0x0000000000000001
#define EFI_MEMORY_WC 0x0000000000000002
#define EFI_MEMORY_WT 0x0000000000000004
#define EFI_MEMORY_WB 0x0000000000000008
#define EFI_MEMORY_UCE 0x0000000000000010
#define EFI_MEMORY_WP 0x0000000000001000
#define EFI_MEMORY_RP 0x0000000000002000
#define EFI_MEMORY_XP 0x0000000000004000
#define EFI_MEMORY_NV 0x0000000000008000
#define EFI_MEMORY_MORE_RELIABLE 0x0000000000010000
#define EFI_MEMORY_RO 0x0000000000020000
#define EFI_MEMORY_SP 0x0000000000040000
#define EFI_MEMORY_CPU_CRYPTO 0x0000000000080000
#define EFI_MEMORY_RUNTIME 0x8000000000000000

typedef struct _EFI_MEMORY_DESCRIPTOR {
    UINT32 Type;
    EFI_PHYSICAL_ADDRESS PhysicalStart;
    EFI_VIRTUAL_ADDRESS VirtualStart;
    UINT64 NumberOfPages;
    UINT64 Attribute;
} EFI_MEMORY_DESCRIPTOR;

#define EFI_MEMORY_DESCRIPTOR_VERSION 1

typedef enum _EFI_TIMER_DELAY {
    TimerCancel,
    TimerPeriodic,
    TimerRelative
} EFI_TIMER_DELAY;

typedef enum _EFI_INTERFACE_TYPE {
    EFI_NATIVE_INTERFACE
} EFI_INTERFACE_TYPE;

typedef enum _EFI_LOCATE_SEARCH_TYPE {
    AllHandles,
    ByRegisterNotify,
    ByProtocol
} EFI_LOCATE_SEARCH_TYPE;

typedef struct _EFI_OPEN_PROTOCOL_INFORMATION_ENTRY {
    EFI_HANDLE AgentHandle;
    EFI_HANDLE ControllerHandle;
    UINT32 Attributes;
    UINT32 OpenCount;
} EFI_OPEN_PROTOCOL_INFORMATION_ENTRY;

typedef enum _EFI_RESET_TYPE {
    EfiResetCold,
    EfiResetWarm,
    EfiResetShutdown,
    EfiResetPlatformSpecific
} EFI_RESET_TYPE;

typedef struct _EFI_CAPSULE_BLOCK_DESCRIPTOR {
    UINT64 Length;
    union {
        EFI_PHYSICAL_ADDRESS DataBlock;
        EFI_PHYSICAL_ADDRESS ContinuationPointer;
    };
} EFI_CAPSULE_BLOCK_DESCRIPTOR;

typedef struct _EFI_CAPSULE_HEADER {
    EFI_GUID CapsuleGuid;
    UINT32 HeaderSize;
    UINT32 Flags;
    UINT32 CapsuleImageSize;
} EFI_CAPSULE_HEADER;

typedef struct _EFI_CAPSULE_TABLE {
    UINT32 CapsuleArrayNumber;
    VOID* CapsulePtr[1];
} EFI_CAPSULE_TABLE;

#define EFI_PAGE_SIZE 4096
#define EFI_PAGE_MASK 0xfff
#define EFI_PAGE_SHIFT 12
#define EFI_SIZE_TO_PAGES(Size) (((Size) >> EFI_PAGE_SHIFT) + (((Size) & EFI_PAGE_MASK) ? 1 : 0))
#define EFI_PAGES_TO_SIZE(Pages) ((Pages) << EFI_PAGE_SHIFT)

#define EFI_CHECK_EXPECTATION(Result, Expectation) \
	if ((Status = Result) != Expectation) { \
		goto Cleanup; \
	}

#define EFI_CHECK_EXPECTATION_OR_SUCCESS(Result, Expectation) \
	if ((Status = Result) != Expectation && Status != EFI_SUCCESS) { \
		goto Cleanup; \
	}

#define EFI_CHECK(Result) EFI_CHECK_EXPECTATION(Result, EFI_SUCCESS)

#define EFI_FAIL(Result) \
    Status = Result; \
    goto Cleanup

#define EFI_SUCCEED() EFI_FAIL(EFI_SUCCESS)

#define CONST const

#endif // _UEFI_COMMON_H
