#include "../inc/Graphics.h"

extern EFI_BOOT_SERVICES* gBS;

EFI_STATUS EnterOptimalGraphicMode(EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE** Mode) {
    EFI_GUID GopGuid = EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID;
    EFI_GRAPHICS_OUTPUT_PROTOCOL* Gop = NULL;
    EFI_STATUS Status = EFI_SUCCESS;

    EFI_CHECK(gBS->LocateProtocol(&GopGuid, NULL, (VOID**)&Gop));
    EFI_GRAPHICS_OUTPUT_MODE_INFORMATION* Info = NULL;

    UINTN SizeOfInfo = 0;
    UINT32 BestResolution = 0;
    UINT32 BestMode = 0;
    for (UINT32 i = 0; i < Gop->Mode->MaxMode; i++) {
        EFI_CHECK(Gop->QueryMode(Gop, i, &SizeOfInfo, &Info));
        if (BestResolution < (Info->HorizontalResolution * Info->VerticalResolution) &&
            (Info->PixelFormat == PixelRedGreenBlueReserved8BitPerColor ||
             Info->PixelFormat == PixelBlueGreenRedReserved8BitPerColor)) {
            BestResolution = Info->HorizontalResolution * Info->VerticalResolution;
            BestMode = i;
        }
    }

    EFI_CHECK(Gop->SetMode(Gop, BestMode));
    if (Mode) {
        *Mode = Gop->Mode;
    }

Cleanup:
    return Status;
}
