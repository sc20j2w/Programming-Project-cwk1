#include "book_management.h"
#include "interface.h"
#include "user.h"
#include "save.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//return book
int book_return(char*Name){
    int i = 0;
    int judge = 0;
    int m = 0;
    User *p;
    p = temp_list;
    p = p->next;
    Book *t;
    t = bl_head->list;
    t = t->next;
    // Determine whether you have borrowed a book
    while(1){
        Name[strlen(Name)] = '\n';
        if(strcmp(p->username,Name) == 0)
        {
            Name[strlen(Name)-1] = '\0';
            break;
        }
        Name[strlen(Name)-1] = '\0';
        p = p->next;
    }
    for(i=0; i<=99; i++){
        if (t == NULL){
            return 0;
        }
        while(1){
            if(p->book_id[i] == t->id)
            {
                judge = 1;
                break;
            }
            if(p->book_id[i] == 0)
            {
                break;
            }
            t = t->next;
        }
    }
    if(judge == 0){
        printf("You don't borrow any books!\n");
        return 0;
    }
    // Find and read borrowed books
    if(judge != 0){
        Book *q;
        q = bl_head->list;
        q = q->next;
        printf("Enter the ID(1~99) of the book which you want to return: ");
        scanf("%d",&m);
        getchar();
        for(i=0; i<=99; i++){
            if (p->book_id[i] == m)
            {
                while(1)
                {
                    if (q->id == p->book_id[i])
                    {
                        q->copies = q->copies+1;
                        p->book_id[i] = 0;
                        printf("You have returned the book successfully");
                        return 0;
                    }
                    q = q->next;
                }
            }
        }
    }
    printf("You didn't borrow this book!");
    return 0;
}


//borrow book
int book_borrow(char*Name){
    int i = 0;
    int j = 0;
    printf("Enter the ID(1~99) of the book which you want to borrow: \n");
    scanf("%d",&i);
    getchar();
    Book *p;
    p = bl_head->list;
    p = p->next;
    // find book
    while(1){
        if(p == NULL){
            printf("We don't have this book. \n");
            return 0;
        }
        if(p->id == i)
        {
            break;
        }
        p = p->next;
    }
    // find copy
    if(p->copies <= 0){
        printf("The book is out of loan, please come next time. \n");
        return 0;
    }else if(p->copies > 0){
        Name[strlen(Name)] = '\n';
        User*t;
        t = temp_list;
        t = t->next;
        while(1)
        {
            if(strcmp(t->username,Name) == 0)
            {
                break;
            }
            t = t->next;
        }
        for(j=0; j<=99; j++)
        {
            if(t->book_id[j] == 0)
            {
                t->book_id[j] = i;
                printf("You borrowed the book successfully!\n");
                break;
            }else if(t->book_id[j] == i){
                Name[strlen(Name)-1] = '\0' ;
                printf("Sorry, you have a copy of this book on loan.\n");
                return 0;
            }else if(j == 100){
                printf("You can not borrowed the book!\n");
                return 0;
            }
        }
        p->copies = p->copies - 1;
        Name[strlen(Name)-1] = '\0' ;
    }
}

BookList find_book_by_year (unsigned int year){
    printf("%s\t","ID");
    printf("%-30s\t","Title");
    printf("%-30s\t","Authors");
    printf("%-4s\t","Year");
    printf("%-4s\n","Copies");
    printf("\n");
    Book *p;
    p = bl_head->list;
    p = p->next;
    int i = 0;
    while (1)
    {
        if( p == NULL){
            if(i == 0){
                printf("Sorry, there is no book in the library.\n");
                break;
            }
            break;
        }
        if(year == p->year)
        {
            i = 1;
            printf("%d\t",p->id);
            printf("%-30s\t",p->title);
            printf("%-30s\t",p->authors);
            printf("%-4d\t",p->year);
            printf("%-4d\n",p->copies);
            printf("\n");
        }
        p = p->next;
    }
}

