#include "database.h"
#include "contact_manage.h"
#include <stdio.h>
#include <string.h>
#include "bsp_readline.h"


int add(contact_book *book)
{
    FILE *fp;
    contact *new_contact = book->contact_list;
    int *num = &book->contact_number;

    

    if( *num >= MAX )
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

    fp = fopen("DATABASE.dat","wb+");
    if(fp == NULL)
    {
        printf("data_base.c cant be open,failed to add\n");
        return -1;
    }

    if( fseek(fp,0,SEEK_SET) != 0 )
    {
        printf("failed to fseek,cant add\n");
        return -1;
    }

    if( fwrite(num,sizeof(int),1,fp) != 1 )
    {
        printf("failed to write num\n");
        return -1;
    }

    if( fseek(fp,sizeof(int),SEEK_SET) != 0 )
    {
        printf("failed to fseek,cant add\n");
        return -1;
    }

    if( fwrite(new_contact,sizeof(new_contact[0]),*num,fp) != *num )
    {
        printf("failed to write contact\n");
        return -1;
    }
    
    fclose(fp);

    printf("\n\nimformation has been recorded\n\nplease press 'enter' to return");
    while(getchar() != '\n');
    
    return 0;
}



int contact_delete(contact_book *book)
{
    contact *_contact = book->contact_list;
    int *num = &book->contact_number;
    char name[20];
    FILE *fp;

    if(*num == 0)
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
    

    for(int i = 0; i < *num; i++)
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
        }
    }


    fp = fopen("DATABASE.dat","wb+");
    if(fp == NULL)
    {
        printf("data_base.c cant be open,failed to delect\n");
        return -1;
    }

    if( fseek(fp,0,SEEK_SET) != 0 )
    {
        printf("failed to fseek,cant delete\n");
        return -1;
    }

    if( fwrite(num,sizeof(int),1,fp) != 1 )
    {
        printf("failed to write num\n");
        return -1;
    }

    if( fseek(fp,sizeof(int),SEEK_SET) != 0 )
    {
        printf("failed to fseek,cant delete\n");
        return -1;
    }

    if( fwrite(_contact,sizeof(_contact[0]),*num,fp) != *num )
    {
        printf("failed to write contact\n");
        return -1;
    }

    fclose(fp);

    printf("\n\ncontact has been delected\n\nplease press 'enter' to return");
    while(getchar() != '\n');

    return 0;
}



int contact_modify(contact_book *book)
{
    contact *_contact = book->contact_list;
    int *num = &book->contact_number;
    char name[20];
    FILE *fp;

    if(*num == 0)
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
        }
    }

    fp = fopen("DATABASE.dat","wb+");
    if(fp == NULL)
    {
        printf("data_base.c cant be open,failed to modify\n");
        return -1;
    }

    if( fseek(fp,sizeof(int),SEEK_SET) != 0 )
    {
        printf("failed to fseek,cant modify\n");
        return -1;
    }

    if( fwrite(_contact,sizeof(_contact[0]),*num,fp) !=*num )
    {
        printf("failed to write modify contact\n");
        return -1;
    }
    
    fclose(fp);

    printf("\n\ncontact has been modifyed\n\nplease press 'enter' to return");
    while(getchar() != '\n');

    return 0;
}




int contact_search(contact_book *book)
{
    contact *_contact = book->contact_list;
    int *num = &book->contact_number;
    char name[10];

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
            printf("\t\t%s\t%s\t%s\n\n",_contact[i].id, _contact[i].name, _contact[i].phone);
    }

    printf("\t\tcontact has been searched\n\nplease prsee 'enter' to return\n");
    while(getchar() != '\n');

    return 0;
}



void print(contact_book *book)
{
    contact *_contact = book->contact_list;
    int num = book->contact_number;

    printf("\t\tid\tname\tphone\n");

    for(int i = 0; i < num; i++)
        printf("\t\t%s\t%s\t%s\n",_contact[i].id,_contact[i].name,_contact[i].phone);

    printf("\n\n\t\timformation has been printed\n\nplease press 'enter' to return");
    while(getchar() != '\n' );
}



void quit(int *flag)
{
    *flag = 0;
    
}