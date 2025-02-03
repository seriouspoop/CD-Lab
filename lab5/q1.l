%{
    int constants = 0;
    int vowels = 0;
%}

%%
[AEIOUaeiou] {vowels++;}
[^AEIOUaeiou] {constants++;}
%%

int yywrap() {return 1;}

int main(){
    FILE *fp;
    char filename[100];
    scanf("%s", filename);
    fp = fopen(filename, "r");
    yyin = fp;
    yylex();
    printf("%d\n%d\n", constants, vowels);
}