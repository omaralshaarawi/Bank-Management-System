#include <stdio.h>
#include "sh3ro.c"
typedef struct
{
    int month;
    int year;
}date;

typedef struct
{
    date open;
    char name[100];
    int account_number;
    float balance;
    int mobile_number;
    char email[100];
 
}customer;


int main()
{
    int n=8;
    printf("%d",n);
    
    return 0;
}
