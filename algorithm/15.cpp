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

/***********************************************************/
                        /*算法说明*/
/**
 * 生成树算法是用于解决在一个图中构建树（即不包含回路的连接）的算法。
 * 首先我们需要认识到：一个完全图的生成树必然包含所有节点，非完全图则不然。因此算法结束的条件应包含两类：
 * 1、所有节点均已加入树中。
 * 2、生成树与图中剩余节点已无可用连接。
 * 起点不同的情况下，同一张图的生成树可能不同。
 * 可以用邻接表或邻接矩阵存储图的信息。
 * C/C++风格邻接表和邻接矩阵的设计见base目录下的对应目录
 */

