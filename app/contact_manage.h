#ifndef CONTACT_MANAGE_H_
#define CONTACT_MANAGE_H_

#include "data/database.h"

int add(contact_book *book);
int contact_delete(contact_book *book);
int contact_modify(contact_book *book);
int contact_search(contact_book *book);
void print(contact_book *book);
void quit(int *flag);

#endif