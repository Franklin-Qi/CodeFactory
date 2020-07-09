/*  Copyright (C++) 2018 * Ltd. All rights reserved.
 *      Create date : 2018-08-23 16:23:08
 *================================================*/

#include <iostream>
using namespace std;

class Distance {
    private:
        int feet; //英尺，0到无穷
        int inches; //英寸，0到12, 1英尺 = 12英寸
    public:
        Distance() {
            feet = 0;
            inches = 0;
        }
        Distance(int f, int i) {
            feet = f;
            inches = i;
        }

        void display() {
            cout<<"feet: "<<feet<<" inches: "<<inches<<endl;
        }

        //重载取反符号
        Distance operator-() {
            //return Distance(-feet, -inches); //这种方式不行，

            feet = -feet;
            inches = -inches;
            return Distance(feet, inches); //只能是这样，不能是return Distance;

        }

        //重载递增运算符(前缀)：++
        Distance operator++() {
            return Distance(feet++, inches++);
        }
        //重载递增运算符(后缀)：++
        Distance operator++(int) {
            //临时对象
            Distance d(feet, inches);
            feet++;
            inches++;
            return d;
        }

        //重载双目运算符：+, 对象加法,没有顺序要求
        Distance operator+(const Distance &d) {
            return Distance(this->feet+d.feet, this->inches+d.inches);
        }

        //重载双目运算符：+，与一个数相加有顺序要求，通过加一个友元函数使另一个顺序的输入合法。
        Distance operator+(const int a) {
            return Distance(feet+a, inches+a);
        }

        //重载双目运算符：+，友元函数，定义在外面
        friend Distance operator+(const int a, Distance d);


        //重载<比较运算符
        bool operator<(const Distance &d) {
            if(feet < d.feet)
                return true;
            if(feet == d.feet && inches < d.inches)
                return true;
            return false;
        }

        //重载提取运算符 >> 
        //const Distance &d, 因为d不变
        //把运算符重载函数声明为类的友元函数，这样我们就能不用创建对象而直接调用函数。
        friend ostream &operator<<(ostream &output, const Distance &d) {
            output<<"feet= "<<d.feet<<" inches= "<<d.inches<<endl;
            return output;
        }
        //重载输入运算符 <<
        //Distance &d，因为d会变
        friend istream &operator>>(istream &input, Distance &d) {
            input>>d.feet>>d.inches;
            return input;
        }

        //重载 = 赋值运算符
        void operator=(const Distance &d) {
            feet = d.feet;
            inches = d.inches;
        }
        //重载 () 函数调用运算符
        //创建一个可以传递任意数目参数的运算符函数。
        Distance operator()(int a, int b, int c) {
            Distance d;
            //进行随机运算
            d.feet = a + c + 10;
            d.inches = b + c + 100;
            return d;
        }
};

//友元函数
Distance operator+(const int a, Distance d) {
    return d+a;
}



/**************************************** TEST **********************************/
/* Test Function Type */
/**** 测试模板 ******/
typedef void(*TESTFUNC)(void);
static int iscontinue = 1;

#define TEST_CYCLE(c, f, s) \
{ \
    c = 0; \
    while(iscontinue) \
    { \
        f = s[c++]; \
        if(f == NULL) break; \
        f(); \
    } \
}


/************************************ 重载运算符 TEST START **********************/
//单目运算符：-取反
void overloading_invert_01(void) {
    Distance D1(12,23);
    -D1;
    D1.display();
}

//单目运算符：++递增，前缀
void overloading_adding_02(void) {
    Distance D1(12,23);
    ++D1;
    D1.display();
}
//单目运算符：++递增，后缀
void overloading_adding_01(void) {
    Distance D1(12,23);
    D1++;
    D1.display();
}

//双目运算符：+、-，与对象相加
void overloading_add_01(void) {
    Distance D1(12,23);
    D1 = D1 + D1;
    D1.display();
}
//双目运算符：+，与数相加
void overloading_add_02(void) {
    Distance D1(12,23);
    D1 = 1 + D1;
    D1.display();
}


//比较运算符：<
void overloading_compare_01(void) {
    Distance D1(12,23), D2(12,22);
    if(D1 < D2)
        cout<<"D1(12,23) < D2(12,22)"<<endl;
    else
        cout<<"D1(12,23 >= D2(12,22)"<<endl;
}


//重载运算符测试start
TESTFUNC TestFunc_C4[] = {
    //overloading_invert_01, //单目运算符：-
    overloading_adding_01,//单目运算符：++，前缀
    overloading_adding_02,//单目运算符：++，后缀
    //overloading_add_01, //双目运算符：+
    //overloading_add_02, //双目运算符：+
    //overloading_compare_01,//比较运算符：<
    NULL
};
//重载运算符测试end


//备用测试 
TESTFUNC TestFunc_X[] = {
    NULL
};

/************************************ TEST END ***********************************/


int main() {
    int cnt = 0;
    iscontinue = 1;
    TESTFUNC pFunc = NULL;


    //重载运算符测试
    TEST_CYCLE(cnt, pFunc,TestFunc_C4)

    return 0;
}
