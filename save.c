#include <stdio.h>
#include <string.h>
#include "structs.h"


void save(customer e,int new)
{
    if(new==0)
    {
        //delete(e);
    }
    else
    n++;
    if(n>=10007&&new==1)
    {
        n--;
        printf("THE NUMBER OF ACCOUNTS LIMIT HAS BEEN REACHED THE ACCOUNT CANNOT BE SAVED");
        return;
    }
    customers[n].account_number=e.account_number;
    customers[n].balance=e.balance;
    strcpy(customers[n].name,e.name);
    strcpy(customers[n].email,e.email);
    customers[n].open.year=e.open.year;
    customers[n].open.month=e.open.month;
    strcpy(customers[n].active,e.active);
    strcpy(customers[n].mobile_number,e.mobile_number);
    if(new==1)
    printf("The account has been saved successfully");   
    FILE *fptr;
    char acc_number[50];
    sprintf(acc_number,"%lld.txt",e.account_number);
    fptr = fopen(acc_number, "w");
    fclose(fptr);
    FILE *fptr1;
    fptr1 = fopen("accounts.txt","a");
    fprintf(fptr1, "\n%lld, %s,%s,%f,%s,%d-%d,%s",e.account_number,e.name,e.email,e.balance,e.mobile_number,e.open.month,e.open.year,e.active);
    fclose(fptr1);
}