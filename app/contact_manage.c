#include "app/contact_manage.h"
#include "console/console_io.h"
#include "storage/contact_storage.h"
#include <stdio.h>
#include <string.h>



int add(contact_book *book)
{
    contact_book temp = {0};
    contact *new_contact = temp.contact_list;
    int *num = &temp.contact_number;

    
    temp = *book;
    
    if( (*num) >= MAX )
    {
        printf("failue:space is full!\n");
        return -1;
    }
      
        
    printf("please enter the id:");
    if( readline(new_contact[*num].id, sizeof(new_contact[*num].id)) == -1 )
    {
        printf("failed to enter id\n");
        return -1;
    }

    printf("please enter the name:");
    if( readline(new_contact[*num].name, sizeof(new_contact[*num].name)) == -1 )
    {
        printf("\nfailed to enter name\n");
        return -1;
    }
    
    printf("please enter the phone:");
    if( readline(new_contact[*num].phone, sizeof(new_contact[*num].phone)) == -1 )
    {
        printf("failed to enter phone\n");
        return -1;
    }
    
    (*num)++;

    if( data_save(&temp, DATABASE_PATH) != 0)
    {
        printf("failed to save data,cant add\n");
        return -1;
    }

    *book = temp;

    printf("\n\nimformation has been recorded\n\n");
    
    wait_enter();
    
    return 0;
}



int contact_delete(contact_book *book)
{
    contact_book temp = {0};
    contact *_contact = temp.contact_list;
    int *num = &temp.contact_number;
    char name[20];

    temp = *book;

    if( (*num) == 0 )
    {
        printf("no contact,cant delect!\n");
        return -1;
    }
    

    printf("please enter the 'name' to delect:");
    if( readline(name, sizeof(name)) == -1)
    {
        printf("failed to enter the name");
        return -1;
    }
    

    for(int i = 0; i < *(num); i++)
    {
        if( strcmp(name,_contact[i].name) == 0 )
        {
            for(int j = i; j < (*num-1); j++)
            {
               strcpy(_contact[j].id,_contact[j+1].id);
               strcpy(_contact[j].name,_contact[j+1].name);
               strcpy(_contact[j].phone,_contact[j+1].phone);
            }
            
            (*num)--;
            if( data_save(&temp, DATABASE_PATH) != 0)
            {
                printf("failed to save data,cant delete\n");
                return -1;
            }

            *book = temp;

            printf("\n\ncontact has been delected\n\n");
            wait_enter();
            return 0;
        }
    }

    printf("failed to delete , please enter the valid name\n");
    wait_enter();

    return -1;
}



int contact_modify(contact_book *book)
{
    contact_book temp = *book;
    contact *_contact = temp.contact_list;
    int *num = &temp.contact_number;
    char name[20];

    if( (*num) == 0 )
    {
        printf("no contact,cant modify!\n");
        return -1;
    }

    printf("please enter 'name' to modify:");
    if( readline(name,sizeof(name)) == -1 )
    {
        printf("failed to enter the name\n");
        return -1;
    }
    

    for(int i = 0; i < (*num); i++ )
    {
        if(strcmp(name,_contact[i].name) == 0)
        {
            printf("please enter the new 'id':");
            if( readline(_contact[i].id,sizeof(_contact[i].id)) == -1 )
            {
                printf("failed to enter the new id\n");
                return -1;
            }
        

            printf("please enter the new 'phone':");
            if( readline(_contact[i].phone,sizeof(_contact[i].phone)) == -1 )
            {
                printf("failed to enter the new phone\n");
                return -1;
            }

            if( data_save(&temp, DATABASE_PATH) != 0)
            {
                printf("failed to save data,cant modify\n");
                return -1;
            }

            *book = temp;

            printf("\n\ncontact has been modifyed\n\n");
            wait_enter();
            return 0;
        }
    }

    printf("failed to modify,please enter the vaild name\n");
    wait_enter();

    return -1;
}




int contact_search(contact_book *book)
{
    contact *_contact = book->contact_list;
    int *num = &book->contact_number;
    char name[20];
    int found = 0;

    printf("please enter the 'name' to search:\n");
    if( readline(name,sizeof(name)) == -1)
    {
        printf("failed to enter the name\n");
        return -1;
    }
    
    printf("\t\tid\tname\tphone\n");

    for(int i = 0; i < (*num); i++)
    {
        if( strcmp(name,_contact[i].name) == 0 )
        {
            printf("\t\t%s\t%s\t%s\n\n",_contact[i].id, _contact[i].name, _contact[i].phone);
            found++;
        }
    }

    if(found == 0)
        printf("\t\tnot found\n\n");
    else
        printf("\t\tcontact has been searched\n\n");

    wait_enter();

    return 0;
}



void print(contact_book *book)
{
    contact *_contact = book->contact_list;
    int num = book->contact_number;

    printf("\t\tid\tname\tphone\n");

    for(int i = 0; i < num; i++)
        printf("\t\t%s\t%s\t%s\n",_contact[i].id,_contact[i].name,_contact[i].phone);

    printf("\n\n\t\timformation has been printed\n\n");
    wait_enter();
}



void quit(int *flag)
{
    *flag = 0;
    
}