BookList find_book_by_author (const char *author){
    printf("%s\t","ID");
    printf("%-30s\t","Title");
    printf("%-30s\t","Authors");
    printf("%-4s\t","Year");
    printf("%-4s\n","Copies");
    printf("\n");
    Book *p;
    p = bl_head->list;
    p = p->next;
    int i = 0;
    while (1)
    {
        if( p == NULL){
            if(i == 0){
                printf("Sorry, there is no book in the library.\n");
                break;
            }
            break;
        }
        if(strcmp(author,p->authors) == 0)
        {
            i = 1;
            printf("%d\t",p->id);
            printf("%-30s\t",p->title);
            printf("%-30s\t",p->authors);
            printf("%-4d\t",p->year);
            printf("%-4d\n",p->copies);
            printf("\n");
        }
        p = p->next;
    }
}

BookList find_book_by_title (const char *title){
    printf("%s\t","ID");
    printf("%-30s\t","Title");
    printf("%-30s\t","Authors");
    printf("%-4s\t","Year");
    printf("%-4s\n","Copies");
    printf("\n");
    Book *p;
    p = bl_head->list;
    p = p->next;
    int i = 0;
    while (1)
    {
        if( p == NULL){
            if(i == 0){
                printf("Sorry, there is no book in the library.\n");
                break;
            }
            break;
        }
        if(strcmp(title,p->title) == 0)
        {
            i = 1;
            printf("%d\t",p->id);
            printf("%-30s\t",p->title);
            printf("%-30s\t",p->authors);
            printf("%-4d\t",p->year);
            printf("%-4d\n",p->copies);
            printf("\n");
        }
        p = p->next;
    }
}

//search book
int book_search(){
    while(1) {
        printf("Please choose an option:\n");
        printf("(1) Find by title\n");
        printf("(2) Find by authors\n");
        printf("(3) Find by year \n");
        printf("(4) Quit \n ");
        printf("     option:");
        int option;
        while(1){
            int j = 0;
            scanf("%d", &option);
            while(getchar() != '\n') j++;
            if(j > 0) {
                printf("Sorry, the option you entered was invalid, please try again.\n");
                printf("Please choose an option:\n");
                printf("(1) Find by title\n");
                printf("(2) Find by authors\n");
                printf("(3) Find by year \n");
                printf("(4) Quit \n ");
                printf("     option:");
                continue;
            }else break;
        }
        if (option == 1) {
            char *title;
            title = (char *) malloc(100 * sizeof (char));
            printf("Please enter the title: \n");
            fflush(stdin);
            gets(title);
            find_book_by_title(title);
        }else if(option == 2) {
            char *author;
            author = (char *) malloc(100 * sizeof (char));
            printf("Please enter the author: \n");
            fflush(stdin);
            gets(author);
            find_book_by_author(author);
        }else if(option == 3) {
            int year;
            printf("Please enter year: \n");
            fflush(stdin);
            scanf("%d", &year);
            getchar();
            find_book_by_year(year);
        }else if(option == 4) {
            printf("You've ended the search function.\n");
            break;
        }else if (option != 1 && option != 2 && option != 3 && option != 4 ){
            printf("Sorry, the option you entered was invalid, please try again. \n");
            continue;
        }
    }
}

//remove book
int remove_book(Book book){
    int i = 0;
    User *q;
    q = temp_list;
    q = q->next;
    // Check if anyone has borrowed the book
    while(1)
    {
        if(q == NULL)
        {
            break;
        }
        for(i=0; i<=99; i++)
        {
            if(q->book_id[i] == book.id)
            {
                printf("You can't delete it until someone returns it! \n");
                return 0;
            }
        }
        q = q -> next;
    }
    // The deletion procedure is officially entered
    Book *head,*p;
    p = bl_head->list;
    head = p;
    head = head->next;
    while(1){
        if(head == NULL)
        {
            break;
        }
        if(head->id == book.id)
        {
            p->next = head->next;
            free(head);
            printf("You succeeded in deleting the book! please login again to refresh routine. \n");
            return 0;
        }
        p = head;
        head = head->next;
    }
    printf("There is no book in the library!\n");
    return 0;
}


//add book
int add_book(Book book){
    int i = 0;
    Book *p,*head,*last;
    last = bl_head->list;
    head = last;
    p = last->next;
    while(1){
        if(p == NULL)
        {
            p = (Book*)malloc(sizeof(Book));
            p->id = i + 1;
            p->title = book.title;
            p->authors = book.authors;
            p->year = book.year;
            p->copies = book.copies;
            p->next = NULL;
            head->next = p;
            break;
        }
        i = p->id;
        head = p;
        p = p->next;
    }
    return 1;
}

