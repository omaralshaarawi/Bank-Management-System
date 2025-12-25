#include <stdio.h>
#include <string.h>
#include "structs.h"

void report()
{
    long long x=-1;
    while(1)
    {
        printf("Please enter the bank account number : ");
        scanf("%lld",&x);
        int flag=1;
        for(int i=0;i<=n;++i){
            if(x==customers[i].account_number){
                flag=0;
                break;
            }
        }
        if(flag)
        {
            printf("please enter a valid bank account number\n");
        }
        else break;
    }
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
        printf("%s \n",line[i]);
    }
    return;

}

void SortByDate()
{

}
void SortByName()
{
    
}
void SortByBalance()
{
    
}
void SortByStatus()
{
    
}

void print()
{
    while(1)
    {
        printf("How would like to print it: \n-1Sorted by Name\n-2Sorted By Date\n-3Sort by Balance\n-4Sort by Status\n-0 Return back to menu\n");
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