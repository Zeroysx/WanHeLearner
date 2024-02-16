/*
11.cpp测试程序
最后修订时间：2024/2/16
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

template <typename T>
void mergeSort(T*  p,T* r)
{
    if(p < r)
    {
        T* q = p + (r - p) / 2;
        mergeSort(p,q);
        mergeSort(q + 1, r);
        merge(p,q,r);
    }
}

using std::cout;
using std::cin;
using std::endl;

int main()
{
    cout<<"Input your example(10 int words)."<<endl;
    int array[10];
    //输入样例
    for(int i = 0;i < 10;i++)
        cin>>array[i];
    //输出原例
    cout<<"Your example:"<<endl;
     for(int i:array)
        cout<<i<<"\t";
    cout<<endl;

    mergeSort(&array[0],&array[9]);  
    cout<<"New array:"<<endl;
    for(int i:array)
        cout<<i<<"\t";    
}
