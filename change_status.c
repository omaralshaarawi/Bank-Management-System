#include <stdio.h>
#include <string.h>
#include "structs.h"

void changeStatus() {
  long long enteredNum;
  int exist = 0 ;
  int founded;

  
  //check if the acount exists or not
  while(!exist){
    
    printf("Enter the bank account number: ");
    scanf("%lld",&enteredNum);
        for(int i = 0 ; i < n ; i++){
          if(enteredNum == customers[i].account_number) {
            exist = 1;
            founded = i;
            break;}
  }
  
  if(!exist)  printf("This account doesn't exist try again\n"); 
            }

  //Understand what the user wants before processing
 
  int key = -1 ;
  while(key != 0 && key != 1){
  printf("To deactivate your account press 0\nTo activate your account press 1\n");
  scanf("%d",&key);
}
  
  //check the account current status to avoid conflects then change it

  //activate
  if(key){
    
    if(strcmp(customers[founded].active,"active") == 0) 
            printf("Your account is already activated!!\n");
              else strcpy(customers[founded].active,"active");
  
  }
  //deactivate
  if(!key){
    
    if(strcmp(customers[founded].active,"inactive") == 0) 
            printf("Your account is already deactivated!!\n");
              else strcpy(customers[founded].active,"inactive");
  }

  //adding changes to file
  FILE *fptr;
char acc_number[50];

  sprintf(acc_number,"%lld.txt",customers[founded].account_number);
    fptr = fopen(acc_number, "a");
    if (!fptr) {
    printf("Error opening file for status history.\n");
    return;
    }

    fprintf(fptr,"%lld status changed into %s\n",customers[founded].account_number,customers[founded].active);
    
    fclose(fptr);
  
}