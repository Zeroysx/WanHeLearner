/*
题目：堆排序算法
最后修订时间:2025/3/29
作者:whsialcx
备注:堆排序的典型实现，包含堆的插入和调整过程
此算法实现了堆排序算法
*/

#include<bits/stdc++.h>
using namespace std;

// 堆排
template <typename T>
void heapinsert(vector<T> &arr, int i)
{
    while(arr[i] > arr[(i - 1) / 2])
    {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

template <typename T>
void heapify(vector<T> &arr, int i, int light)
{
    int left = i * 2 + 1;
    while(left < light)
    {
        int la = arr[left + 1] > arr[left] ? left + 1 : left;
        la = arr[i] > arr[la] ? i : la;
        if(la == i)
        {
            break;
        } 
        swap(arr[la], arr[i]);
        i = la;
        left = la * 2 + 1;
    }
}

template <typename T>
void heapsort(vector<T> &arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        heapinsert(arr, i);
    }
    while(size > 0)
    {
        swap(arr[0], arr[--size]);
        heapify(arr, 0, size);
    }
}

int main()
{
    vector<int> arr = {10,4,2,7,10,4,7};
    //从小到大排序
    heapsort(arr, arr.size());
    for(int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}