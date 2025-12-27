#include <stdio.h>
#include <string.h>
#include "structs.h"

void deposit(){

  long long enteredNum;
  int exist = 0;
  int founded;
  printf("Enter the bank account number: ");
  scanf("%lld",&enteredNum);
   
  //check if the acount exists or not

  for(int i = 0 ; i < n ; i++){
    if(enteredNum == customers[i].account_number) {
      exist = 1;
      founded = i;
      break;}
  }
  
  if(!exist) {
    printf("This account doesn't exist\n"); 
    return;
          }

  //check acount status
  
  if(strcmp(customers[founded].active,"inactive") == 0){
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

  customers[founded].balance += depositAmount;
  printf("Deposit successful! Your current balance: %.2f\n",customers[founded].balance);
}