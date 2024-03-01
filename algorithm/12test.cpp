/*
12test.cpp测试程序
最后修订时间：2024/3/1
作者：Wanhe
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
    delete []val;
}
template <typename T>
int Array<T>::binarySearch(T target)
{
    // int t = this->length/2;
    //查找区间
    int interval[2];
    if(this->val[length/2] == target)
            return length/2;
    else if(this->val[length/2] < target)
    {
        interval[0] = length/2;
        interval[1] = length;
    }
    else
    {
        interval[1] = length/2;
        interval[0] = -1;
    }
    while (interval[0] != interval[1] && interval[0] >= -1 && interval[1] < length)
    {
        if(this->val[(interval[0]+interval[1])/2] == target)
            return (interval[0]+interval[1])/2;
            if (this->val[(interval[0]+interval[1])/2] > target)
            {
                interval[1] = (interval[0]+interval[1])/2;
            }
            else interval[0] = (interval[0]+interval[1])/2 ;
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
    int array[9];
    cout<<"Input 9 int number."<<endl;

    for(int i = 0; i < 9;i++)
    {
        cin>>array[i];
    }
    Array<int> arr(array,9);
    cout<<"Input the value you want to search."<<endl;
    int t;
    cin>>t;
    
    cout<<"The value you search is in No."<<arr.binarySearch(t)<<" place."<<endl;

}