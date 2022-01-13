#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main() 
{
    int i=0,j=-1,k,l,q,y,x,num=1;
    char a[30],n[5]={'E','A','T','B','F'},t[6]={'d','+','*','(',')','$'},p[10],p1[10],g,s[20]={};
    char pt[5][6][5]={"TA","0","0","TA","0","0","0","+TA","0","0","@","@","FB","0","0","FB","0","0","0","@","*FB","0","@","@","d","0","0","(E)","0","0"};
    void push(char ip)
    {
        j++;
        s[j]=ip;
    }
    push('$');
    push('E');
    printf("\nRepresentations:\nE' represented as A\nT' represented as B\nid represented d\n");
    printf("\nEnter the string to be parsed : ");
    gets(a);
    strcat(a,"$");
    printf("\nThe production rules used for this string (if any), are :\n\n");
    while(s[j])
    {
        if(s[j]=='d' || s[j]=='+' || s[j]=='*' || s[j]=='(' || s[j]==')' || s[j]=='$') 
        {
            if(a[i]==s[j] && a[i]=='$')
            {
                printf("\nThe string has been parsed.\n\n");
                break;
            }
            else if(a[i]==s[j])
            {
                i++;  j--;
            }
            else
            {
                printf("%s\t%s\tERROR\n",s,a);
                exit(0);
            }
        }
        else
        {
            x=-1,y=-1;
            for(q=0;q<5;q++)
            {
                if(n[q]==s[j])
                {
                    x=q; 
                    break;
                }
            }
            for(q=0;q<6;q++)
            {
                if(t[q]==a[i])
                {
                    y=q; break;
                }
            }
            if(y==-1)
            { 
                    printf("Invalid Input\n"); exit(0);
            }
            strcpy(p,"");
            strcpy(p,pt[x][y]);
            j--;
            if(strcmp(p,"0")!=0)
            {
                int len=strlen(p);
                if(strcmp(p,"@")!=0)
                {
                    for(k=len-1;k>=0;k--)
                        push(p[k]);          
                }
                g=n[x];
                printf(" %d) %c->%s\n",num,g,p);
                num=num+1;
            }
            else
            {
                printf("ERROR\n"); 
                exit(0);     
            }    
        }  
    }
}