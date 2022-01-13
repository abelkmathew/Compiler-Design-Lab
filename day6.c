#include<stdio.h>
#include<string.h>
void main()
{
    char a[50][50];
    char c[10],b;
    int i,j,k,l,m,n,p,y;
    int e,f,x,size;
    int q=0;
    printf("Enter the number of input lines:");
    scanf("%d",&i);
    for(k=0;k<i;k++)
    {
        printf("Enter the %d line:",k+1);
        scanf("%s",a[k]);
    }
    for(k=0;k<i;k++)
    {
        for(j=0;a[k][j]!='\0';j++)
        if(a[k][j]=='=')
        {
            size=0;
            for (x=0;x<j;x++)
            {
                c[x]=a[k][x];
                size++;
            }
            b=a[k][j+1];
            for(m=k+1;m<i;m++)
            {
                for(n=0;a[m][n]!='\0';n++)
                {
                    if(a[m][n]==c[0])
                    {
                        p=1;
                        for (x=n+1;x<n+size;x++)
                        {
                            if (a[m][x]!=c[p++])
                            {
                                break;
                            }
                        }
                        if(p==size)
                        {
                            if (a[m][n-1]=='+')
                            {
                                a[m][n]=b;
                                for (x=n+1;x<n+size;x++)
                                    a[m][x]=' ';
                            }
                            else if (a[m][n+size]=='+')
                            {
                                for (x=n;x<n+size;x++)
                                {
                                    if (x!=n+size-1)
                                        a[m][x]=' ';
                                    else
                                        a[m][x]=b;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(k=0;k<i;k++)
    {
        for(j=0;a[k][j]!='\0';j++)
        {
            if(a[k][j]=='+')
            {
                y=a[k][j-1];
                b=a[k][j+1];
                if(y>='a'&&y<='z'||y>='a'&&y<='z')
                {
                    q=1;
                }
                if(q==0)
                {
                    e=y-'0';
                    f=b-'0';
                    l=e+f;
                    y=l+'0';
                    a[k][j-1]=y;
                    a[k][j+1]=' ';
                    a[k][j]=' ';
                }

            }
        }
    }

    for(i=0;i<k;i++)
    {
        printf("%s \n",a[i]);
    }
}
