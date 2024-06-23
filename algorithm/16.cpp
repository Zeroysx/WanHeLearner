/*
题目:最大子数组问题
最后修订时间：2024/5/15
作者:Wanhe
备注:未完成(克鲁斯卡尔算法和普里姆算法)
问题描述：一个含有含符号数的数组，求其中拥有最大和的最大子数组
*/
#include "all_algorithm_lib.h"
#include <vector>
using std::vector;
// 定义一个极大数
const int MAX_NUM = 2147483647;

// Kruskal算法（克鲁斯卡尔算法)
/*
基本思路：
将不同的弧按边权的大小从小到大排序，从小到大开始连接各个端点
*/
typedef struct Tree
{
    char val;
    vector<Tree *> next;
};

class Max_subtree
{
private:
    int length;
    vector<char> val;
    // 带边权的邻接矩阵
    int *adjMatrix;

public:
    Max_subtree(/* args */);
    ~Max_subtree();
    // 为邻接矩阵分配内存
    void malloc_auto();
    // 输入端点值
    void inputval(int value);
    // 修改邻接矩阵的权值
    void changematrix(int begin, int end, int weight);
    // 克鲁斯卡尔算法
    Tree *Kruskal();
};
typedef struct Line
{
    int begin;
    int end;
    int weight;
};

Max_subtree::Max_subtree(/* args */)
{
}

Max_subtree::~Max_subtree()
{
}

void Max_subtree::inputval(int value)
{
    val.push_back(value);
    length++;
}
void Max_subtree::malloc_auto()
{
    delete adjMatrix;
    adjMatrix = new int[length * length];
}
void Max_subtree::changematrix(int begin, int end, int weight)
{
    adjMatrix[begin * length + end] = weight;
}

// 归并排序
void merge(std::vector<Line>::iterator *begin, std::vector<Line>::iterator *midduim, std::vector<Line>::iterator *end)
{
    // copy
    vector<Line> copy1;
    vector<Line> copy2;
    for (int i = 0; begin + i < midduim; i++)
    {
        copy1.push_back(*(*(begin + i)));
        copy2.push_back(*(*(midduim + i)));
    }
    // 比较
    for (int i = 0, j = 0; begin != end; begin++)
    {
        if (copy1[i].weight > copy2[j].weight)
        {
            **begin = copy1[i];
            i++;
        }
        else
        {
            **begin = copy2[j];
            j++;
        }
    }
}
void mergeSort(std::vector<Line> *begin)
{
    if (!begin->empty())
    {
        
    }
}
//
Tree *Max_subtree::Kruskal()
{
    // 将所有边压入数组中
    vector<Line> arrLine;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (adjMatrix[i * length + j] != 0)
            {
                arrLine.push_back({i, j, adjMatrix[i * length + j]});
            }
        }
    }

    // 将这些边按权值从小到大排序
    auto begin = arrLine.begin();
    auto end = arrLine.end();
}
