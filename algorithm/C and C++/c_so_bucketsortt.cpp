/*
题目：桶排序算法
最后修订时间:2025/3/19
作者: whsialcx
备注: 实现了桶排序算法，使用桶分配和排序方法对数组进行排序
*/

#include <bits/stdc++.h>
using namespace std;

void bucketSort(vector<int> &nums)
{
    int n = nums.size();
    int mn = nums[0], mx = nums[0];
    for (int i = 1; i < n; i++)
    {
        mn = min(mn, nums[i]);
        mx = max(mx, nums[i]);
    }
    int size = (mx - mn) / n + 1;   // size 至少要为1
    int cnt = (mx - mn) / size + 1; // 桶的个数至少要为1
    vector<vector<int>> buckets(cnt);
    for (int i = 0; i < n; i++)
    {
        int idx = (nums[i] - mn) / size;
        buckets[idx].push_back(nums[i]);
    }
    for (int i = 0; i < cnt; i++)
    {
        sort(buckets[i].begin(), buckets[i].end());
    }
    int index = 0;
    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < buckets[i].size(); j++)
        {
            nums[index++] = buckets[i][j];
        }
    }
}

int main()
{
    // 输入
    vector<int> nums = {4, 2, 7, 1, 9, 3};
    cout << "Before sorting: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;
    // 调用桶排序
    bucketSort(nums);
    // 输出排序后的结果
    cout << "After sorting: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;
    return 0;
}