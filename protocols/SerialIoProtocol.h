#ifndef _UEFI_PROTOCOLS_SERIALIOPROTOCOL_H
#define _UEFI_PROTOCOLS_SERIALIOPROTOCOL_H

#include "../Common.h"

#define EFI_SERIAL_IO_PROTOCOL_GUID { 0xbb25cf6f, 0xf1d4, 0x11d2, { 0x9a, 0xc, 0x0, 0x90, 0x27, 0x3f, 0xc1, 0xfd } }

#define EFI_SERIAL_TERMINAL_DEVICE_TYPE_GUID \
    { 0x6ad9a60f, 0x5815, 0x4c7c, { 0x8a, 0x10, 0x50, 0x53, 0xd2, 0xbf, 0x7a, 0x1b } }

typedef struct _EFI_SERIAL_IO_PROTOCOL EFI_SERIAL_IO_PROTOCOL;

typedef enum _EFI_PARITY_TYPE {
    DefaultParity,
    NoParity,
    EvenParity,
    OddParity,
    MarkParity,
    SpaceParity
} EFI_PARITY_TYPE;

typedef enum _EFI_STOP_BITS_TYPE {
    DefaultStopBits,
    OneStopBit,
    OneFiveStopBits,
    TwoStopBits
} EFI_STOP_BITS_TYPE;

#define EFI_SERIAL_CLEAR_TO_SEND 0x10
#define EFI_SERIAL_DATA_SET_READY 0x20
#define EFI_SERIAL_RING_INDICATE 0x40
#define EFI_SERIAL_CARRIER_DETECT 0x80
#define EFI_SERIAL_INPUT_BUFFER_EMPTY 0x100
#define EFI_SERIAL_OUTPUT_BUFFER_EMPTY 0x200
#define EFI_SERIAL_REQUEST_TO_SEND 0x2
#define EFI_SERIAL_DATA_TERMINAL_READY 0x1
#define EFI_SERIAL_HARDWARE_LOOPBACK_ENABLE 0x1000
#define EFI_SERIAL_SOFTWARE_LOOPBACK_ENABLE 0x2000
#define EFI_SERIAL_HARDWARE_FLOW_CONTROL_ENABLE 0x4000

typedef EFI_STATUS (*EFI_SERIAL_RESET)(EFI_SERIAL_IO_PROTOCOL* This);

typedef EFI_STATUS (*EFI_SERIAL_SET_ATTRIBUTES)(EFI_SERIAL_IO_PROTOCOL* This, UINT64 BaudRate, UINT32 ReceiveFifoDepth, 
        UINT32 Timeout, EFI_PARITY_TYPE Parity, UINT8 DataBits, EFI_STOP_BITS_TYPE StopBits);

typedef EFI_STATUS (*EFI_SERIAL_SET_CONTROL_BITS)(EFI_SERIAL_IO_PROTOCOL* This, UINT32 Control);

typedef EFI_STATUS (*EFI_SERIAL_GET_CONTROL_BITS)(EFI_SERIAL_IO_PROTOCOL* This, UINT32* Control);

typedef EFI_STATUS (*EFI_SERIAL_WRITE)(EFI_SERIAL_IO_PROTOCOL* This, UINTN* BufferSize, VOID* Buffer);

typedef EFI_STATUS (*EFI_SERIAL_READ)(EFI_SERIAL_IO_PROTOCOL* This, UINTN* BufferSize, VOID* Buffer);

typedef struct _EFI_SERIAL_IO_MODE {
    UINT32 ControlMask;
    UINT32 Timeout;
    UINT64 BaudRate;
    UINT32 ReceiveFifoDepth;
    UINT32 DataBits;
    UINT32 Parity;
    UINT32 StopBits;
} EFI_SERIAL_IO_MODE;

#define EFI_SERIAL_IO_PROTOCOL_REVISION 0x10000
#define EFI_SERIAL_IO_PROTOCOL_REVISION1_1 0x10001

struct _EFI_SERIAL_IO_PROTOCOL {
    UINT32 Revision;
    EFI_SERIAL_RESET Reset;
    EFI_SERIAL_SET_ATTRIBUTES SetAttributes;
    EFI_SERIAL_SET_CONTROL_BITS SetControl;
    EFI_SERIAL_GET_CONTROL_BITS GetControl;
    EFI_SERIAL_WRITE Write;
    EFI_SERIAL_READ Read;
    EFI_SERIAL_IO_MODE* Mode;
    CONST EFI_GUID* DeviceTypeGuid; // Revision 1.1
};

#endif // _UEFI_PROTOCOLS_SERIALIOPROTOCOL_H
