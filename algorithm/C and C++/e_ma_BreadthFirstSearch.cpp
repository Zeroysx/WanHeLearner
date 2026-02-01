/*
题目: 广度优先搜索
最后修订时间：2026/1/23
作者:Wanhe
备注:图的广度优先遍历的样例
*/
//TODO:邻接表的BFS实现
#include <iostream>
#include <queue>
#include "all_algorithm_lib.h"//图的基本定义
using namespace std;

GraphMatrix<char> init()
{
    GraphMatrix<char> graph(6);
    graph.addVertex('A');
    graph.addVertex('B');
    graph.addVertex('C');
    graph.addVertex('D');
    graph.addVertex('E');
    graph.addVertex('F');
    graph.addEdge(0, 1); // A-B
    graph.addEdge(0, 2); // A-C
    graph.addEdge(1, 3); // B-D
    graph.addEdge(1, 4); // B-E
    graph.addEdge(2, 5); // C-F

    return graph;
}
void BFS(GraphMatrix<char> graph)
{
    int n = graph.getVertexCount();
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    queue<int> q;
    q.push(0); // 从顶点0开始遍历
    visited[0] = true;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << graph.getVertex(current) << " ";
        for (int i = 0; i < n; i++) {
            if (graph.isEdge(current, i) && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

using namespace std;
int main()
{
    //初始化
    GraphMatrix<char> graph = init();
    //广度优先搜索
    cout << "Breadth First Search (BFS) starting from vertex A:" << endl;
    BFS(graph);
    cout << endl;
    return 0;
}