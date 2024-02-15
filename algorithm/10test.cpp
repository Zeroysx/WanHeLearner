/*
10.cpp测试程序
最后修订时间：2024/2/15
作者:Wanhe
*/
#include <iostream>

const int FLAG=2147483647;

template <typename T>
void merge(T *p1,T *p2 ,T *p3)
{
    T *arr1 = new T;
    T *arr2 = new T;
    //将两个区间内的值复制
    int i = 0;
    for(; p1 + i <= p2 ; i++)
        *(arr1+i) = *(p1 + i);
    *(arr1+i) =  FLAG;
    for(i = 1; p2 + i <= p3 ; i++)
        *(arr2+i-1) = *(p2 + i);
    *(arr2+i-1) = FLAG;
    for(int i = 0,j = 0;p1 <= p3 ;p1++)
    {
        if(arr1[i] <= arr2[j])
          {
            *p1 = arr1[i];
            i++;
        }
        else 
        {
            *p1 = arr2[j];
            j++;
        }
    } 
}

using std::cout;
using std::cin;
using std::endl;

int main()
{
    cout<<"Input your example(10 int words).The first five numbers and the last five numbers must be in separate order"<<endl;
    int array[10];
    //输入样例,前五个数和后五个数必须分别降序
    for(int i = 0;i < 10;i++)
        cin>>array[i];
    //输出原例
    cout<<"Your example:"<<endl;
     for(int i:array)
        cout<<i<<"\t";
    cout<<endl;

    merge(&array[0],&array[4],&array[9]);  
    cout<<"New array:"<<endl;
    for(int i:array)
        cout<<i<<"\t";    
}