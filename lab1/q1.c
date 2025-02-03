#include <stdlib.h>
#include <stdio.h>

int main()
{
    FILE *f1;
    char filename[100], c;

    printf("Enter filename to read: ");
    scanf(" %s", filename);

    f1 = fopen(filename, "r");

    if (f1 == NULL)
    {
        printf("Cannot open file: %s\n", filename);
        exit(0);
    }

    int char_count = 0, line_count = 0;

    c = fgetc(f1);
    while (c != EOF)
    {
        char_count++;
        if (c == '\n')
        {
            line_count++;
        }
        c = fgetc(f1);
    }
    printf("Total character: %d, Total Lines: %d\n", char_count, line_count);
}