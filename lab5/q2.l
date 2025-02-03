%{
 int words = 0;
 int characters = 0;
 int blanks = 0;
 int lines = 1;
%}

lines [\n\A]
blank [ \t]+
characters .
words [a-zA-Z]+

%%
{lines} {lines++;}
{blank} {blanks++;}
{characters} {characters++;}
{words} {words++; characters += strlen(yytext);}
%%

int yywrap() {return 1;}

int main(){
    FILE *fp;
    char filename[100];
    scanf("%s", filename);
    fp = fopen(filename, "r");
    yyin = fp;
    yylex();
    printf("Words: %d\nCharacters: %d\nBlanks: %d\nLines: %d\n", words, characters, blanks, lines);
}