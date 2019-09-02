#include<stdio.h>
#include<conio.h>
#include<math.h>

int main()
{
    int a[100][100];
    int i,j,n;
    printf("Enter no. of vertices : ");
    scanf("%d",&n);
    printf("Input Graph in Matrix Form (9999 = infinity) : \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("Enter the value of a[%d][%d]:",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("\n\n");
    printf("Infinity = inft");
    printf("\n\n");
    printf("\nThe input weight matrix is:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(a[i][j]==9999)
                printf("inft\t");
            else
                printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    floyd(a,n);
    printf("\nThe final matrix:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(a[i][j]==9999)
                printf("inft\t");
            else
                printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
void floyd(int a[100][100],int n)
{
    int k,i,j,p,q;
    for(k=0; k<n; k++)
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(a[i][j]>(a[i][k]+a[k][j]))
                    a[i][j]=(a[i][k]+a[k][j]);
            }
        }
        printf("Pass: %d\n", k+1);
        for(p=0; p<n; p++)
        {
            for(q=0; q<n; q++)
            {
                if(a[p][q]==9999)
                    printf("inft\t");
                else
                    printf("%d\t",a[p][q]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
