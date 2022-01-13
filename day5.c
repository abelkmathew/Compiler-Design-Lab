#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int op_table[6][6]={
    {1,1,1,1,1,1},
    {0,1,1,0,0,1},
    {0,1,1,0,0,1},
    {0,1,1,1,1,1},
    {0,1,1,1,1,1},
    {0,0,0,0,0,0}
};

int to_table(char a){
    int res;
    if(isalpha(a))
    {
        return 0;
    }
    else{
        switch (a)
        {
        case 'a':
                res = 0;
                break;
        case '+':
                res = 1;
                break;
        case '-':
                res = 2;
                break;
        case '*':
                res = 3;
                break;
        case '/':
                res = 4;
                break;
        case '$':
                res = 5;
                break;

        default:
                printf("\n Not accepted\n");
                exit(1);
                break;
        }
    }
    return res;
}

void main(){
    char stack1[100], stack2[100], input[100], out[100];
    int i=0 ,f=0,top1=0 , top2=-1, count=0, a=0;

    printf("Enter input:");
    scanf("%s",input);
    strcat(input,"$");
    stack1[0]='$';
    stack1[1]=0;
    printf("\nStack1\t\tInput\t\tStack2\t\tProductions");
    printf("\n %s\t\t%s\t\t%s ",stack1,i+input,stack2);
    while (1)
    {
        if(op_table[to_table(stack1[top1])][to_table(input[i])]){
            if(isalpha(stack1[top1]))
            {
                stack2[++top2]='E';
            }
            else
            {
                top2--;
                a=to_table(stack1[top1]);
                if(a==1)
                        printf("\t\tE->E+E");
                else if(a==2)
                        printf("\t\tE->E-E");
                else if(a==3)
                        printf("\t\tE->E*E");
                else if(a==4)
                        printf("\t\tE->E/E");
        //      printf("\n");
            }
            out[count++]=stack1[top1];
            top1--;
        }
        else{
                                                                                                             
            stack1[++top1]=input[i];
            i++;
        }
        if(input[i]=='$' && top1==0 && top2==0)
        {
            out[count]='\0';
            stack1[top1+1]='\0';
            stack2[top2+1]='\0';
            printf("\n %s\t\t%s\t\t%s ",stack1,i+input,stack2);
            printf("\n Accepted \n Postfix:%s\n",out);
            f=1;
            break;
        }
        stack1[top1+1]='\0';
        stack2[top2+1]='\0';
        printf("\n %s\t\t%s\t\t%s ",stack1,i+input,stack2);
        //if(a==0)
        //      printf("\n");


    }

}
