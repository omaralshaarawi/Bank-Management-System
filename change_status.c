#include <stdio.h>
#include <string.h>
#include "structs.h"

void changeStatus() {
  long long enteredNum;
  int index,flag;
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