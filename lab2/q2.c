#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char *c_keywords[] = {
    "auto", "break", "case", "char", "const", "continue",
    "default", "do", "double", "else", "enum", "extern",
    "float", "for", "goto", "if", "inline", "int", "long",
    "register", "restrict", "return", "short", "signed",
    "sizeof", "static", "struct", "switch", "typedef",
    "union", "unsigned", "void", "volatile", "while",
    "_Alignas", "_Alignof", "_Atomic", "_Bool", "_Complex",
    "_Generic", "_Imaginary", "_Noreturn", "_Static_assert",
    "_Thread_local"
};

int checkInKeywords(char *token){
    int size = sizeof(c_keywords)/sizeof(c_keywords[0]);
    for(int i=0; i<size; i++){
        if(strcmp(c_keywords[i], token)==0){
            return i;
        }
    }
    return -1;
}

char *capitalizeString(const char str[]) {
    size_t size = sizeof(str)/sizeof(str[0]);
    char *temp = malloc(sizeof(char)*size);
    strcpy(temp, str);
    for(int i=0; str[i]!='\0'; i++){
        temp[i] = toupper(str[i]);
    }
    return temp;
}

int main()
{
    int n = 0;
    FILE *f1;
    char filename[100], buffer[10000], c;
    printf("Enter filename: ");
    scanf("%s", filename);

    f1 = fopen(filename, "rb");
    while((c = fgetc(f1)) != EOF || n<10000) {
        buffer[n] = c;
        n++;
    }

    char *token = strtok(buffer, " \t\n+-!=<>()[]{}");
    while(token){
        int n = checkInKeywords(token);
        if (n>=0){
            printf("Keyword is: %s\n", capitalizeString(c_keywords[n]));
        }
        token = strtok(NULL, " \t\n+-!=<>()[]{}");
    }

    return 0;
}