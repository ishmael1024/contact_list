#ifndef CONTACT_STORAGE_H_
#define CONTACT_STORAGE_H_

#include "data/database.h"

#define DATABASE_PATH "data/DATABASE.dat"

int data_load(contact_book *book, char *filename);
int data_save(contact_book *book, char *filename);

#endif