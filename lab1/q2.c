#include <stdio.h>
#include <stdlib.h>

long displayFileSize(const char *inputfile)
{
    FILE *f1 = fopen(inputfile, "rb");

    fseek(f1, 0, SEEK_END);
    long size = ftell(f1);
    fclose(f1);
    return size;
}

void reverseFileContents(const char *inputFile, const char *outputFile)
{
    FILE *inFile = fopen(inputFile, "rb");
    FILE *outFile = fopen(outputFile, "wb");

    if (inFile == NULL)
    {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    if (outFile == NULL)
    {
        perror("Error opening output file");
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    // Find the size of the file
    fseek(inFile, 0, SEEK_END);
    long fileSize = ftell(inFile);

    // Reverse the file contents
    for (long i = fileSize - 1; i >= 0; i--)
    {
        fseek(inFile, i, SEEK_SET);
        int ch = fgetc(inFile);
        if (ch != EOF)
        {
            if (ch == '\n')
            {
                continue;
            }
            fputc(ch, outFile);
        }
    }

    fclose(inFile);
    fclose(outFile);

    printf("File contents reversed and written to '%s'.\n", outputFile);
}

int main()
{
    char filename[100], filename2[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    printf("Enter filename 2: ");
    scanf("%s", filename2);

    printf("Size of the file is: %ld\n", displayFileSize(filename));
    reverseFileContents(filename, filename2);
    return 0;
}