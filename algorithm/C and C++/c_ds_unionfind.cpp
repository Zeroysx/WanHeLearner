#include<bits/stdc++.h>
using namespace std;
/*
题目：并查集（Union-Find）算法实现
最后修订时间:2025/4/24
作者: whsialcx
备注: 实现并查集（Union-Find）数据结构，包含路径压缩与按秩合并优化。
此算法用于高效的集合合并与查找操作，适用于动态连通性问题。
*/

template <typename T>
class Event
{
public:
    T value;
    Event(T val) : value(val) {}
};

template <typename T>
class Event
{
public:
    T value;
    Event(T val) : value(val) {}
};

template <typename T>
class UnionFind
{
public:
    unordered_map<T, Event<T>*> valuemap;
    unordered_map<Event<T>*, Event<T>*> parentmap;
    unordered_map<Event<T>*, int> sizemap;
    // 构造函数
    UnionFind(vector<T> value)
    {
        for (T val : value)
        {
            Event<T>* node = new Event<T>(val);
            valuemap[val] = node;
            parentmap[node] = node;
            sizemap[node] = 1;
        }
    }
    // 析构函数，释放内存
    ~UnionFind()
    {
        for (auto& entry : valuemap)
        {
            delete entry.second;  // 删除动态分配的 Event 对象
        }
    }
    // 查找父节点并进行路径压缩
    Event<T>* findparent(Event<T>* a)
    {
        stack<Event<T>*> path;
        while (a != parentmap[a])
        {
            path.push(a);
            a = parentmap[a];
        }
        // 路径压缩
        while (!path.empty())
        {
            parentmap[path.top()] = a;
            path.pop();
        }
        return a;
    }
    // 判断两个元素是否在同一个集合
    bool issameset(T a, T b)
    {
        if (valuemap.find(a) != valuemap.end() && valuemap.find(b) != valuemap.end())
        {
            Event<T>* af = findparent(valuemap[a]);
            Event<T>* bf = findparent(valuemap[b]);
            return af == bf;
        }
        return false;
    }
    // 合并两个集合
    void unionset(T a, T b)
    {
        if (valuemap.find(a) != valuemap.end() && valuemap.find(b) != valuemap.end())
        {
            Event<T>* af = findparent(valuemap[a]);
            Event<T>* bf = findparent(valuemap[b]);
            if (af != bf)
            {
                Event<T>* big = sizemap[af] >= sizemap[bf] ? af : bf;
                Event<T>* small = big == af ? bf : af;
                int sum = sizemap[big] + sizemap[small];
                sizemap[big] = sum;
                sizemap.erase(small);
                parentmap[small] = big;
            }
        }
    }
};