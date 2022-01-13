%{
#include<stdio.h>
%}
%%
0(10|01)* {printf("Valid");}
.* printf("Not Valid");
%%
void main()
{
yylex();}
int yywrap(){
return 1;}

