#include<bits/stdc++.h>
using namespace std;
/*
题目：完美洗牌
最后修订时间:2025/3/19
作者: whsialcx
备注：将一个数组中给定的某一段范围中，将一个点的前后值交换顺序，要求O(1)的时间复杂度
长度为3^k - 1的数组，有固定的出发点是1 3 9 .....3^k - 1
*/
void change(vector<int> &arr, int begin, int end, int cs)
{
    int ll = begin;
    int rl = cs;
    while (ll < rl)
    {
        swap(arr[ll], arr[rl]);
        ll++;
        rl--;
    }
    int lr = cs + 1;
    int rr = end;
    while (lr < rr)
    {
        swap(arr[lr], arr[rr]);
        lr++;
        rr--;
    }
    reverse(arr.begin() + begin, arr.begin() + end + 1);
}

//下标从1开始，不从0开始
int modifyindex(int N, int i)
{
    if(i <= N / 2)
    {
        return i * 2;
    }
    return 2 * (i - N / 2) - 1;
}

int modifyindex2(int N, int i)
{
    return (2 * i) % (N + 1);
}

void clcys(vector<int> &arr, int begin, int len, int k)
{
    for(int i = 0, target = 1; i < k; i++, target *= 3)
    {
        int pre = arr[target + begin - 1];
        int cur = modifyindex2(len, target);
        while(cur != target)
        {
            swap(arr[cur + begin - 1], pre);
            cur = modifyindex2(len, cur);
        }
        arr[cur + begin - 1] = pre;
    }
}

void shuffle(vector<int> &arr, int l, int r)
{
    while (r - l + 1 > 0)
    {
        int len = r - l + 1;
        int base = 3;
        int k = 1;
        while(base <= (len + 1) / 3)
        {
            base *= 3;
            k++;
        }
        int half = (base - 1) / 2;
        int mid = (l + r) / 2;
        change(arr, l + half, mid + half, mid);
        clcys(arr, l, base - 1, k);
        l = l + base - 1;
    }
}

void shufflemain(vector<int> &arr)
{
    if(arr.size() != 0 &&(arr.size() & 1) == 0)
    return shuffle(arr, 0, arr.size() - 1);
}
int main()
{
    vector<int> arr = {2, 3, 4, 5};
    shufflemain(arr);
    for(int num : arr)
    {
        cout << num << " ";
    }//结果是4 2 5 3
}
