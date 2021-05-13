#ifndef _UEFI_CONSOLE_H
#define _UEFI_CONSOLE_H

#include "Utils.h"

/**
 * @brief Enters the highest resolution text mode
 * @return the status code returned by a failed operation or EFI_SUCCESS
 */
EFI_STATUS EnterOptimalTextMode();

#endif // _UEFI_CONSOLE_H
