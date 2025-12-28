#include <stdio.h>
#include <string.h>
#include "structs.h"
#include <time.h>
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

//check if the dailylimit and the current balance
//exceeded
if( (customers[i].lastwithdraw.withdrawn_amount + withdrawAmount) > 50000 ){
  printf("You are only allowed to withdraw %.2f for today!\n",50000-(customers[i].lastwithdraw.withdrawn_amount));
  return 0;
  }
// enough balance
if(customers[i].balance < withdrawAmount){
      printf("Not enough balance your current balance : %.2f\n",customers[i].balance);
      return 0;
    }
  
  //can be withdrawn 1-update the daily withdrawn amount 2-return 1 to confirm the operation
  customers[i].lastwithdraw.withdrawn_amount += withdrawAmount;
return 1;
}


