/*  Copyright (C++) 2018 * Ltd. All rights reserved.
 *      Create date : 2018-08-28 23:06:59
*================================================*/

#include<iostream>  
#include<vector>  
#include<map>  
#include<iomanip>  
  
using namespace std;    
  
int main()  
{  
    double N,maxneed,tm,ts;  
    cin>>N>>maxneed;  
    vector<double> vm,vs,vp;//vm是总量，vs是总销售额，vp是价格  
    for(int i = 1;i<=N;++i)  
    {  
     cin>>tm;  
     vm.push_back(tm);  
    }  
    for(int i = 1;i<=N;++i)  
    {  
     cin>>ts;  
     vs.push_back(ts);  
    }  
    for(int i = 0;i<N;++i)  
     vp.push_back(vs[i]/vm[i]);  

    map<double,double> m;  
    for(int i = 0;i<N;++i)  
     m.insert(make_pair(vp[i],vs[i]));//插入后自动按Key值进行排序  
    cout<<"按Key排序结果："<<endl;  
    for(map<double,double>::iterator it=m.begin();it!=m.end();++it)  
     cout<<it->first<<" "<<it->second<<endl;  

    //94.50
    return 0;  
}  

