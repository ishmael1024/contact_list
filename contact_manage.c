#include "contact_manage.h"
#include "main.h"
#include <stdio.h>
#include <string.h>


void add(contact_book *mycontact_book)
{
    int str_len;
    FILE *fp;
    char ch;

    if( mycontact_book->contact_number >= MAX )
    {
        printf("failue:space is full!\n");
        return;
    }
      
        
    printf("please enter the id:");
    fgets(mycontact_book->contact_list[mycontact_book->contact_number].id,sizeof(char)*19,stdin);

    str_len = strlen(mycontact_book->contact_list[mycontact_book->contact_number].id);
        if(mycontact_book->contact_list[mycontact_book->contact_number].id[str_len-1] == '\n' )
               mycontact_book->contact_list[mycontact_book->contact_number].id[str_len-1] = '\0';
        else
                while( (ch = getchar()) != '\n'&& ch !=EOF );
    

    printf("please enter the name:");
    fgets(mycontact_book->contact_list[mycontact_book->contact_number].name,sizeof(char)*19,stdin);

    str_len = strlen(mycontact_book->contact_list[mycontact_book->contact_number].name);
        if( mycontact_book->contact_list[mycontact_book->contact_number].name[str_len-1] == '\n' )
                mycontact_book->contact_list[mycontact_book->contact_number].name[str_len-1] = '\0';
        else
                while( (ch = getchar()) != '\n'&& ch !=EOF );
    

    printf("please enter the phone:");
    fgets(mycontact_book->contact_list[mycontact_book->contact_number].phone,sizeof(char)*14,stdin);

    str_len = strlen(mycontact_book->contact_list[mycontact_book->contact_number].phone);
        if( mycontact_book->contact_list[mycontact_book->contact_number].phone[str_len-1] == '\n' )
                mycontact_book->contact_list[mycontact_book->contact_number].phone[str_len-1] = '\0';
        else
                while( (ch = getchar()) != '\n'&& ch !=EOF );
    
    
    mycontact_book->contact_number++;

    fp = fopen("DATABASE.dat","wb+");
    if(fp == NULL)
    {
        printf("data_base.c cant be open,failed to add\n");
        return;
    }

    fseek(fp,0,SEEK_SET);
    fwrite(&mycontact_book->contact_number,sizeof(int),1,fp);

    fseek(fp,sizeof(int),SEEK_SET);
    fwrite(&mycontact_book->contact_list,sizeof(mycontact_book->contact_list[0]),mycontact_book->contact_number,fp);
    
    fclose(fp);

    printf("\n\nimformation has been recorded\n\nplease press 'enter' to return");

    while(getchar() != '\n');

}



void contact_delect(contact_book *mycontact_book)
{
    int str_len;
    char name[20],ch;
    FILE *fp;

    if(mycontact_book->contact_number == 0)
    {
        printf("no contact,cant delect!\n");
    }
    

    printf("please enter the 'name' to delect:");

    fgets(name,sizeof(char)*19,stdin);
    
    str_len = strlen(name);
        if( name[str_len-1] == '\n' )
                name[str_len-1] = '\0';
        else
                while( (ch = getchar()) != '\n'&& ch !=EOF );

    for(int i = 0; i < mycontact_book->contact_number; i++)
    {
        if( strcmp(name,mycontact_book->contact_list[i].name) == 0 )
        {
            for(int j = i; j < (mycontact_book->contact_number); j++)
            {
               strcpy(mycontact_book->contact_list[j].id,mycontact_book->contact_list[j+1].id);
               strcpy(mycontact_book->contact_list[j].name,mycontact_book->contact_list[j+1].name);
               strcpy(mycontact_book->contact_list[j].phone,mycontact_book->contact_list[j+1].phone);
            }
            
            mycontact_book->contact_number--;
        }
    }


    fp = fopen("DATABASE.dat","wb+");
    if(fp == NULL)
    {
        printf("data_base.c cant be open,failed to delect\n");
        return;
    }

    fseek(fp,0,SEEK_SET);
    fwrite(&mycontact_book->contact_number,sizeof(int),1,fp);

    fseek(fp,sizeof(int),SEEK_SET);
    fwrite(&mycontact_book->contact_list,sizeof(mycontact_book->contact_list[0]),mycontact_book->contact_number,fp);

    fclose(fp);

    printf("\n\ncontact has been delected\n\nplease press 'enter' to return");

    while(getchar() != '\n');
    
}



