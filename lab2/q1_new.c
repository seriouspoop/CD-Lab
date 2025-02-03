

int main()
{
    FILE *f1, *f2;

    char inputfile[100], outputfile[100], c;

    printf("Enter input      #   filename: ");
    scanf("%s", inputfile);
    printf("Enter output filename: ");
    scanf("%s", outputfile);

    f1 = fopen(inputfile, "rb");
    f2 = fopen(outputfile, "wb");
    while ((c = fgetc(f1)) != EOF)
    {

        if (c == '\'')
        {
            fputc('\'', f2);
            while ((c = fgetc(f1)) != '\'')
            {
                fputc(c, f2);
            }
            fputc('\'', f2);
        }
        else if (c == '"')
        {
            fputc('"', f2);
            while ((c = fgetc(f1)) != '"')
            {
                fputc(c, f2);
            }
            fputc('"', f2);
        }

        else if (c == '#')
        {
            while ((c = fgetc(f1)) != '\n')
                ;
            fseek(f1, -1, SEEK_CUR);
        }

        else if (c == '/')
        {
            c = fgetc(f1);
            if (c == '/')
                while ((c = fgetc(f1)) != '\n')
                    ;
            else
                fputc('/', f2);
            fseek(f1, -1, SEEK_CUR);
        }

        else if (c == ' ')
        {
            c = fgetc(f1);
            if (c == ' ')
                while ((c = fgetc(f1)) == ' ')
                    ;
            fputc(' ', f2);
            fseek(f1, -1, SEEK_CUR);
        }
        else
        {
            fputc(c, f2);
        }
    }
    return 0;
}