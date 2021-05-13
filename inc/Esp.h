#ifndef _UEFI_ESP_H
#define _UEFI_ESP_H

#include "Common.h"
#include "protocols/FileProtocol.h"

/**
 * @brief Opens a file from the ESP
 * @param Path the absolute path to the file
 * @param OpenMode the mode to open the file with
 * @param Attributes the attributes of the opened file
 * @param Result set to the EFI_FILE_PROTOCOL object of the opened file
 * @return the status code returned by a failed operation or EFI_SUCCESS
 */
EFI_STATUS OpenEspFile(CHAR16* Path, UINT64 OpenMode, UINT64 Attributes, EFI_FILE_PROTOCOL** Result);

#endif // _UEFI_ESP_H
