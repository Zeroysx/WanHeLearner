/*
题目:生成树算法
最后修订时间：2024/6/23
作者:Wanhe
备注:Kruskal算法和Prim算法,初始图用邻接矩阵表示

*/

#include "all_algorithm_lib.h"
#include <vector>
using std::vector;
// 定义一个极大数
const int INF = 2147483647;

// Kruskal算法（克鲁斯卡尔算法)
/*
基本思路：
将不同的弧按边权的大小从小到大排序，从小到大开始连接各个端点
*/
// 用邻接表表示树
typedef struct Node
{
    float weight;  // 边权
    HeadNode *ptr; // 指向子节点的指针
    Node *next;    // 指向下一个
};

typedef struct HeadNode
{
    char val;
    Node *son;
};
typedef struct Triplets
{
    int x = -1;
    int y = -1;
    int weight = -1;
    Triplets *next = nullptr;
};

/**
 * @brief Kruskal算法
 *
 * @param arr_val 图的节点的值的数组
 * @param n 图的总节点数
 * @param weight_list 权值表
 * @param ret 返回的最小生成树的首地址
 * @return true 构造成功
 * @return false 构造失败
 */
bool kruskal(char arr_val[], int n, float *weight_list, HeadNode *ret)
{
    HeadNode head;
    int visited[n] = {0};
    // 遍历排序所有的边
    int m, n;
    int min = INF;
    Triplets *head_tab = new Triplets;
    Triplets *pNode = new Triplets;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (weight_list[i * n + j] != -1)
            {
                if (head_tab->weight == -1)
                {
                    head_tab->x = j;
                    head_tab->y = i;
                    head_tab->weight = weight_list[i * n + j];
                }

                pNode->next = head_tab;
                while (pNode->next->weight < weight_list[i * n + j])
                {
                    if(pNode->next == nullptr)
                        break;
                  pNode->next = pNode->next->next; 
                }
                 if (pNode->next == head_tab)
                    {
                        pNode->x = j;
                        pNode->y = i;
                        pNode->weight = weight_list[i * n + j];
                        head_tab = pNode;
                    }
                    else if(pNode->next == nullptr)
                    {
                        pNode->next = new Triplets;
                        pNode->next->x = j;
                        pNode->next->y = i;
                        pNode->weight = weight_list[i*n + j];
                        
                    }
                    else
                    {
                    Triplets* node = new Triplets;
                    node->x = j;
                    node->y = i;
                    node->weight = weight_list[i * n + j];
                    node->next = pNode->next;
                    pNode->next = node;
                    }
                    
            }
        }
    }
}
