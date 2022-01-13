#include<stdio.h>
#include<string.h>
void calc(int posn,char op,char exp[20])
{ 
	int j,left,right;
	int static tmpch=90;
	left=exp[posn-1];
	right=exp[posn+1];
	printf("%c = %c %c %c", tmpch,left,op,right);
	exp[posn-1]=tmpch;
	tmpch--;
	for(j=posn;j<strlen(exp);j++)
		exp[j]=exp[j+2];
	exp[j+1]='\0';
	printf("\t\t\t%s\n",exp);
}
void main()
{
	int i,k=0,j,l=0,posn;
	char pos[10][10],exp[20],tmpch=90,left,right;
	printf("Enter expression: ");
	scanf("%s",exp);
	for(i=0;i<strlen(exp);i++)
	{	if(exp[i]=='/')
			calc(i,'/',exp);
	}
	for(i=0;i<strlen(exp);i++)
	{	if(exp[i]=='*')
		calc(i,'*',exp);
	}
	for(i=0;i<strlen(exp);i++)
	{	if(exp[i]=='+')
		calc(i,'+',exp);
	}
	for(i=0;i<strlen(exp);i++)
	{	
		if(exp[i]=='-')
		calc(i,'-',exp);
	}
}

