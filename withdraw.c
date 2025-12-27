#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "daily_limit.c"
#include "bankaccount.c"
void withdraw() {
  long long enteredNum;
  int exist = 0;
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


  //tell the user to input the withdrawn value
  float withdrawAmount;
  while(1){
  printf("Enter the withdrawn amount 'max 10000 per transaction': ");
  scanf("%f",&withdrawAmount);
  if(withdrawAmount <= 10000 && withdrawAmount >= 1) break;
  else printf("Invalid amount! Please enter a value between 1 and 10000.\n");
  }
  //check the dailylimit withdraw
  int key = dailyLimit(index,withdrawAmount);
  if(!key) return;

  //final process
  if(key){
    if(customers[index].balance >= withdrawAmount){
      customers[index].balance -= withdrawAmount;
      printf("Withdrawal successfully! Your new balance: %.2f\n",customers[index].balance);
    }else{
      printf("Not enough balance your current balance : %.2f\n",customers[index].balance);
    }
  }



  //change the status in accont.txt file

  save(customers[index],0);


  //adding changes to file
  FILE *fptr;
char acc_number[50];

  sprintf(acc_number,"%lld.txt",customers[index].account_number);
    fptr = fopen(acc_number, "a");
    if (!fptr) {
    printf("Error opening file for withdraw history.\n");
    return;
    }

    fprintf(fptr,"%lld withdraw %.2f\n",customers[index].account_number,withdrawAmount);
    
    fclose(fptr);
    

}