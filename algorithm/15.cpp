/*
题目:生成树算法
最后修订时间：2024/4/2
作者:Wanhe
备注:穷举法获取节点的生成树
*/

// 节点
typedef struct 
{
    int id;//节点编号
    bool ifuse;//节点是否被访问
}Node;
//图,此时假设为矩阵图
class Map
{
private:
    //长
    int m;
    //宽
    int n;
    //图的解决方案
    typedef struct Solution
    {
        int * array;
        static int number_of_solution;
    };
    
    
    
public:
    Map(/* args */);
    ~Map();
};

Map::Map(/* args */)
{
}

Map::~Map()
{
}

