/*  Copyright (C++) 2018 * Ltd. All rights reserved.
 *      Create date : 2018-08-28 19:44:09
 *================================================*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
      bool operator() (const char& lhs, const char& rhs) const
        {return lhs<rhs;}
};

/* 构造函数 */
/*
void conStruct() {
    map<char,int> first;//直接定义
    first['a']=10;
    first['b']=30;
    first['c']=50;
    first['d']=70;

    map<char,int> second (first.begin(),first.end());//通过迭代器

    map<char,int> third (second); //复制

    map<char,int,classcomp> fourth;                 // 重新定义 Compare 对象，该对象内部对运算符 () 进行重载

    bool(*fn_pt)(char,char) = fncomp;
    map<char,int,bool(*)(char,char)> fifth (fn_pt); // 通过函数指针
}
*/

/* map<char,int> */
void test01() {
    map<char,int>::iterator it;
    map<char,int> mymap;
    mymap['a']=10;
    mymap['b']=30;
    mymap['c']=50;
    mymap['d']=70;
    for(it=mymap.begin(); it!=mymap.end(); it++) {
        cout<<it->first<<" "<<it->second<<endl;//迭代器全部输出元素
    }


    mymap['a']=1002;//修改映射值
    while(!mymap.empty()) {
        cout<<mymap.begin()->first<<" ==> "<<mymap.begin()->second<<endl;
        mymap.erase(mymap.begin());
    }

    mymap.insert(pair<char,int>('f',100));//插入元素
    cout<<"f ==> "<<mymap.find('f')->second<<endl;

/*
    map<char,int>::key_compare key_comp;//Compare 参数的使用
    key_comp =mymap.key_comp();
    cout << "mymap contains:\n";


    char highest = mymap.rbegin()->first;//迭代器反向遍历的起始位置
    it = mymap.begin();
    do {
        cout << (*it).first<< " => " << (*it).second << endl;
    } while ( key_comp((*it++).first, highest) );
    */

}

/* map<int,string> */
void test02() {
    map<int,string> mapStudent;

    /* 插入 */

    for(int i=0;i<9;i++) {
        mapStudent.insert(make_pair(i,"hello"));
    }
    mapStudent.insert(pair<int,string>(1,"wangc"));//插入
    mapStudent.insert(make_pair(2,"liming"));
    mapStudent.insert(pair<int,string>(2,"hengk"));//插入数据，重复的不插入
    mapStudent.insert(map<int, string>::value_type (3, "student_three")); //插入数据，重复的不插入 

    /* 查找 */
    cout<<"count(3)= "<<mapStudent.count(3)<<endl;//只是查找该元素是否存在，可以使用函数count(k)，该函数返回的是k出现的次数
    cout<<"find(2)= "<<mapStudent.find(2)->second<<endl;//想取得key对应的值，可以使用函数find(k)，该函数返回的是指向该元素的迭代器

    map<int,string>::iterator it;//迭代器

    /* 更新 */
    it = mapStudent.find(1);//更新
    if(it!=mapStudent.end()) {
        it->second = "wangchao";
    }

    /* 删除 */
    //mapStudent.erase(1);//删除的是m中键为k的元素，返回的是删除的元素的个数
    //mapStudent.erase(mapStudent.begin());//删除的是迭代器p指向的元素，返回的是void

    
    cout<<endl;
    for(it=mapStudent.begin(); it!=mapStudent.end(); it++)
        cout<<it->first<<" "<<it->second<<endl;//输出元素

}

void test03() {

}
int main() {
    test02();


    return 0;
}

