#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "daily_limit.c"
void withdraw() {
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


  //tell the user to input the withdrawn value
  float withdrawAmount;
  while(1){
  printf("Enter the withdrawn amount 'max 10000 per transaction': ");
  scanf("%f",&withdrawAmount);
  if(withdrawAmount <= 10000 && withdrawAmount >= 1) break;
  else printf("Invalid amount! Please enter a value between 1 and 10000.\n");
  }
  //check the dailylimit withdraw
  int key = dailyLimit(founded,withdrawAmount);

  //final process
  if(key){
    if(customers[founded].balance >= withdrawAmount){
      customers[founded].balance -= withdrawAmount;
      printf("Withdrawal successfully! Your new balance: %.2f\n",customers[founded].balance);
    }else{
      printf("Not enough balance your current balance: %.2f\n",customers[founded].balance);
    }


  }
}