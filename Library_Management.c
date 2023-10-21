#include <stdio.h>
#include <stdbool.h>

#include "library_Func.h"

Books Book[100];

unsigned char bookID = 0;
bool startFlag = false;

int main(void)
{
    int systemModes = 0;
    bool end = true, checkOkay = true;


    while ( end )
    {
        printf("\nPlease select Mode: \n1- Add Book.\n2- Borrow Book. \n3- Buy Book. \n4- Print all books in library");
        printf("\n5- Print one book. \n6- Delete \n7- Exit.\n");
        printf("--------------------------------------------------\n- ");

        
        scanf("%d", &systemModes);
        fflush(stdin);

        switch (systemModes)
        {
        case ADD_Book:
            checkOkay = addBook();
            if ( checkOkay )
            {
                printf("\n%s is successfully added.\n", Book[bookID-1].title);
            }
            else
            {
                printf("\nBook is not added library is full.\n");
            }
            
            break;
        case Borrow_Book:
            borrowBook();
            break;
        case Print_One:
            printABook();
            break;
        case Print_All:
            printLibraryBooks();
            break;
        case Buy_Book:
            buyBook();
            break;
        case Delete_Book:
            deleteBook();
            break;
        case Exit:
            end = false;
            break;
        default:
            printf("Wrong Input please try again.\n\n");
            break;
        }
    }
    
    return 0;
}

int addBook()
{
    startFlag = true;
    bool checkAdded = true;
    int idCheck = 0;

    if ( bookID <= 100 && bookID >= 0 )
    {
        for (int i = 0; i < bookID; i++)
        {
            if ( Book[i].deleted )
            {
                idCheck = i;
                break;
            }
            
        }
        
        if (idCheck > 0)
        {
            printf("\nPlease Enter Book Name: ");
            gets(Book[idCheck].title);
            printf("\nPlease Enter Book's Author Name: ");
            gets(Book[idCheck].author);
            printf("\nPlease Enter Book price: ");
            scanf("%f", &Book[idCheck].price);
            fflush(stdin);
            printf("\nPlease Enter Book copies: ");
            scanf("%d", &Book[idCheck].copies);
            fflush(stdin);
            printf("\nPlease Enter Book's published year: ");
            scanf("%d", &Book[idCheck].year);
            fflush(stdin);

            Book[idCheck].idx = idCheck;

            if (Book[idCheck].copies > 0)
            {
                Book[idCheck].state = true;
                Book[idCheck].deleted = false;
            }

        }
        else
        {
            printf("\nPlease Enter Book Name: ");
            gets(Book[bookID].title);
            printf("\nPlease Enter Book's Author Name: ");
            gets(Book[bookID].author);
            printf("\nPlease Enter Book price: ");
            scanf("%f", &Book[bookID].price);
            fflush(stdin);
            printf("\nPlease Enter Book copies: ");
            scanf("%d", &Book[bookID].copies);
            fflush(stdin);
            printf("\nPlease Enter Book's published year: ");
            scanf("%d", &Book[bookID].year);
            fflush(stdin);

            Book[bookID].idx = bookID;

            if (Book[bookID].copies > 0)
            {
                Book[bookID].state = true;
                Book[bookID].deleted = false;
            }

            bookID++;
        }
        
    }
    else
    {
        printf("\nBook Store is full.\n");
        checkAdded = false;
    }
    
    return checkAdded;
}

void printABook()
{

    if (startFlag)
    {
        printf("\nAvilable Books with Ids:\n");

        for (int i = 0; i < bookID; i++)
        {
            printf("\nBook name: %s", Book[i].title);
            printf("\tID: %d", Book[i].idx);
        }
        
        int ID = 0;
        printf("\n\nPlease Enter Book ID: ");
        scanf("%d", &ID);
        fflush(stdin);

        if ((ID < 100) && !Book[ID].deleted)
        {
            if (ID < bookID)
            {

                printf("\nBook name: %s", Book[ID].title);
                printf("\nAuthor name: %s", Book[ID].author);
                printf("\nBook price: %.3f", Book[ID].price);
                printf("\nNo of copies: %d", Book[ID].copies);
                printf("\nPublished year: %d", Book[ID].year);
                if (Book[ID].state)
                {
                    printf("\nAvalable.");
                }
                else
                {
                    printf("\nNot avalable.");
                }

                printf("\n------------------------------------\n");
            }
            else
            {
                printf("\nBook ID not regestered yet.\n");
            }
        }
        else
        {
            printf("\nBook ID Not found please try again.\n");
        }
    }
    else
    {
        printf("\nNo Books registered yet.\n");
    }
    
}

