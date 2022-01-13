#include<stdio.h>
#include<string.h>
#include<ctype.h>
char input[100];
int i,error;
void E();
void T();
void Eprime();
void Tprime();
void F();
/*
@ is for epsilon
E->TE'
E'->+TE'/@
T->FT'
T'->*FT'/@
F->(E)/a/b/c
*/
void main()
{
    i=0;
    error=0;
    printf("Recursive Descent Parsing for the following grammar\n"); 
    printf("E->TE'\nE'->+TE'/@\nT->FT'\nT'->*FT'/@\nF->(E)/ID\n");
    printf("Enter an arithmetic expression:");
    scanf("%s",input);
    E();
    if(strlen(input)==i&&error==0)
      printf("\nAccepted..!!!\n");
    else 
      printf("\nRejected..!!!\n");
}

void E()
{
    T();
    Eprime();
}
void Eprime()
{
    if(input[i]=='+')
    {
      i++;
      T();
      Eprime();
    }
}
void T()
{
    F();
    Tprime();
}
void Tprime()
{
    if(input[i]=='*')
    {
      i++;
      F();
      Tprime();
    }
}
void F()
{
    if((input[i]=='a')||(input[i]=='b')||(input[i]=='c'))
        i++;
    else if(input[i]=='(')
    {
        i++;
        E();
        if(input[i]==')')
          i++;
        else 
          error=1;
    }        
    else 
      error=1;
}