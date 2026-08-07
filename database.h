#ifndef DATABASE_H_
#define DATABASE_H_

#define MAX 30


typedef struct {
    char id[20];
    char name[20];
    char phone[15];
} contact;

typedef struct {
    contact contact_list[MAX];
    int contact_number;
} contact_book;



#endif