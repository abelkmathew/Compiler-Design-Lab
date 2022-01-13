%{
#include <stdio.h>
int z=0;
%}
%%
^[a-z A-Z _][a-z A-Z 0-9]* {printf("%s",yytext);}
\t ;
= ;
[0-9] ;
[0-9 A-z a-z] ;
%%
void main()
{

yyin=fopen("file2.txt","r");
printf("\nIdentifiers:\n");
yylex();
}
int yywrap()
{return 1;}

/* This is the correct one */
