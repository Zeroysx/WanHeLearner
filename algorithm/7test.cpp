/*
7.cpp测试程序
最后修订时间：2024/2/14
作者:Wanhe
*/
#include <iostream>

template <typename T> 
void insertionSort(T A[],int length)
{
    for( int j = 1; j < length; j++)
    {
        int key = A[j];
        int i = j - 1;
        //比较并插入key
        while ( i >= 0 && A[i] > key)
        {
            A[i+1] = A[i];
            i--;
        } 
        A[i+1] = key;    
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
    insertionSort(array,length);
    for(int i:array)
        cout<<i<<"\t";    
}