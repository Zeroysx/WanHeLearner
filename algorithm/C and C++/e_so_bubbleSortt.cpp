/*
9.cpp测试程序
最后修订时间：2024/2/15
作者:Wanhe
*/
#include <iostream>

template <typename T>
void bubbleSort(T array,int length)
{
    for(int i = 0; i < length ;i++)
    {
        for(int j = 0 ; j < length - 1 ; j++)
        {
            if(array[j] < array[j+1])
            {
                int t = array[j];
                array[j] = array[j+1];
                array[j+1] = t;
            }
        }
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
    bubbleSort(array,length);
    for(int i:array)
        cout<<i<<"\t";    
}