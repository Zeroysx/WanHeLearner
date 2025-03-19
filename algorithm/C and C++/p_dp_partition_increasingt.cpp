/*
题目：递增数分裂问题的动态规划解法
最后修订时间:2025/3/19
作者: whsialcx
备注: 该程序通过不同的动态规划策略（普通动态规划和位置依赖动态规划）来计算将一个正整数分裂成若干递增数的组合数。
      例如1可以分成(1);2可以分成(1,1),(2);3可以分成(1,1,1),(1,2)和(3)
      包括暴力递归、动态规划和位置依赖动态规划三种实现方式。
      在数据量较大时，位置依赖的动态规划效率明显高于暴力递归。
*/
#include<bits/stdc++.h>
using namespace std;
//函数声明
int way1(int pre, int rest);
int way2(int n);
int way3(int n);

//暴力递归
int way1(int pre, int rest)
{
    if(rest == 0)
    {
        return 1;
    }
    if(pre > rest)
    {
        return 0;
    }
    int way = 0;
    for(int i = pre; i <= rest; i++)
    {
        way += way1(i, rest - i);
    }
    return way;
}

//动态规划
int way2(int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));//默认从1开始，所以dp数组的大小为n+1 * n+1
    for(int i = 1; i <= n; i++)//初始化数组
    {
        dp[i][0] = 1;
    }
    for(int pre = n; pre > 0; pre--)//填表
    {
        for(int rest = pre; rest <= n; rest++)
        {
            for(int i = pre; i <= rest; i++)
            dp[pre][rest] += dp[i][rest - i];
        }
    }
    return dp[1][n];
}

//位置依赖的动态规划
int way3(int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        dp[i][i] = 1;
    }
    for(int pre = n - 1; pre > 0; pre--)
    {
        for(int rest = pre + 1; rest <= n; rest++)
        {
            dp[pre][rest] = dp[pre][rest - pre] + dp[pre + 1][rest];
        }
    }
    return dp[1][n];
}
int main() {
    // 输入要计算的递增数分裂问题的数字
    cout << "Input the number (n) to calculate the number of ways to split into increasing parts: " << endl;
    int n;
    cin >> n;
    // 输出暴力递归方法的结果
    cout << "Result using brute force recursion (way1): " << way1(1, n) << endl;
    // 输出动态规划方法的结果
    cout << "Result using dynamic programming (way2): " << way2(n) << endl;
    // 输出位置依赖动态规划方法的结果
    cout << "Result using position-dependent dynamic programming (way3): " << way3(n) << endl;
    return 0;
}