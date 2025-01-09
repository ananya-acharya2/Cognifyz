#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 100

int main() {
    char sourceFile[MAX_FILENAME_LENGTH], destFile[MAX_FILENAME_LENGTH];
    FILE *source, *dest;
    int ch;
    printf("Enter the name of the source file: ");
    scanf("%99s", sourceFile);
    source = fopen(sourceFile, "r");
    if (source == NULL) {
        printf("Error: Cannot open source file %s\n", sourceFile);
        exit(EXIT_FAILURE);
    }
    printf("Enter the name of the destination file: ");
    scanf("%99s", destFile);
    dest = fopen(destFile, "w");
    if (dest == NULL) {
        printf("Error: Cannot open destination file %s\n", destFile);
        fclose(source);
        exit(EXIT_FAILURE);
    }
    while ((ch = fgetc(source)) != EOF) {
        if (fputc(ch, dest) == EOF) {
            printf("Error: Writing to file %s\n", destFile);
            fclose(source);
            fclose(dest);
            exit(EXIT_FAILURE);
        }
    }
    if (fclose(source) != 0) {
        printf("Error: Closing source file %s\n", sourceFile);
    }

    if (fclose(dest) != 0) {
        printf("Error: Closing destination file %s\n", destFile);
    }

    printf("File copied successfully from %s to %s\n", sourceFile, destFile);
    return 0;
}

