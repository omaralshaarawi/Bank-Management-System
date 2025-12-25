#ifndef STRUCTS_H
#define STRUCTS_H
typedef struct
{
    int month;
    int year;
}date;

typedef struct
{
    long long account_number;
    char name[100];
    char email[100];
    float balance;
    char mobile_number[20];
    date open;
    char active[10];
 
}customer;

extern customer customers[10007];
extern int n;
#endif

