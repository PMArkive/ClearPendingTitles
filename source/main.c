#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>

void finished() {
	printf("Done! Press B to exit.\n");
}

int main(int argc, char **argv) {
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);
    printf("ClearPendingTitles\nby Hikari\n\n");
    printf("Initializing AM...\n");
    amInit();
		printf("Press A to clear pending NAND title installs.\n");
		printf("Press X to clear pending SD title installs.\n");
		printf("Press Y to clear all pending title installs.\n");
		printf("Press B to exit.\n");
			while (aptMainLoop()) {
				hidScanInput();
				u32 kDown = hidKeysDown();

					if (kDown & KEY_A) {
						printf("Clearing pending NAND title installs...\n");
						AM_DeleteAllPendingTitles(MEDIATYPE_NAND);
						finished();
					}
					else if (kDown & KEY_X) {
						printf("Clearing pending SD title installs...\n");
						AM_DeleteAllPendingTitles(MEDIATYPE_SD);
						finished();
					}
				 	else if (kDown & KEY_Y) {
						printf("Clearing all pending title installs...\n");
						AM_DeleteAllPendingTitles(MEDIATYPE_NAND);
						AM_DeleteAllPendingTitles(MEDIATYPE_SD);
						finished();
					}
					else if (kDown & KEY_B) {
						printf("Exiting...\n");
						break;
					}
			}

		amExit();
		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();

    gfxExit();
    return 0;
}
