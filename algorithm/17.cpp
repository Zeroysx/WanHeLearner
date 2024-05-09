/*
题目:编写一个递归算法，从键盘输入一个正整数，给出其对应的2的幂次方表示形式，并要求按照次幂的降序排列。
最后修订时间：2024/5/9
作者:Wanhe
备注:规定：2的b次方即2^b， 用2{b}表示，2^1用2表示
*/
#include <iostream>
// using namespace std;
using std::cout;
using std::cin;
using std::endl;
//递归计算，直接输出
void output(int val)
{
    if(val == 0)
    return;
    int i = 0,j = 1;
    while (j * 2 <= val)
    {
        i++;
        j*=2;
    }
    cout<<"2";
    if(i != 0 && i != 1)
    {
        cout<<"{";
        output(i);
        cout<<"}";
    }
    else if(i == 0)
     cout<<"{0}";
     if(val - j != 0)
     cout<<"+";
     output(val - j);
}

int main()
{
    int val;
    cin>>val;
    output(val); 
}