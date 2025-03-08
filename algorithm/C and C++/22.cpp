/*
题目:矩阵乘法的Strassen算法
最后修订时间：2025.2.20
作者:WanHe
备注:分治策略,计算n*n矩阵的乘法
*/
#include <stdlib.h>

// 矩阵的类
class Matrix
{
private:
    int rows;//矩阵的行数
    // int cols;//矩阵的列数
    int* data;//矩阵空间
public:
    Matrix(/* args */);
    ~Matrix();
    Matrix(int size);

    void setrows(int n);

    //重载以下运算符以满足矩阵乘法的计算
    Matrix operator=(Matrix m);
    int* operator[](unsigned n);//重载
    Matrix operator*(const Matrix m);
    Matrix operator+(const Matrix m1);
};

Matrix::Matrix(/* args */)
{
    rows = 0;
    // cols = 0; 
    data = nullptr;
}

Matrix::Matrix(int size)
{
    rows = size;
    data = new int[size*size];

}
Matrix::~Matrix()
{
    delete data;
}

 
//?问题：如何对矩阵的复制进行优化
void Matrix::setrows(int n)
{
    rows = n;
    //将


    delete [] data;
}

int* Matrix::operator[](unsigned n)
{
    return &data[n*rows];
}

Matrix operator*(const Matrix m)
{

}

Matrix Matrix::operator+(const Matrix m1)
{
    Matrix ret;
    //只有同型矩阵才能进行加减法。
    if(this->rows != m1.rows)
    {
        
    }
}

//test
#include <iostream>
int main()
{
    Matrix m(5);
    m[1][1] = 2;
    std::cout<<m[1][1];
}