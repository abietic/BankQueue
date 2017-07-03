#ifndef savecomment_H_INCLUDED
#define savecomment_H_INCLUDED
# include<stdio.h>
# include<stdlib.h>
# include"itoa.h"
#define TotalWindows 16
struct star
{
    int level;
    int people;
};
void inited()//初始化评级记录文件
{
    char a[10];
    FILE *fp;
    int i,j;
    struct star b[6];
    for(i=1;i<=5;i++)
    {
        b[i].level=i;
        b[i].people=0;
    }
    for(i=1;i<=TotalWindows;i++)
    {
        itoa(i,a);
        if((fp=fopen(a,"w"))==NULL)
        {
          printf("Cannot open file.\n");
        }

        for(j=1;j<=5;j++)
        {
            fprintf(fp,"%d %d\n",b[j].level,b[j].people);
        }
        fclose(fp);
    }

}
void modify(int m,int n)//
{
    FILE *fp;
    int i;
    char a[10];
    struct star s[6];
    itoa(m,a);
    if((fp=fopen(a,"a+"))==NULL)
        {
            printf("Cannot open file.\n");
            exit(0);
        }
    for(i=1;i<=5;i++)
        {
            fscanf(fp,"%d %d",&s[i].level,&s[i].people);
            if(n==i)
                s[i].people++;
        }
    fclose(fp);
    if((fp=fopen(a,"w"))==NULL)
        {
            printf("Cannot open file.\n");
            exit(0);
        }
        for(i=1;i<=5;i++)
        {
            fprintf(fp,"%d %d\n",s[i].level,s[i].people);
        }
        fclose(fp);
}


#endif
