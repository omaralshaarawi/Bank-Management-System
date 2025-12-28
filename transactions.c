#include <stdio.h>
#include "structs.h"
#include "bankaccount.h"
#include "prints.h"
#include "transactions.h"
#include <time.h>
#include <string.h>

void changeStatus() {
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
        else
        break;
    }
  //Understand what the user wants before processing
 
  int key = -1 ;
  while(key != 0 && key != 1){
  printf("To deactivate your account press 0\nTo activate your account press 1\n");
  scanf("%d",&key);
}
  
  //check the account current status to avoid conflects then change it
int confirmation=0;
  //activate
  if(key){
    
    if(strcmp(customers[index].active,"active") == 0) {
            printf("Your account is already activated!!\n");
            return;
          }
              else {
                printf("if you want confirm to activation your account press 1 else press 0\n");
                scanf("%d",&confirmation);
                if(confirmation==1) strcpy(customers[index].active,"active");
                else return;
              }
  
  }
  //deactivate
  if(!key){
    
    if(strcmp(customers[index].active,"inactive") == 0) {
            printf("Your account is already deactivated!!\n");
            return;
          }
              else{ 
                printf("if you want confirm to deactivation your account press 1 else press 0\n");
                scanf("%d",&confirmation);
                if(confirmation==1) strcpy(customers[index].active,"inactive");
                else return;
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
    printf("Error opening file for status history.\n");
    return;
    }

    fprintf(fptr,"%lld status changed into %s\n",customers[index].account_number,customers[index].active);
    
    fclose(fptr);
  
}

int dailyLimit(int i , float withdrawAmount) {
  
  time_t now = time(NULL);
  struct tm *today = localtime(&now);

  
  //reset daily withdraw
  if(customers[i].lastwithdraw.year != today->tm_year ||
     customers[i].lastwithdraw.day != today->tm_yday ) { 
    
    customers[i].lastwithdraw.withdrawn_amount = 0;
    customers[i].lastwithdraw.year = today->tm_year;
    customers[i].lastwithdraw.day = today->tm_yday;
  }

//check if the dailylimit
//exceeded
if( (customers[i].lastwithdraw.withdrawn_amount + withdrawAmount) > 50000 ){
  printf("You are only allowed to withdraw %.2f for today!\n",50000-(customers[i].lastwithdraw.withdrawn_amount));
  return 0 ;
  }
  //can be withdrawn 1-update the daily withdrawn amount 2-return 1 to confirm the operation
  customers[i].lastwithdraw.withdrawn_amount += withdrawAmount;
return 1 ;
}


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
        else break;
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
        else
        break;
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

void transfer() {
int sender , receiver ;


//check if the sender exists or not
printf("now checking sender\n");
while(1)
    {
        sender=search_account(1);
        if(sender==-1)
        {
            printf("Please enter a valid bank account number\n");
        }
        else
        break;
    }
//check if the receiver exists or not
printf("now checking receiver\n");
while(1)
    {
        receiver=search_account(1);
        if(receiver==-1)
        {
            printf("Please enter a valid bank account number\n");
        }
        else break;
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


  //change the status in accont.txt file

  save(customers[sender],0);
  save(customers[receiver],0);

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