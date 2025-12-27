#include <stdio.h>
#include <string.h>
#include "structs.h"
void save(customer e,int new)
{
    if(new==1)
    n++;
    if(n>=10007&&new==1)
    {
        n--;
        printf("THE NUMBER OF ACCOUNTS LIMIT HAS BEEN REACHED THE ACCOUNT CANNOT BE SAVED");
        return;
    }
    if(new==1){
        customers[n].account_number=e.account_number;
        customers[n].balance=e.balance;
        strcpy(customers[n].name,e.name);
        strcpy(customers[n].email,e.email);
        customers[n].open.year=e.open.year;
        customers[n].open.month=e.open.month;
        strcpy(customers[n].active,e.active);
        strcpy(customers[n].mobile_number,e.mobile_number);
    }
    if(new==1)
    printf("The account has been saved successfully\n");  
    FILE *fptr;
    char acc_number[50];
    sprintf(acc_number,"%lld.txt",e.account_number);
    fptr = fopen(acc_number, "a+");
    if(fptr==NULL)
    {
        perror("The account number file wasn't made");
    }
    fclose(fptr);
    FILE *file1;
     file1=fopen("account.txt","w");
        for(int i=0;i<=n;++i){
            fprintf(file1,"%lld,%s,%s,%f,%s,%d-%d,%s\n",customers[i].account_number,customers[i].name,customers[i].email,customers[i].balance,customers[i].mobile_number,customers[i].open.month,customers[i].open.year);
        }

}