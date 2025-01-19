#include<stdio.h>

struct student{
    int reg;
    char name[100];
    double cgpa;
};

int main()
{
    int i,j,k,n;

    printf("How many Students' You Want to Enter:");

    scanf("%d",&n);

    struct student x[n],y;

    for(i=0;i<n;i++)
    {
        printf("Enter The Reg No.:");
        scanf("%d",&x[i].reg);

        printf("Enter The Name:");
        scanf("%s", x[i].name);

        printf("Enter The CGPA:");
        scanf("%lf",&x[i].cgpa);

        printf("\n");
    }

    for(j=0;j<n;j++)
    {
        for(k=j+1;k<n;k++)
        {
            if(x[j].cgpa<x[k].cgpa)
            {
                y=x[k];
                x[k]=x[j];
                x[j]=y;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        printf("Student %d:\nReg no:%d Name:%s CGPA:%0.2lf\n\n" ,(i+1),x[i].reg, x[i].name, x[i].cgpa);
    }

    return 0;
}
