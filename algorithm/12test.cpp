/*
12test.cpp测试程序
最后修订时间：2024/2/26
作者：Wanhe
未完成
*/
template <typename T>
class Array{
private:
int length;
T *val;
public:
//构造函数
Array();
Array(T value[],int leth);
//折构函数
~Array();

/**
 * @brief 二分查找算法
 * @return int
 * @retval 目标数据的下标
 * @retval -1:未查找到
 */
int binarySearch(T target);

bool setValue(T value,int n);
};

//函数定义

template <typename T>
Array<T>::Array(T value[],int leth)
{
    // length = sizeof(value)/sizeof(T);
    length = leth;
    val = new T[length];
    for(int i = 0 ; i < length ; i++)
        val[i] = value[i];
    
}
template <typename T>
Array<T>::~Array()
{
    delete val[];
}
template <typename T>
int Array<T>::binarySearch(T target)
{
    int t = this->length/2;
    while (t >= 0 && t < this->length)
    {
        if(this->val[t] == target)
            return t;
        else if(this->val[t] > target)
        {
            t = (t + length) / 2;
        }
        else
        {
            t = (t+1)/2 - 1;
        }
    }
    return -1;
    
}

template <typename T>
bool Array<T>::setValue(T value , int n)
{
    if(n < this->length && n > 0)
    this->val[n] = value;
    else return false;
    return true;
}

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//main函数
int main()
{
    int array[10];
    for(int i = 0; i < 10;i++)
    {
        cin>>array[i];
    }
    Array<int> arr(array,10);
    cout<<"Input the value you want to search."<<endl;
    int t;
    cin>>t;
    
    cout<<"The value you search is in No."<<arr.binarySearch(t)<<" place."<<endl;

}