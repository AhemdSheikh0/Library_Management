#ifndef LIBRARY_FUNC_H_
#define LIBRARY_FUNC_H_


#define ADD_Book        1
#define Borrow_Book     2
#define Buy_Book        3
#define Print_All       4
#define Print_One       5
#define Delete_Book     6
#define Exit            7

typedef struct Library{

    bool state;
    bool deleted;
    char title[100];
    char author[100];
    int idx;
    int year;
    int copies;
    float price;
    
}Books;



int addBook();
void deleteBook();
void printABook();
void printLibraryBooks();
void borrowBook();
void buyBook();


#endif