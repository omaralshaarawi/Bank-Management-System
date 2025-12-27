#include <stdio.h>
#include <string.h>
#include "structs.h"

void tranfer() {
long long senderNum,receiverNum;
int sender , receiver ,exist =0;

//get the sender 
printf("Enter the sender account number: ");
scanf("%lld",&senderNum);
//check if the sender exists or not

  for(int i = 0 ; i < n ; i++){
    if(senderNum == customers[i].account_number) {
      exist = 1;
      sender = i;
      break;}
  }
  
  if(!exist) {
    printf("The sender doesn't exist\n"); 
    return;
          }

//get the receiver
exist = 0;
printf("Enter the receiver account number: ");
scanf("%lld",&receiverNum);

//check if the receiver exists or not

  for(int i = 0 ; i < n ; i++){
    if(receiverNum == customers[i].account_number) {
      exist = 1;
      receiver = i;
      break;}
  }
  
  if(!exist) {
    printf("The receiver doesn't exist\n"); 
    return;
          }

//check the two accounts are diffrent
if(sender == receiver){
  printf("Cannot transfer to the same account.\n");
  return;
}

// check accounts status
if(strcmp(customers[sender].active,"inactive") == 0){
    printf("The sender account is inactive you can't do any transaction process\n");
    return;
  }
if(strcmp(customers[receiver].active,"inactive") == 0){
    printf("The receiver account is inactive you can't do any transaction process\n");
    return;
  }

//ask the user how much is the transferred value
 float transferedAmount ;
 while(1){
 printf("Enter the transferred amount: ");
 scanf("%f",&transferedAmount);
 if(transferedAmount>0 && transferedAmount <= customers[sender].balance)break;
 printf("Invalid amount! Enter a positive value not exceeding sender's balance.\n");
}

//final process
customers[sender].balance -= transferedAmount;
customers[receiver].balance += transferedAmount;
printf("Transfer successful!\n");
printf("The sender balance: %.2f\n",customers[sender].balance);
printf("The receiver balance: %.2f\n",customers[receiver].balance);
}