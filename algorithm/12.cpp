/*
二分查找算法
最后修订时间2024/2/22
作者：Wanhe

*/

template <typename T>
class Array{
private:
T *val;
int length;
public:
//构造函数
Array();
Array(T value[]);
//折构函数
~Array();

/**
 * @brief 二分查找算法
 * @return int
 * @retval 目标数据的下标
 * @retval -1:未查找到
 */
int binarySearch(T target);

};

//函数定义

template <typename T>
Array<T>::Array(T value[])
{
    length = sizeof(value)/sizeof(T);
    *val = new T[length];
    
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
            t = (t + length) / 2
        }
        else
        {
            t = (t+1)/2 - 1;
        }
    }
    return -1;
    
}
