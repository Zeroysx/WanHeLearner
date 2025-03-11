/*
8.cpp测试程序
最后修订时间;2024/2/14
作者:Wanhe
*/
#include <iostream>

template <typename T>
void selectSort(T array[],int length)
{
    for(int i=0;i < length;i++)
    {
        T t=array[i];
        T *max=&array[i];
        for(int j = i+1; j < length ; j++)
            if(*max < array[j])
                max = &array[j];
        array[i] = *max;
        *max = t; 
    }
}

using std::cout;
using std::cin;
using std::endl;

int main()
{
    cout<<"Input your example(5 int words)."<<endl;
    int array[5];
    //输入样例
    for(int i = 0;i < 5;i++)
        cin>>array[i];

    int length = sizeof(array)/sizeof(array[0]);
    cout<<"Your example:"<<endl;
     for(int i:array)
        cout<<i<<"\t";
    cout<<endl;  
    cout<<"New array:"<<endl;
    selectSort(array,length);
    for(int i:array)
        cout<<i<<"\t";    
}