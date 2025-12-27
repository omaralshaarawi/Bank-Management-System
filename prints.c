#include <stdio.h>
#include <string.h>
#include "structs.h"

void report()
{
    int flag;
    long long x=-1;
    while (1)
    {
        printf("1-continue\n2-return back\n");
        printf("Enter your choice: ");
        scanf("%d",&flag);
        if(flag==1)
            break;
        else if(flag==2)
            return;
        else 
            printf("Wrong choice try again\n");
    }
    while(1)
    {
        x=search_account(1);
        if(x==-1)
        {
            printf("Please enter a valid bank account number\n");
        }
        else break;
    }
    printf("-----The Report of %s's lastest Transcations-----\n",customers[x].name);
    x=customers[x].account_number;
    char acc_number[50];
    sprintf(acc_number,"%lld.txt",x);
    FILE *fptr1;
    fptr1 = fopen(acc_number,"r");
    if (fptr1==NULL) {
        perror("File open failed");
        return;
    }
    char line[1000][1000];
    int cnt=0;
    while (fgets(line[cnt], sizeof(line[cnt]), fptr1)) {
        cnt++;
    }
    for(int i=cnt-1;i>((cnt-1-5>-1)?cnt-1-5:-1);i--)
    {
        printf("%s",line[i]);
    }
    return;

}

void print1(int idx)
{
    printf("%lld %s %s %f %s %d-%d %s\n",customers[idx].account_number,customers[idx].name,customers[idx].email,customers[idx].balance,customers[idx].mobile_number,customers[idx].open.month,customers[idx].open.year,customers[idx].active);
}

void SortByDate()
{
    int sort[n+1];
    for(int i=0;i<=n;i++)
    {
        sort[i]=-1;
    }
    for(int j=0;j<=n;j++)
    {
        int idx=j;
        for(int i=0;i<=n;i++)
        {
            if(sort[i]==-1)
            {
                sort[i]=idx;
                break;
            }
            else if(customers[sort[i]].open.year>customers[idx].open.year||(customers[sort[i]].open.year==customers[idx].open.year&&customers[sort[i]].open.month>customers[idx].open.month))
            {
                int temp=sort[i];
                sort[i]=idx;
                idx=temp;
            }
        }
    }
    for(int i=0;i<=n;i++)print1(sort[i]);
}
void SortByName()
{
    int sort[n+1];
    for(int i=0;i<=n;i++)
    {
        sort[i]=-1;
    }
    for(int j=0;j<=n;j++)
    {
        int idx=j;
        for(int i=0;i<=n;i++)
        {
            if(sort[i]==-1)
            {
                sort[i]=idx;
                break;
            }
            else if(strcmp(customers[sort[i]].name,customers[idx].name)>0)
            {
                int temp=sort[i];
                sort[i]=idx;
                idx=temp;
            }
        }
    }
    for(int i=0;i<=n;i++)print1(sort[i]);
}
void SortByBalance()
{
    int sort[n+1];
    for(int i=0;i<=n;i++)
    {
        sort[i]=-1;
    }
    for(int j=0;j<=n;j++)
    {
        int idx=j;
        for(int i=0;i<=n;i++)
        {
            if(sort[i]==-1)
            {
                sort[i]=idx;
                break;
            }
            else if(customers[sort[i]].balance>customers[idx].balance)
            {
                int temp=sort[i];
                sort[i]=idx;
                idx=temp;
            }
        }
    }
    for(int i=0;i<=n;i++)print1(sort[i]);
}
void SortByStatus()
{
    for(int i=0;i<=n;i++)
    {
        if(strcmp(customers[i].active,"inactive")==0)
        {
            print1(i);
        }
    }
    for(int i=0;i<=n;i++)
    {
        if(strcmp(customers[i].active,"inactive")!=0)
        {
            print1(i);
        }
    }
}

void print()
{
    while(1)
    {
        printf("How would like to print it: \n1-Sorted by Name\n2-Sorted By Date\n3-Sort by Balance\n4-Sort by Status\n0-Return back to menu\n");
        int x;
        if(scanf("%d",&x))
        {
            if(x==1)SortByName();
            else if(x==2)SortByDate();
            else if(x==3)SortByBalance();
            else if(x==4)SortByStatus();
            else if(x==0)return;
            else{
                printf("Invalid choice please enter number again\n");
                continue;
            }
            break;

        }
        else printf("Invalid choice please enter number again\n");

    }
}