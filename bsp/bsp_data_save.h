#ifndef BSP_DATA_SAVE_H_
#define BSP_DATA_SAVE_H_

#include "data/database.h"

#define DATABASE_PATH "data/DATABASE.dat"

int data_save(contact_book *book, char *filename);

#endif