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
//函数，获取数组长度
int getLength()
public:
//构造函数
Array();
Array(T value);
//折构函数
~Array();

/**
 * @brief 二分查找算法
 * @return int
 * @retval 目标数据的下标
 * @retval -1:未查找到
 */
int binarySearch(arrtype target);

};
template <typename T>
Array<T>::Array(T value)
{

}

