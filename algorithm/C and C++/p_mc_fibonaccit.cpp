#include<bits/stdc++.h>
using namespace std;

/*
题目：斐波那契数列的第n项计算（矩阵快速幂）
程序最后修订时间：2025年3月19日
作者：whsialcx
问题描述/备注：
该程序通过矩阵快速幂的方式计算斐波那契数列的第n项，时间复杂度为O(logn)。
传统的斐波那契数列计算方法为递归或动态规划，时间复杂度较高。通过矩阵快速幂可以显著降低时间复杂度，达到O(logn)。
其中的矩阵乘法和矩阵幂的实现方式可以应用于更广泛的线性递推问题的求解。

*/

// 函数声明
vector<vector<int>> matrixpower(vector<vector<int>>& m, int p);
vector<vector<int>> mulmatrix(const vector<vector<int>>& A, const vector<vector<int>>& B);

// 矩阵快速幂，类似于对一个数求快速幂
vector<vector<int>> matrixpower(vector<vector<int>>& m, int p) {
    int n = m.size();
    vector<vector<int>> res(n, vector<int>(n, 0)); // 初始化res为单位矩阵
    for (int i = 0; i < n; i++) {
        res[i][i] = 1; // 单位矩阵，相当于数字1
    }
    vector<vector<int>> t = m; // 复制基矩阵
    for (; p > 0; p >>= 1) {
        if ((p & 1) != 0) // 如果当前位为1，乘以t
            res = mulmatrix(res, t);
        t = mulmatrix(t, t); // t平方
    }
    return res;
}

// 矩阵乘法，在规模确定的情况下时间复杂度为O(1)
vector<vector<int>> mulmatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int ROW = A.size();
    int COL = B[0].size();
    int commonDim = A[0].size(); 
    vector<vector<int>> result(ROW, vector<int>(COL, 0)); 
    
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            for (int k = 0; k < commonDim; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

int fibonacci(int n) 
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    vector<vector<int>> base = {{1, 1}, 
                                {1, 0}};
    vector<vector<int>> res = matrixpower(base, n - 2);
    return res[0][0] + res[1][0];
}

int main() {
    // 输入要计算的斐波那契数列的项数
    cout << "Input the position (n) of Fibonacci sequence: " << endl;
    int n;
    cin >> n;
    // 输出斐波那契数列的第n项
    cout << "Fibonacci number at position " << n << " is: " << fibonacci(n) << endl;
    return 0;
}
