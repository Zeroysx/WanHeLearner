#include<bits/stdc++.h>
using namespace std;
int convert_str_to_int(string str)
{
    bool neg = str[0] == '-' ? true : false;//判断是否为负数
    int minq = INT_MIN / 10;// 控制不会溢出
    int minr = INT_MIN % 10;// 控制不会溢出
    int res = 0;
    int cur = 0;
    int n = str.size();
    for(int i = neg ? 1 : 0; i < n ; i++)//如果是负数就从下标为1的位置开始，正数就从下标为0的位置开始
    {
        cur = '0' - str[i];//将字符串转为整型所对应的负数
        if((res < minq) || (res == minq && cur < minr))//检查是否越界
        {
            throw overflow_error("Cannot convert, will overflow range");
        }
        res = res * 10 + cur;
    }
    if(!neg && res == INT_MIN)//正数，但是等于系统最小值，越界
    {
        throw overflow_error("Cannot convert, will overflow range");
    }
    return neg ? res : -res;
}

int main()
{
    try
    {
        cout << convert_str_to_int("12131")<< endl;
        cout << convert_str_to_int("-2147483648") << endl;
        cout << convert_str_to_int("2147483648") << endl;
    }
    catch(const overflow_error &e)
    {
        cout << e.what() << endl;
    }
    cin.get();
    return 0;
    
}