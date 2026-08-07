#include "bsp/bsp_data_load.h"
#include <stdio.h>
#include <stdlib.h>



int data_load(contact_book *book, char *filename)
{
    FILE *fp;
    contact *_contact = book->contact_list;
    int *num = &book->contact_number;
    int num_copy; 

    fp = fopen(filename,"rb");

    if(fp == NULL)
    {
        printf("%s cant be open,failed to inheritance,please add a new contact to create a new contact_book\n\n",filename);
        return -1;
    }
        

    if( fseek(fp,0,SEEK_SET) != 0 )
    {
        printf("failed to fseek,cant load contact_number\n");
        fclose(fp);
        return -1;
    }
        
    
    if( fread(&num_copy,sizeof(int),1,fp) != 1 )
    {
        printf("failed to fread,cant load contact_number\n");
        fclose(fp);
        return -1;
    }

    if (num_copy < 0 || num_copy > MAX)
    {
        printf("contact_number is wrong,The database is corrupted\n");
        fclose(fp);
        return -1;
    }
    else
        *num = num_copy;

    if( fseek(fp,sizeof(int),SEEK_SET) != 0 )
    {
        printf("failed to fseek,cant load contact_list\n");
        fclose(fp);
        return -1;
    }
    
    if( fread(_contact,sizeof(_contact[0]),*num,fp) != *num )
    {
        printf("failed to fread,cant load contact_list\n");
        fclose(fp);
        return -1;
    }
    
    fclose(fp);

    return 0;

}
