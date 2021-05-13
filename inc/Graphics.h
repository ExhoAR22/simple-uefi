#ifndef _UEFI_GRAPHICS_H
#define _UEFI_GRAPHICS_H

#include "Utils.h"
#include "protocols/GraphicsOutputProtocol.h"

/**
 * @brief Finds and enters the best graphical mode
 * @param Mode if not NULL, will be set to the appropriate EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE structure
 * @return the status code returned by a failed operation or EFI_SUCCESS
 */
EFI_STATUS EnterOptimalGraphicMode(EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE** Mode);

#endif // _UEFI_GRAPHICS_H
