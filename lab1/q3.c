#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    FILE *f1, *f2, *f3;
    char filename[100], filename1[100], filename2[100], c1, c2;

    printf("Enter file 1: ");
    scanf("%s", filename);
    printf("Enter file 2: ");
    scanf("%s", filename1);
    printf("Enter output file: ");
    scanf("%s", filename2);

    f1 = fopen(filename, "rb");
    f2 = fopen(filename1, "rb");
    f3 = fopen(filename2, "wb");

    if (f1 == NULL || f2 == NULL)
    {
        perror("Error while reading files");
        exit(EXIT_FAILURE);
    }

    bool turnf1 = true;
    c2 = fgetc(f2);
    c1 = fgetc(f1);
    while (c1 != EOF && c2 != EOF)
    {
        while (turnf1 && c1 != EOF)
        {
            if (c1 == '\n' && c2 != EOF)
            {
                turnf1 = false;
            }
            else
            {
                fputc(c1, f3);
            }
            c1 = fgetc(f1);
            if (c1 == EOF)
            {
                fputc('\n', f3);
                turnf1 = false;
            }
        }

        while (!turnf1 && c2 != EOF)
        {
            if (c2 == '\n' && c1 != EOF)
            {
                turnf1 = true;
            }
            else
            {
                fputc(c2, f3);
            }
            c2 = fgetc(f2);
            if (c2 == EOF)
            {
                fputc('\n', f3);
                turnf1 = true;
            }
        }
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);

    return 0;
}