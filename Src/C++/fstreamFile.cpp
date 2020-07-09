/*  Copyright (C++) 2018 * Ltd. All rights reserved.
 *      Create date : 2018-08-21 16:10:39
 *================================================*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> //setw()
using namespace std;


typedef struct stu {
    char name[20];
    int num;
} STU;

void write() {
    ofstream fout("file.txt");
    if (!fout) {
        cout<<"打开文件失败"<<endl;
        return;
    }
    STU stu[3] = {"licheng",100,
                  "wangk",101,
                  "mas",102
                 };

    fout<<setw(8)<<"name"<<" "<<setw(8)<<"num"<<endl;
    for(int i =0; i<3; i++)
    {
        fout<<setw(8)<<stu[i].name<<" "<<setw(8)<<stu[i].num<<endl; //写入字符串
    }
    /*
    for(int i =0; i<3; i++)
    {
        cout<<stu[i].name<<" "<<stu[i].num<<endl; //写入字符串
    }
    */
    
    fout.close();
}

/* 从指定行进行读取数据到内存 */
void read() {
    ifstream fin("file.txt");
    if(!fin) {
        cout<<"打开文件失败\n";
        return;
    }

    STU stu[3];

    char str[100];////须大于文件中每行的最大字符数
    int pos = 1;//pos为第几行开始读取数据
    for(int i=0;i<pos;i++)
        fin.getline(str,100);//第2行读取数据
    //cout<<fin.tellg()<<endl;//当前定位指针的位置，字节数

    for(int i=0; i<3; i++)
    {
        fin>>stu[i].name>>stu[i].num;
    }

    fin.close();

    for(int j =0; j<3; j++)
    {
        cout<<setw(8)<<stu[j].name<<" "<<setw(8)<<stu[j].num<<endl; //写入字符串
    }

/*
    fin.seekg(18,ios::beg);
    streampos sp = fin.tellg();//sp为当前定位指针的位置，因为它在文件结束处，所以也就是文件的大小


    fin.seekg(sp);
    cout<<fin.rdbuf();
    */
}

/********************************************/
/* 二进制文件读写文件 */
void writeBin() {
    ofstream fout("file.txt", ios::binary);
    if(!fout) {
        cout<<"打开文件失败"<<endl;
        return;
    }

    STU stu[3] = {"lichen",100,
                  "wangk",101,
                  "mas",102
                 };
    for(int i=0; i<sizeof(stu)/sizeof(stu[0]); i++) {
        fout.write((char *)&stu[i], sizeof(stu[i]));
    }
    //fout.write((char *)&stu[0], sizeof(stu));//也可以，write参数：指针地址，字节数
    fout.close();

}

void readBin() {
    STU stu[3];
    ifstream fin("file.txt", ios::binary);
    if(!fin) {
        cout<<"打开文件失败"<<endl;
        return;
    }

    
    fin.read((char *)&stu[0], sizeof(stu));
    fin.close();

    for(int i=0; i<3; i++) {
        cout<<stu[i].name<<" "<<stu[i].num<<endl;
    }
}
/***********************************************************/

int main() {
    write();//写数据到文件中
    read();//读取数据在内存中

    //writeBin(); //写二进制数据到文件中
    //readBin(); //读取二进制数据到内存中

    return 0;
}
