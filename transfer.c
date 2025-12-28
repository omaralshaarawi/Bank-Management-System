#include <stdio.h>
#include <string.h>
#include "structs.h"
void transfer() {
int sender , receiver,flag ,exitCheck;
    
//to make sure that the user want to continue
while (1)
    {
        printf("1-continue\n2-return back\n");
        printf("Enter your choice: ");
        scanf("%d",&flag);
        if(flag==1)
            break;
        else if(flag==2)
            return;
        else 
            printf("Wrong choice try again\n");
    }
//check if the sender exists or not
printf("now checking sender\n");
while(1)
    {
        sender=search_account(1);
        if(sender==-1)
        {
            printf("Please enter a valid bank account number\nTo exit Enter 0\n");
            scanf("%d",&exitCheck);
            if(exitCheck==0) break;

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
            scanf("%d",&exitCheck);
            if(exitCheck==0) break;

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