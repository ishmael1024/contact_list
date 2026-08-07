#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "data/database.h"
#include "bsp/bsp_readline.h"
#include "bsp/bsp_data_load.h"
#include "app/contact_manage.h"




int main()
{
    contact_book mycontact_book = {0};
    int flag = 1,   command_num,  contact_number;
    char command_list[6][10] = {
        "add",
        "print",
        "search",
        "modify",
        "delete",
        "quit"
    };
    char command[10];

    data_load(&mycontact_book, "D:\\Personal\\Desktop\\通讯录系统\\DATABASE.dat");

    while(flag)
    {
        printf("please enter the command:\n \
                        1) add\n \
                        2) print\n \
                        3) search\n \
                        4) modify\n \
                        5) delete\n \
                        6) quit\n");
        
        if( readline(command, sizeof(command)) == -1)
        {
                printf("failed to enter command\n");
                        exit(0);
        }
        

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
            case 4: contact_delete(&mycontact_book);
                    break;
            case 5: quit(&flag);
                    break;
            default: printf("NO VALID COMMAND!");
                     break;               
        }
    }

    return 0;
}