#include "../inc/Esp.h"
#include "../inc/Utils.h"

#include "../inc/protocols/SimpleFilesystemProtocol.h"

extern EFI_BOOT_SERVICES* gBS;

EFI_STATUS OpenEspFile(CHAR16* Path, UINT64 OpenMode, UINT64 Attributes, EFI_FILE_PROTOCOL** Result) {
    EFI_GUID SimpleFsGuid = EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID;
    EFI_SIMPLE_FILE_SYSTEM_PROTOCOL* SimpleFs = NULL;
    EFI_STATUS Status = EFI_SUCCESS;
    EFI_FILE_PROTOCOL* VolumeHandle = NULL;

    EFI_CHECK(gBS->LocateProtocol(&SimpleFsGuid, NULL, (VOID**)&SimpleFs));
    EFI_CHECK(SimpleFs->OpenVolume(SimpleFs, &VolumeHandle));
    EFI_CHECK(VolumeHandle->Open(VolumeHandle, Result, Path, OpenMode, Attributes));

Cleanup:
    if (VolumeHandle) {
        VolumeHandle->Close(VolumeHandle);
    }

    return Status;
}
