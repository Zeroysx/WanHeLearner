#include<bits/stdc++.h>
using namespace std;
/*
斐波拉契数列求第n项，做到O(logn)的时间复杂度

通项F(n) = F(n - 1) + F(n - 2)，此时可以看作是行列式|F(n),F(n - 1)| = |F(1),F(2)|*{{1,1},
                                                                                {1,0}}^(n-2)
我们只要算出矩阵的n-2次方，根据矩阵乘法，计算出F(n)
这里的矩阵{{1,1},{1,0}}是根据特殊值计算得到的，可以先将4个值分别设置为x,y,z,w将n=3,n=4待人，求出对应的值
*/
/*
这里的方法不止适用于斐波拉契数列，其他类似的表达式固定的也可以采用这中方法
例如：F(n) = 3F(n - 3) - 2F(n - 1) + F(n - 2)
此时 我们就要构造一个3*3的矩阵最后的|F(n),F(n - 1),F(n - 2)| = |F(1),F(2),F(3)|*{{?,?,?},{?,?,?},{?,?,?}}^(n - 3)
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

int main() 
{
    int n = 5;
    cout << fibonacci(n) << endl;
    cin.get();
    return 0;
}
