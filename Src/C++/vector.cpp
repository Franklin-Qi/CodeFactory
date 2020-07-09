/*  Copyright (C++) 2018 * Ltd. All rights reserved.
 *      Create date : 2018-08-24 16:21:39
 *================================================*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*  bool isEmpty = vec1.empty();    //判断是否为空
 *  vec1.insert(vec1.end(),5,3);    //从vec1.back位置插入5个值为3的元素
 *  vec1.erase(vec1.begin(),vec1.begin()+2);//删除vec1[0]-vec1[2]之间的元素，不包括vec1[2]其他元素前移
 *  vector<int> vec2(vec1);  //使用vec1初始化vec2
 */

/* 容器最后插入和删除数据 */
void test01() {
    vector<int> obj; //向量是一个能够存放任意类型的动态数组
    for(int i=0; i<10; i++) {
        obj.push_back(i);
        cout<<obj[i]<<" ";
    }
    
    for(int i=0; i<5; i++) {
        obj.pop_back();//删除末尾值
    }

    obj.erase(obj.begin(), obj.begin()+2);//删除2个元素，左闭右开

    cout<<"\n"<<endl;
    
    for(int i=0; i<obj.size(); i++) {
        cout<<obj[i]<<" ";
    }
    cout<<"\n"<<endl;

}

/* clear()清空容器中所有数据 */
void test02() {
    vector<int> obj;
    for(int i=0; i<10; i++) {
        obj.push_back(i);
    }

    obj.clear();//清空容器中所有数据

    for(int i=0; i<obj.size(); i++) {
        cout<<obj[i]<<" ";
    }
}

bool compare(int a, int b) {
    return a>b; //降序；a<b为升序
}
/* sort由小到大排序, reverse反转元素，由大到小 */
void test03() {
    vector<int>obj;
    obj.push_back(1);
    obj.push_back(3);
    obj.push_back(2);
    for(int i=0; i<obj.size(); i++) {
        cout<<obj[i]<<" ";
    }
    cout<<endl;

    cout<<"sort: ";
    sort(obj.begin(), obj.end()); //sort由小到大

    for(int i=0; i<obj.size(); i++) {
        cout<<obj[i]<<" ";
    }
    cout<<endl;

    cout<<"sort降序: ";
    sort(obj.begin(), obj.end(), compare); //sort由小到大

    for(int i=0; i<obj.size(); i++) {
        cout<<obj[i]<<" ";
    }
    cout<<endl;

    cout<<"reverse: ";
    reverse(obj.begin(), obj.end()); //reverse反转元素，由大到小

    for(int i=0; i<obj.size(); i++) {
        cout<<obj[i]<<" ";
    }
    cout<<endl;

}

/* 数组访问&迭代器访问 */
void test04() {
    vector<int> obj;
    for(int i=0; i<10; i++) {
        obj.push_back(i);
    }

    //数组访问
    cout<<"数组访问：";
    for(int i=0; i<10; i++) {
        cout<<obj[i]<<" ";
    }
    cout<<endl;

    //迭代器访问
    cout<<"迭代器访问：";
    vector<int>::iterator it; //声明一个迭代器，遍历或指向容器元素
    for(it=obj.begin(); it!=obj.end(); it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
}

/* 二维数组 */
void test05() {
    int N=6, M=6;
    vector< vector<int> > obj(N, vector<int>(M)); //定义二维数组5行6列

    //赋值
    for(int i=0; i<obj.size(); i++) {
        for(int j=0; j<=i; j++) {
            obj[i][j] = j;
        }
    }

    //输出
    for(int i=0; i<obj.size(); i++) {
        for(int j=0; j<=i; j++) {
            cout<<obj[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


int main() {
    test01(); //简单一维数组，插入和删除数据
    //test02(); //清空容器所有数据
    //test03(); //sort排序
    //test04();   //迭代器访问容器元素
    //test05();   //二维数组

    return 0;
}
