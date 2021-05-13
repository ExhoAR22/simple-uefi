#ifndef _UEFI_UTILS_H
#define _UEFI_UTILS_H

#include "Common.h"
#include "Tables.h"

#define COUNT_OF(x) (sizeof(x) / sizeof(x[0]))

/**
 * @brief Stores the given image handle and system table for use by other library and user functions
 */
void SetImageParameters(EFI_HANDLE Handle, EFI_SYSTEM_TABLE* SystemTable);

/**
 * @brief Returns the stored image handle pointer
 */
EFI_HANDLE GetImageHandle();

/**
 * @brief Returns the stored system table pointer
 */
EFI_SYSTEM_TABLE* GetSystemTable();

/**
 * @brief Wrapper for gBS->SetMem
 */
void memset(void* dest, int value, UINTN size);

#endif // _UEFI_UTILS_H