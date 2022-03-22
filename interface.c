#include "interface.h"

#include "customer.h"
#include "book_management.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



 void main_menu() {
    printf("Enter the number before the option and press enter to confirm.\n");
    printf("1.Manager entrance\n");
    printf("2.Reader entrance\n");
    printf("3.Quit\n\n");
    printf("Please choose an option:");
}

void mainchoose(){
    char choose;
    int tag = 1;
    while(tag){
        main_menu();
        scanf(" %c", &choose);
        getchar();
        switch(choose)
        {
            case'1':
                loginmain1();
                break;
            case'2':
                loginmain();
                break;
            case'3':
                printf("Press any key to continue..");
                getch();
                tag = 0;
                break;
            default:
                printf("\nInvalid option\n");
                printf("Press any key to continue..");
                getch();
                break;
        }
        system("cls");
    }
}

void run_interface() {

    main_menu();
    mainchoose();
    //time to clean up behind us.

    customer_cleanup();
    order_cleanup();

    return;
}
