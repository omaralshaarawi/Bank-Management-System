#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include "structs.h"

void save(customer e, int is_new);
void add_account(void);
int search_account(int check);
void advanced_search(void);
int Delete_account(int multiple);
void modify_account(void);
void delete_multipile(void);

/* data load */
void load(void);

#endif // BANKACCOUNT_H
