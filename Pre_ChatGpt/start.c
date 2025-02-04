#include <stdio.h>
#include <stdlib.h>

int main() {
    // Compile your C program
    system("gcc -o test test.c");

    // Create a batch script to run the compiled program
    FILE *batchScript = fopen("run_program.bat", "w");
    if (batchScript != NULL) {
        fprintf(batchScript, "@echo off\n");
        fprintf(batchScript, "test.exe\n");
        fprintf(batchScript, "pause\n");  // Pause before exiting
        fclose(batchScript);

        // Open a new command prompt window and execute the batch script
        system("start cmd /c run_program.bat");

        // Optionally, you can remove the batch script after it's executed
        remove("run_program.bat");
    }

    return 0;
}

