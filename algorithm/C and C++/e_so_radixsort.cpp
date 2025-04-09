#include<bits/stdc++.h>
using namespace std;
/*
题目：基数排序算法
最后修订时间: 2024/4/4
作者: whsialcx
备注: 基数排序的实现，采用了逐位排序的思想
此算法需要用到数字位数计算函数f()以及获取每位数字的g()函数
*/
int g(int x, int b) 
{
    
    int divisor = 1;
    for (int i = 1; i < b; i++) 
    {
        divisor *= 10;
    }
    return (x / divisor) % 10;
}

int f(int number)
{
    int res = 0;
    while(number > 0)
    {
        res++;
        number = number / 10;
    }
    return res;
}

void radixosort(vector<int> &arr, int b)
{
    vector<int> num(arr.size());
    for(int i = 1 ; i <= b; i++)
    {
        vector<int> cn(10, 0);
        for(int j = 0; j < arr.size(); j++)
        {
            cn[g(arr[j], i)]++;
        }
        for(int k = 1; k < 10; k++)
        {
            cn[k] = cn[k - 1] + cn[k];
        }
        for(int y = arr.size() - 1; y >= 0; y--)
        {
            int h = g(arr[y], i);
            num[--cn[h]] = arr[y];
        }
        for(int k = 0; k < arr.size(); k++)
        {
            arr[k] = num[k];
        }
    }
}

int main()
{
    vector<int> arr = {31, 57, 10, 61, 120, 32, 13, 42, 14, 16};
    int maxnumber = INT_MIN;
    maxnumber = *max_element(arr.begin(), arr.end());
    radixosort(arr, f(maxnumber));
    for(int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}