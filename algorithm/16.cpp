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

//Kruskal算法（克鲁斯卡尔算法)
/*
基本思路：
将不同的弧按边权的大小从小到大排序，从小到大开始连接各个端点
*/

// 节点的定义
typedef struct Node
{
    int id;
    int val;
};

//用一个数组存储以访问的端点
vector<int> visited_list;

/**
 * @brief 检查节点是否已经被加入树
 * 
 * @param id 端点的唯一的id
 * @param vsted_list 供搜索的已访问列表
 * @return true 已被加入树
 * @return false 未被加入树
 */
bool ifVisited(int id,vector<int> vsted_list)
{
    auto begin = vsted_list.begin();
    auto end = vsted_list.end();
    while (begin != end)
    {
        if(*begin == id)
            return true;
        begin++;
    }
    return false;
}

//边及其边权,此处假设边权全为整数
typedef struct line_weight
{
    int weight;
    Node node_out;
    Node node_in;
};

//使用归并算法对数组进行排序
/**
 * @brief 归并算法
 * 
 * @param begin 开始位置
 * @param midduim 中间位置
 * @param end 结束位置
 */
void merge(line_weight* begin,line_weight* midduim,line_weight* end)
{
    vector<line_weight> arr1;
    vector<line_weight> arr2;

    for(int i = 0 ; begin + i < midduim;i++)
    {
        arr1.push_back(*(begin + i));
    }
    
}

/**
 * @brief 将弧按照边权从小到大进行排序
 * 
 * @param arr 要排序的边权数组
 */
void line_sort(line_weight arr[])
{
    
}
