#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>

void gspWait(int vs){
	while(vs--)gspWaitForVBlank();
}

void clearpendingtitles() {
  AM_DeleteAllPendingTitles(MEDIATYPE_SD);
  AM_DeleteAllPendingTitles(MEDIATYPE_NAND);
}

int main(int argc, char **argv) {
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);
    printf("ClearPendingTitles\n\n");
    printf("by Hikari\n\n");
    printf("\n\n");
    printf("Initializing AM...\n\n");
    amInit();
    amAppInit();
    printf("Clearing pending titles...\n\n");
    clearpendingtitles();
    printf("Done! Exiting to Home Menu...\n\n");
    gspWait(50);
    amExit();
    gfxFlushBuffers();
    gfxSwapBuffers();
    gspWaitForVBlank();
    gfxExit();
    return 0;
}
