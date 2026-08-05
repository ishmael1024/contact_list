#include "database_inheritance.h"
#include "main.h"
#include <stdio.h>
#include <stdlib.h>



void database_inheritance(contact_book *mycontact_book)
{
    FILE *fp;

    fp = fopen("DATABASE.dat","wb+");

    if(fp == NULL)
    {
        printf("DATABASE.dat cant be open,failed to inheritance\n");
        exit(1);
    }
        

    fseek(fp,0,SEEK_SET);
    fread(&mycontact_book->contact_number,sizeof(int),1,fp);

    fseek(fp,sizeof(int),SEEK_SET);
    fread(mycontact_book->contact_list,sizeof(mycontact_book->contact_list[0]),mycontact_book->contact_number,fp);

    fclose(fp);

}
