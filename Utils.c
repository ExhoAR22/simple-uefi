#include "Utils.h"

EFI_HANDLE gImageHandle = NULL;
EFI_SYSTEM_TABLE* gST = NULL;
EFI_BOOT_SERVICES* gBS = NULL;
EFI_RUNTIME_SERVICES* gRS = NULL;

void SetImageParameters(EFI_HANDLE Handle, EFI_SYSTEM_TABLE* SystemTable) {
    gImageHandle = Handle;
    gST = SystemTable;
    gBS = gST->BootServices;
    gRS = gST->RuntimeServices;
}

EFI_HANDLE GetImageHandle() {
    return gImageHandle;
}

EFI_SYSTEM_TABLE* GetSystemTable() {
    return gST;
}

void memset(void* dst, int value, UINTN size) {
    // Assume the firmware's implementation is better, try to use it. if gBS is not set fall back to naive impl
    if (!gBS) {
        // Optimization: use size instead of another variable to count from the start
        for (UINTN i = 0; i < size; i++) {
            ((UINT8 *)(dst))[i] = value;
        }
    } else {
        gBS->SetMem(dst, size, value);
    }
}
