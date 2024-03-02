/*
类模板的使用
最后修订时间:2024/3/2
作者：Wanhe

*/

#include <iostream>

template <typename T>
class classdemo
{
private:
//对象值
    T val;
    //对象计数
    static int NumofClass;

public:
    //默认构造函数
    classdemo(/* args */);
    //构造函数
    classdemo(T value);
    //折构函数
    ~classdemo();
    //返回存储的内容
    T showval();
    //改变val的值
    bool setval(T value);

};
template <typename T>
classdemo<T>::classdemo(/* args */)
{
    val = NULL;
    NumofClass++;

}
template <typename T>
classdemo<T>::~classdemo()
{
    NumofClass--;
}
template <typename T>
bool classdemo<T>::setval(T value)
{
    this->val =value;
}
template <typename T>
T classdemo<T>::showval()
{
    return this->val;
}
template <typename T>
classdemo<T>::classdemo(T value)
{
    this->val = value;
    NumofClass++;
}