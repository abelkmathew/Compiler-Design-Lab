#include<stdio.h>
#include<string.h>
int n=0,t=0;
char p[10][10],nt[10];

int find(char a)
{
   int k;
   for(k=0;k<t;k++)
   {
       if(nt[k]==a)
       {
            return k;
       }
   }
   return -1;
}
void add(char First[], char c)
{
    int k;
    for(k=0;First[k]!='\0';k++)
    {
        if(First[k]==c)
        {
            return;
        }
    }
    First[k]=c;
    First[k+1]='\0';
}
void findfirst(char *First,char c)
{
    char result[10];
    result[0]='\0';
    First[0]='\0';
    int q,l,j;
    if(islower(c) ||c== '+' || c=='*' || c=='(' || c==')')
    {
          add(First,c);
          return;
    }
    else
    {
          for(q=0;q<n;q++)
          {
                if(p[q][0]==c)
                {
                      if(p[q][3]=='@')
                      {
                            add(First,'@');
                      }
                      else
                      {
                            l=3;
                            while(p[q][l]!='\0')
                            {
                                int flag=0;
                                findfirst(result,p[q][l]);
                                for(j=0;result[j]!='\0';j++)
                                {
                                    if(result[j]=='@'&&p[q][l+1]=='\0')
                                        add(First,result[j]);
                                    else
                                        if(result[j]!='@')
                                            add(First,result[j]);
                                }
                                for(j=0;result[j]!='\0';j++)
                                {
                                   if(result[j]=='@')
                                   {
                                        flag=1;
                                        break;
                                    }
                                }
                                if(flag==1)
                                    l++;
                                else
                                    break;
                             }
                       }
                }
        }
    }
   return;
}
void main()
{
    int i,j;
    char first[10];
    printf("Enter the no. of productions\n");
    scanf("%d",&n);
    printf("Enter the productions\n");
    for(i=0;i<n;i++)
    {
         scanf("%s",p[i]);
         if(find(p[i][0])==-1)
         {
              nt[t++]=p[i][0];
         }
    }
    for(i=0;i<t;i++)
    {
       strcpy(first,"");
       findfirst(first,nt[i]);
       printf("First(%c)= {",nt[i]);
       for(j=0;first[j]!='\0';j++)
       {
           printf(" %c ",first[j]);
       }
       printf("}\n");
    }
}

