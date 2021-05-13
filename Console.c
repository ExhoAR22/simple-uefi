#include "Console.h"

extern EFI_SYSTEM_TABLE* gST;

EFI_STATUS EnterOptimalTextMode() {
    UINTN Best = 0;
    UINTN BestMode = 0;
    UINTN Row = 0;
    UINTN Col = 0;
    EFI_STATUS Status = EFI_SUCCESS;
    
    if (!gST) {
        return EFI_NOT_READY;
    }

    for (UINTN CurrentMode = 0; CurrentMode < gST->ConOut->Mode->MaxMode; CurrentMode++) {
        EFI_CHECK_EXPECTATION_OR_SUCCESS(gST->ConOut->QueryMode(gST->ConOut, CurrentMode, &Col, &Row), EFI_UNSUPPORTED);
        if (Status == EFI_UNSUPPORTED) {
            continue;
        }

        if ((Row * Col) >= Best) {
            Best = Row * Col;
            BestMode = CurrentMode;
        }
    }

    EFI_CHECK(gST->ConOut->Reset(gST->ConOut, TRUE));
    EFI_CHECK(gST->ConOut->SetMode(gST->ConOut, BestMode));
    EFI_CHECK(gST->ConOut->SetAttribute(gST->ConOut, EFI_TEXT_ATTR(EFI_WHITE, EFI_BLACK)));

Cleanup:
    return Status;
}
