"""
题目：Kruskal算法实现最小生成树
最后修订时间: 2025/03/12
作者: whsialcx
备注: 该程序使用并查集（Union-Find）数据结构实现Kruskal算法，解决最小生成树（MST）问题。
程序将给定的图作为输入，输出最小生成树的边及其权重，总节点数和边数。
"""

class UnionFind:#并查集结构，时间复杂度始终为O(1)
    def __init__(self):#建立一个类似图的结构，此结构是一个向上的图，即第一个元素作为代表节点
        self.parent = {}
        self.rank = {}
    def find(self, u):#find方法，寻找节点的代表节点
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u])  # 路径压缩
        return self.parent[u]
    def union(self, u, v):#合并集合，将规模小的代表节点连接到规模大的代表节点下
        root_u = self.find(u)
        root_v = self.find(v)
        if root_u != root_v:
            if self.rank[root_u] > self.rank[root_v]:
                self.parent[root_v] = root_u#将小的集合删除
            elif self.rank[root_u] < self.rank[root_v]:
                self.parent[root_u] = root_v
            else:
                self.parent[root_v] = root_u
                self.rank[root_u] += 1
    def add(self, u):#初始化，每一个节点刚开始都是自己的代表节点
        if u not in self.parent:
            self.parent[u] = u
            self.rank[u] = 0
def Kruskal(graph):
    sum = 0
    edges = []
    for u in graph:
        for v, weight in graph[u].items():
            edges.append((weight, u, v))
    edges.sort()
    uf = UnionFind()
    mst = []
    for u in graph:
        uf.add(u)
    for weight, u, v in edges:
        if uf.find(u) != uf.find(v):  # 如果不在同一集合
            uf.union(u, v)  # 合并集合
            mst.append((u, v, weight))
            sum += weight
    return mst,sum
graph = {
    'A': {'B': 1, 'C': 10, 'E': 3, 'G': 2, 'I': 6},
    'B': {'A': 1, 'C': 1, 'D': 6, 'E': 4, 'G': 2},
    'C': {'A': 10, 'B': 1, 'D': 3, 'H': 3},
    'D': {'B': 1, 'C': 3},
    'E': {'A': 3, 'B': 4, 'F': 3, 'G': 1, 'J': 1},
    'F': {'E': 3, 'D': 6, 'I': 1, 'J': 2},
    'G': {'A': 2, 'B': 2, 'E': 1, 'H': 2, 'J': 2},
    'H': {'G': 2, 'C': 3, 'I': 3, 'J': 1},
    'I': {'H': 3, 'A': 6, 'F': 1},
    'J': {'G': 2, 'E': 1, 'F': 2}
}
mst ,sum = Kruskal(graph)
num_nodes = len(graph)
num_edges = len(mst)
print("最小生成树的边：")
for u, v, weight in mst:
    print(f"{u} - {v}: {weight}")
print("节点个数：",end = " ")
print(num_nodes)
print("边的个数：",end = " ")
print(num_edges)
print("总权重",end = " ")
print(sum)