void printLibraryBooks()
{

    if (startFlag)
    {
        for (int i = 0; i < bookID; i++)
        {
            if (Book[i].deleted)
            {
            }
            else
            {
                printf("\nBook name: %s", Book[i].title);
                printf("\nAuthor name: %s", Book[i].author);
                printf("\nBook price: %.3f", Book[i].price);
                printf("\nNo of copies: %d", Book[i].copies);
                printf("\nPublished year: %d", Book[i].year);
                if (Book[i].state)
                {
                    printf("\nAvalable.");
                }
                else
                {
                    printf("\nNot avalable.");
                }
                printf("\n--------------------------------\n");
            }
        }
    }
    else
    {
        printf("\nNo Books registered yet.\n");
    }
    
}

void deleteBook()
{

    if (startFlag)
    {
        printf("\nAvilable Books with Ids:\n");

        for (int i = 0; i < bookID; i++)
        {
            printf("\nBook name: %s", Book[i].title);
            printf("\t\tID: %d", Book[i].idx);
        }

        int ID = 0;
        printf("\n\nPlease Enter Book ID: ");
        scanf("%d", &ID);
        fflush(stdin);

        if (ID < 100)
        {
            if (ID < bookID)
            {
                Book[ID].state = false;
                Book[ID].deleted = true;

                printf("\nBook was deleted.\n");

                if (bookID == 1)
                {
                    startFlag = false;
                    bookID = 0;
                }
                

            }
            else
            {
                printf("\nBook ID not regestered yet.\n");
            }
        }
        else
        {
            printf("\nBook number is more than 100 please try again.\n");
        }
    }
    else
    {
        printf("\nNo Books registered yet.\n");
    }
    
}

void borrowBook()
{

    if (startFlag)
    {
        printf("\nAvilable Books with Ids:\n");
        for (int i = 0; i < bookID; i++)
        {
            printf("\nBook Name: %s", Book[i].title);
            printf("\tID: %d", Book[i].idx);
            printf("\tAvilable Copies: %d", Book[i].copies);
        }
        unsigned char ID = 0, copy = 0;

        printf("\n\nPlease Enter Book ID: ");
        scanf("%d", &ID);
        fflush(stdin);

        if (ID < 100)
        {

            printf("\n\nPlease Enter Number of copies you would like to borrow: ");
            scanf("%d", &copy);
            fflush(stdin);

            if ((ID < bookID) && !Book[ID].deleted)
            {
                Book[ID].copies -= copy;

                if ((Book[ID].copies <= 0))
                {
                    Book[ID].state = false;
                }
                else
                {
                    Book[ID].state = true;
                }

                printf("\nEnjoy reading.\n");
            }
            else
            {
                printf("\nBook ID not regestered or maybe deleted.\n");
            }
        }
        else
        {
            printf("\nBook number is more than 100 please try again.\n");
        }
    }
    else
    {
        printf("\nNo Books registered yet.\n");
    }
    
}

void buyBook()
{

    if (startFlag)
    {
        printf("\nAvilable Books with Ids:\n");

        for (int i = 0; i < bookID; i++)
        {
            printf("\nBook name: %s", Book[i].title);
            printf("\tID: %d", Book[i].idx);
            printf("\tAvilable Copies: %d", Book[i].copies);
        }

        unsigned char ID = 0, copy = 0;

        printf("\n\nPlease Enter Book ID: ");
        scanf("%d", &ID);
        fflush(stdin);

        if (ID < 100)
        {
            printf("\n\nPlease Enter Number of copies you would like to buy: ");
            scanf("%d", &copy);
            fflush(stdin);

            if ((ID < bookID) && !Book[ID].deleted)
            {
                Book[ID].copies += copy;
                Book[ID].state = true;
                printf("\nCopy is added.\n");
            }
            else
            {
                printf("\nBook ID not regestered yet or maybe deleted.\n");
            }
        }
        else
        {
            printf("\nBook number is more than 100 please try again.\n");
        }
    }
    else
    {
        printf("\nNo Books registered yet.\n");
    }
    
}
