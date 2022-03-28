#include "book_management.h"
#include "interface.h"
#include "user.h"
#include "save.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>



int add_book(Book book)
{
    int num = 0;
    Book *last,*p,*q;
    last = bl_head->list;
    q = last;
    p = last->next;
    while(1){
        if(p == NULL)
        {
            p = (Book *) malloc(sizeof (Book));
            p->id = num+1;
            p->title = book.title;
            p->authors = book.authors;
            p->year = book.year;
            p->copies = book.copies;
            p->next = NULL;
            q->next = p;
            break;
        }
        num = p->id;
        q = p;
        p = p->next;
    }
    return 1;
}