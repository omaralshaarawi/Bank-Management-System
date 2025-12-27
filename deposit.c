#include <stdio.h>
#include <string.h>
#include "structs.h"

void deposit(){

  long long enteredNum;
  int index;
  
  //check if the acount exists or not
while(1)
    {
        index=search_account(1);
        if(index==-1)
        {
            printf("Please enter a valid bank account number\n");
        }
    }

  //check acount status
  
  if(strcmp(customers[index].active,"inactive") == 0){
    printf("Your account is inactive you can't do any transaction process\n");
    return;
  }

  //tell the user to input the deposit value
  float depositAmount;
  while(1){
  printf("Enter the deposit amount 'max 10000 per transaction': ");
  scanf("%f",&depositAmount);
  if(depositAmount <= 10000 && depositAmount >= 1) break;
  else printf("Invalid amount! Please enter a value between 1 and 10000.\n");
  }

  // final process

  customers[index].balance += depositAmount;
  printf("Deposit successful! Your current balance: %.2f\n",customers[index].balance);


  //change the status in accont.txt file

  save(customers[index],0);

 //adding changes to file
  FILE *fptr;
char acc_number[50];

  sprintf(acc_number,"%lld.txt",customers[index].account_number);
    fptr = fopen(acc_number, "a");
    if (!fptr) {
    printf("Error opening file for deposite history.\n");
    return;
    }

    fprintf(fptr,"%lld deposit %.2f\n",customers[index].account_number,depositAmount);
    
    fclose(fptr);
  
}
