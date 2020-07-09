/*  Copyright (C++) 2018 * Ltd. All rights reserved.
 *      Create date : 2018-08-21 20:47:50
 *================================================*/

#include <iostream>
#include <string>
using namespace std;

class Book {
    public:
        //自定了构造函数，那创建对象 (Book book;)会失败，这时是走的自定义的构造函数
        Book(){ ptr = new int;}
        Book(string title, int val);
        Book(const Book &obj);
        ~Book();

        //string getTitle(void) const;
        //1.在内联函数内不允许使用循环语句和开关语句；
        //2.内联函数的定义必须出现在内联函数第一次调用之前；
        //3.类结构中所在的类说明内部定义的函数是内联函数。
        inline string getTitle(void) const {
            return title;
        }

        string getTitle(string str) const {
            return str;
        }

        int getPtr(void) const;
        void setTitle(string title);

        int compare(int val) {
            return this->getPtr() > val;
        }

        friend void printBook(const Book &obj);

        Book operator+(const Book &b) {
            cout<<"**********"<<endl;
            Book book;
            cout<<"*********1*"<<endl;
            *book.ptr =( *(this->ptr) + *(b.ptr));
            cout<<"*********2*"<<endl;
            book.title = this->title + b.title;
            cout<<"*********3*"<<endl;
            return book;
        }

    private:
        string title;
        int *ptr;
};

class javaBook: public Book {
    public:
        javaBook(): Book("javabook1", 2365) {
            cout <<"子类构造函数：" <<endl;
        }
        
        string getJavaTitle() {
            return this->getTitle();
        }
    private:
        string name;
};

/***************************** begin成员函数 ******************/
/****** 构造函数 ********/
Book::Book(string title, int val): title(title) {
    cout << "调用简单构造函数：" << endl;
    ptr = new int;
    *ptr = val;
}

/****** 拷贝构造函数 ********/
//有的类有一个数据成员是指针，或者是有成员表示在构造函数中分配的其他资源，这两种情况下都必须定义拷贝构造函数。
//当用类的一个对象去初始化该类的另一个对象（或引用）时系统自动调用拷贝构造函数实现拷贝赋值。
//若函数的形参为类对象，调用函数时，实参赋值给形参，系统自动调用拷贝构造函数。 
//当函数的返回值是类对象时，系统自动调用拷贝构造函数。
Book::Book(const Book &obj) {
    cout << "调用拷贝构造函数：" << endl;
    ptr = new int;
    *ptr = *obj.ptr;
    title = obj.title;
}

/******* 析构函数 *********/
Book::~Book() {
    cout << "调用析构函数：" << endl;
    delete ptr;
}


/********************************************/

int Book::getPtr(void) const {
    return *ptr;
}

void Book::setTitle(string Title) {
    //形参最好不和类变量一样，不然赋值有问题
    title = Title;
}

/********* 友元函数 **********/
/* 因为友元函数没有this指针，则参数要有三种情况： 
 *
 * 要访问非static成员时，需要对象做参数；
 *
 * 要访问static成员或全局变量时，则不需要对象做参数；
 *
 * 如果做参数的对象是全局对象，则不需要对象做参数.
 *
 * 可以直接调用友元函数，不需要通过对象或指针
 */
void printBook(const Book &obj) {
    cout << "string: " << obj.getTitle() << endl;
    cout << "*ptr: " << obj.getPtr() << endl;
}

/********************************************/

/***************************** end成员函数 ******************/



//不设置为类成员函数，因此调用时不用类对象进行调用
void displayBooks(Book obj) {
    cout << "string: " << obj.getTitle() << endl;
    cout << "*ptr: " << obj.getPtr() << endl;
}

int main() {
    Book bookOne("java",123);
    //返回的匿名对象通过“=”号赋值给bookTwo，此时由于采用的是初始化的方式，因此编译器会直接将匿名对象的名称更改为bookTwo，
    //即直接转化为bookTwo，不会调用析构函数。
    //Book bookTwo; bookTwo = bookOne;
    //由于此时代码采用的是赋值的方式，因此编译器会调用拷贝构造函数将匿名对象拷贝给bookTwo，同时匿名对象被析构。
    Book bookTwo = bookOne; //当用类的一个对象去初始化该类的另一个对象（或引用）时系统自动调用拷贝构造函数实现拷贝赋值。
    Book *ptr ;
    ptr = &bookOne;
    cout<<"string = "<<ptr->getTitle()<<endl;
    //重载
    cout<<"重载string = "<<bookTwo.getTitle("重载string")<<endl;


    int *ptr1;
    int a = 0;
    ptr1 = &a;

    //操作符重载
    bookOne = bookOne + bookTwo;
    cout<<"操作符重载: "<<bookOne.getTitle()<<endl;

    javaBook javaOne;
    cout<<"java string = "<<javaOne.getJavaTitle()<<endl;


    printBook(bookTwo);

    if(bookTwo.compare(100)) {
        cout<<"123 > 100" <<endl;
    }
    else {
        cout<<"123 < 100" <<endl;
    }

    bookOne.setTitle("CSS");
    displayBooks(bookOne);  //若函数的形参为类对象，调用函数时，实参赋值给形参，系统自动调用拷贝构造函数。

    return 0;
}
