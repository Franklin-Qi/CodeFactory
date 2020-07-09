/*  Copyright (C++) 2018 * Ltd. All rights reserved.
 *      Create date : 2018-08-20 20:42:25
 *================================================*/

#include <iostream>
#include <cstring>
using namespace std;

typedef struct books {
    int id;
    char title[50];
    char author[50];
    char subject[100];
} Books, *pBooks; //struct books 取个别名 Books ;  struct books * 取个别名 Books

struct books setBooks(int id, const char *title, const char *author, const char* subject) {
    //char *给char []赋值只能通过strcpy，直接 = 会error
    //字符串是常量，作为实参传值时，形参需const char * ，不然会有warning
    Books books;
    books.id = id;
    strcpy(books.title, title);
    strcpy(books.author, author);
    strcpy(books.subject, subject);
    return books;
}


void printBook(Books book) {
    cout << "书 ID ：" << book.id << endl;
    cout << "书 标题 ：" << book.title <<endl;
    cout << "书 作者 ： " << book.author << endl;
    cout << "书 类目 ：" << book.subject <<endl;
}

void printBookPointer(pBooks book) {
    cout << "书 ID ：" << book->id << endl;
    cout << "书 标题 ：" << book->title <<endl;
    cout <<"书 作者 ： " <<book->author<<endl;
    cout <<"书 类目 ：" <<book->subject<<endl;
}

int main() {
    Books oneBook;
    pBooks twoBook;

    oneBook.id = 12345;
    strcpy(oneBook.title, "C++ 教程");
    strcpy(oneBook.author, "runoob");
    strcpy(oneBook.subject, "编程语言");
    oneBook = setBooks(123456, "CSS 教程", "runoob", "编程语言");
    printBook(oneBook);

    twoBook = &oneBook;
    printBookPointer(twoBook);

/*  段错误,twoBook没赋予存储空间，去赋值出错
    twoBook->id = 12346;
    strcpy(twoBook->title, "CSS 教程");
    strcpy(twoBook->author, "runoob");
    strcpy(twoBook->subject, "编程语言");
    */

    return 0;
}
