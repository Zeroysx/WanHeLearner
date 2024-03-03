/*
题目:类模板的使用
最后修订时间:2024/3/3
作者：Wanhe
备注:过于粗糙，缺乏实际意义，待修改
*/
#include <iostream>

template <typename T>
class classdemo
{
private:
    // 对象值
    T val;
    // 对象计数
    static int NumofClass;

public:
    // 默认构造函数
    classdemo(/* args */);
    // 构造函数
    classdemo(T value);
    // 折构函数
    ~classdemo();
    // 返回存储的内容
    T showval();
    // 改变val的值
    bool setval(T value);
    int retnum() { return NumofClass; }
};
template <typename T>
classdemo<T>::classdemo(/* args */)
{
    val = NULL;
    NumofClass++;
}
// 折构函数
template <typename T>
classdemo<T>::~classdemo()
{
    NumofClass--;
}
// 修改val的值
template <typename T>
bool classdemo<T>::setval(T value)
{
    this->val = value;
    return true;
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
// 最大对象存在数
const int MAXOBJ = 5;
// 初始化计数
template <typename T>
int classdemo<T>::NumofClass = 0;
using std::cin;
using std::cout;
using std::endl;

// 演示程序
int main()
{
    //
    classdemo<int> *interobj = new classdemo<int>(1);
    classdemo<double> *floatobj = new classdemo<double>(2.00);
    classdemo<char> *charobj = new classdemo<char>('w');
    // 初始化输出;
    cout << "The value of these object:" << endl
         << interobj->showval() << '\t' << floatobj->showval() << '\t' << charobj->showval();
    // 修改对象的值
    cout << "Please input an int number , a float number and a character." << endl;
    int i;
    double j;
    char k;
    cin >> i >> j >> k;
    interobj->setval(i);
    floatobj->setval(j);
    charobj->setval(k);
    cout << "Now, the value of these object:" << endl
         << interobj->showval() << '\t' << floatobj->showval() << '\t' << charobj->showval();
    delete interobj;
    delete floatobj;
    delete charobj;
}