void contact_modify(contact_book *mycontact_book)
{
    char name[20],ch;
    int str_len;
    FILE *fp;

    if(mycontact_book->contact_number == 0)
    {
        printf("no contact,cant modify!\n");
        return;
    }

    printf("please enter 'name' to modify:");

    fgets(name,sizeof(name)-1,stdin);

        str_len = strlen(name);
        if( name[str_len-1] == '\n' )
                name[str_len-1] = '\0';
        else
                while( (ch = getchar()) != '\n'&& ch !=EOF );


    for(int i = 0; i < mycontact_book->contact_number; i++ )
    {
        if(strcmp(name,mycontact_book->contact_list[i].name) == 0)
        {
            printf("please enter the new 'id':");
            fgets(mycontact_book->contact_list[i].id,sizeof(char)*19,stdin);

            str_len = strlen(mycontact_book->contact_list[i].id);
            if( mycontact_book->contact_list[i].id[str_len-1] == '\n' )
                mycontact_book->contact_list[i].id[str_len-1] = '\0';
            else
                while( (ch = getchar()) != '\n'&& ch !=EOF );
        

            printf("please enter the new 'phone':");
            fgets(mycontact_book->contact_list[i].phone,sizeof(char)*14,stdin);

            str_len = strlen(mycontact_book->contact_list[i].phone);
            if( mycontact_book->contact_list[i].phone[str_len-1] == '\n' )
                mycontact_book->contact_list[i].phone[str_len-1] = '\0';
            else
                while( (ch = getchar()) != '\n'&& ch !=EOF );
            
        }
    }

    fp = fopen("DATABASE.dat","wb+");
    if(fp == NULL)
    {
        printf("data_base.c cant be open,failed to modify\n");
        return;
    }

    fseek(fp,sizeof(int),SEEK_SET);
    fwrite(&mycontact_book->contact_list,sizeof(mycontact_book->contact_list[0]),mycontact_book->contact_number,fp);
    
    fclose(fp);

    printf("\n\ncontact has been modifyed\n\nplease press 'enter' to return");

    while(getchar() != '\n');

}




void contact_search(contact_book *mycontact_book)
{
    char name[10],ch;
    int str_len;

    printf("please enter the 'name' to search:\n");

    fgets(name,sizeof(name)-1,stdin);

        str_len = strlen(name);
        if( name[str_len-1] == '\n' )
                name[str_len-1] = '\0';
        else
                while( (ch = getchar()) != '\n'&& ch !=EOF );

    printf("\t\tid\tname\tphone\n");

    for(int i = 0; i < mycontact_book->contact_number; i++)
    {
        if( strcmp(name,mycontact_book->contact_list[i].name) == 0 )
            printf("\t\t%s\t%s\t%s\n\n",mycontact_book->contact_list[i].id,mycontact_book->contact_list[i].name,mycontact_book->contact_list[i].phone);
    }

    printf("\t\tcontact has been searched\n\nplease prsee 'enter' to return\n");

    while(getchar() != '\n');

}



void print(contact_book *mycontact_book)
{
    
    printf("\t\tid\tname\tphone\n");

    for(int i = 0; i < mycontact_book->contact_number; i++)
        printf("\t\t%s\t%s\t%s\n",mycontact_book->contact_list[i].id,mycontact_book->contact_list[i].name,mycontact_book->contact_list[i].phone);

    printf("\n\n\t\timformation has been printed\n\nplease press 'enter' to return");

    while(getchar() != '\n' );
}



void quiet(int *flag)
{
    *flag = 0;
    
}