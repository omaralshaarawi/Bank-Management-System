#include <stdio.h>
#include <string.h>
#include "structs.h"

void transfer() {
long long senderNum,receiverNum;
int sender , receiver ,exist =0;


//check if the sender exists or not
while(!exist){
  
  printf("Enter the sender account number: ");
  scanf("%lld",&senderNum);
    for(int i = 0 ; i < n ; i++){
      if(senderNum == customers[i].account_number) {
        exist = 1;
        sender = i;
        break;}
  }
  
  if(!exist)  printf("The sender doesn't exist try again\n"); 
          
      } 

exist = 0;

//check if the receiver exists or not
while(!exist){
  
  printf("Enter the receiver account number: ");
  scanf("%lld",&receiverNum);
    for(int i = 0 ; i < n ; i++){
      if(receiverNum == customers[i].account_number) {
        exist = 1;
        receiver = i;
        break;}
  }
  
  if(!exist)  printf("The receiver doesn't exist try again\n"); 

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

//add changes to files
FILE *fptr;
char acc_number[50];
//sender
sprintf(acc_number,"%lld.txt",customers[sender].account_number);
    fptr = fopen(acc_number, "a");
    if (!fptr) {
    printf("Error opening file for sender history.\n");
    return;
    }

    fprintf(fptr,"%lld sent %.2f to %lld\n",customers[sender].account_number,transferedAmount,customers[receiver].account_number);
    fclose(fptr);
    
//receiver
sprintf(acc_number,"%lld.txt",customers[receiver].account_number);
    fptr = fopen(acc_number, "a");
    if (!fptr) {
    printf("Error opening file for receiver history.\n");
    return;
    }

    fprintf(fptr,"%lld received %.2f from %lld\n",customers[receiver].account_number,transferedAmount,customers[sender].account_number);
    
    fclose(fptr);
    
}