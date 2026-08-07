#include "database.h"
#include "database_inheritance.h"
#include <stdio.h>
#include <stdlib.h>



int database_inheritance(contact_book *book)
{
    FILE *fp;
    contact *_contact = book->contact_list;
    int *num = &book->contact_number; 

    fp = fopen("DATABASE.dat","rb");

    if(fp == NULL)
    {
        printf("DATABASE.dat cant be open,failed to inheritance,please add a new contact to create a new contact_book\n\n");
        return 0;
    }
        

    if( fseek(fp,0,SEEK_SET) != 0 )
        printf("failed to fseek,cant inheritance contact_number\n");
    
    if( fread(num,sizeof(int),1,fp) != 1 )
        printf("failed to fread,cant inheritance contact_number\n");

    if (*num < 0 || *num > MAX)
    {
        fclose(fp);
        return 0;
    }

    if( fseek(fp,sizeof(int),SEEK_SET) != 0 )
        printf("failed to fseek,cant inheritance contact_lsit\n");
    
    if( fread(_contact,sizeof(_contact[0]),*num,fp) != *num )
        printf("failed to fread,cant inheritance contact_lsit\n");
    fclose(fp);

}
