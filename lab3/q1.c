#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef enum {
    TKN_SPL_SYM,
    TKN_IDENTIFIER,
    TOKEN_OPERATOR,
    TOKEN_CONSTANT
} TOKEN_TYPE;

typedef struct{
    char *lexeme;
    // int index; Symbol table not used in this experiment
    unsigned int row, col;
    TOKEN_TYPE type;
} Token;

static int row = 1, col = 0;
const char specialSymbols[] = {':', '?', ';', '[', ']', '{', '}', ',', '(', ')', '\0'};
const char arithmeticSymbol[] = {'*', '+', '-', '/', '%', '\0'};

bool charPresentIn(char cin, const char *arr){
    size_t len = strlen(arr);
    for(int i=0; i<len;i++){
        if(arr[i]==cin){
            return true;
        }
    }
    return false;
}


Token getNextToken(FILE *fin){
    char c;
    Token tkn = {.row=-1};
    while((c = fgetc(fin)) != EOF && ++col){
        if(c == '\n') {
            col=0;
            row++;
            continue;
        }
        if(charPresentIn(c, specialSymbols)) {
            switch (c)
            {
            case ':':
                tkn = (Token){.lexeme="COLON", .row=row, .col=col, .type=TKN_SPL_SYM};
                break;
            case '?':
                tkn = (Token){.lexeme="QUESTION_MARK", .row=row, .col=col, .type=TKN_SPL_SYM};
                break;
            case ';':
                tkn = (Token){.lexeme="SEMI_COLON", .row=row, .col=col, .type=TKN_SPL_SYM};
                break;
            case '[':
                tkn = (Token){.lexeme="OPEN_BRACKET", .row=row, .col=col, .type=TKN_SPL_SYM};
                break;
            case ']':
                tkn = (Token){.lexeme="CLOSE_BRACKET", .row=row, .col=col, .type=TKN_SPL_SYM};
                break;
            case '{':
                tkn = (Token){.lexeme="OPEN_CURLY_BRACES", .row=row, .col=col, .type=TKN_SPL_SYM};
                break;
            case '}':
                tkn = (Token){.lexeme="CLOSE_CURLY_BRACES", .row=row, .col=col, .type=TKN_SPL_SYM};
                break;
            case ',':
                tkn = (Token){.lexeme="COMMA", .row=row, .col=col, .type=TKN_SPL_SYM};
                break;
            case '(':
                tkn = (Token){.lexeme="OPEN_PARA", .row=row, .col=col, .type=TKN_SPL_SYM};
                break;
            case ')':
                tkn = (Token){.lexeme="CLOSE_PARA", .row=row, .col=col, .type=TKN_SPL_SYM};
                break;
            default:
                break;
            }
            
            return tkn;
        }else if(charPresentIn(c, arithmeticSymbol)){
            switch (c)
            {
            case '*':
                tkn = (Token){.lexeme="MUL_OP", .row=row, .col=col, .type=TOKEN_OPERATOR};
                break;
            case '+':
                tkn = (Token){.lexeme="ADD_OP", .row=row, .col=col, .type=TOKEN_OPERATOR};
                break;
            case '-':
                tkn = (Token){.lexeme="SUB_OP", .row=row, .col=col, .type=TOKEN_OPERATOR};
                break;
            case '/':
                tkn = (Token){.lexeme="DIV_OP", .row=row, .col=col, .type=TOKEN_OPERATOR};
                break;
            case '%':
                tkn = (Token){.lexeme="RMD_OP", .row=row, .col=col, .type=TOKEN_OPERATOR};
                break;
            default:
                break;
            }
            
            return tkn;
        }else {
            tkn = (Token){.lexeme="CHAR", .row=row, .col=col, .type=TOKEN_CONSTANT};
            return tkn;
        }
    }
    return tkn;
}

int main(){
    FILE *f1;
    char filename[100];

    printf("Enter filename to read: ");
    scanf("%s", filename);

    f1 = fopen(filename, "rb");
    Token tkn;
    while ((tkn = getNextToken(f1)).row != -1) {
        printf("Lexeme: %s, Row: %u, Column: %u\n", tkn.lexeme, tkn.row, tkn.col);
    }
    fclose(f1);
    return 0;
}