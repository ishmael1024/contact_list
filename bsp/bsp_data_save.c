#include "bsp/bsp_data_save.h"
#include <stdio.h>



int data_save(contact_book *book, char *filename)
{
    contact *_contact = book->contact_list;
    int *num = &book->contact_number;
    FILE *fp;

    fp = fopen(filename,"wb+");
    if(fp == NULL)
    {
        printf("%s cant be open,failed to save\n",filename);
        return -1;
    }

    if( fwrite(num,sizeof(int),1,fp) != 1 )
    {
        printf("failed to write num\n");
        fclose(fp);
        return -1;
    }

    if( fwrite(_contact,sizeof(_contact[0]),*num,fp) != (*num) )
    {
        printf("failed to write contact\n");
        fclose(fp);
        return -1;
    }
    
    fclose(fp);
    
    return 0;
}