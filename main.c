#include <stdio.h>
#include <string.h>
#include "main.h"
#include "contact_manage.h"
#include "database_inheritance.h"



int main()
{
    contact_book mycontact_book = {0};
    int flag = 1,   command_num,  contact_number,str_len;
    char ch;
    char command_list[6][10] = {
        "add",
        "print",
        "search",
        "modify",
        "delect",
        "quiet"
    };
    char command[10];

    database_inheritance(&mycontact_book);

    while(flag)
    {
        printf("please enter the command:\n \
                        1) add\n \
                        2) print\n \
                        3) search\n \
                        4) modify\n \
                        5) delect\n \
                        6) quiet\n");

        fgets(command,sizeof(command)-1,stdin);

        str_len = strlen(command);
        if( command[str_len-1] == '\n' )
                command[str_len-1] = '\0';
        else
                while( (ch = getchar()) != '\n'&& ch !=EOF );


        for(command_num = 0; command_num < 6; command_num++)
        {
            if( strcmp(command,command_list[command_num]) == 0 )
                break;
        }

        switch (command_num) {
            case 0: add(&mycontact_book);
                    break;
            case 1: print(&mycontact_book);
                    break;
            case 2: contact_search(&mycontact_book);
                    break;
            case 3: contact_modify(&mycontact_book);
                    break;
            case 4: contact_delect(&mycontact_book);
                    break;
            case 5: quiet(&flag);
                    break;
            default: printf("NO VALID COMMAND!");
                     break;               
        }
    }

    return 0;
}