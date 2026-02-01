#ifndef WANHE_LIB
#define WANHE_LIB
#include <iostream>
//本库集中了本代码仓中适合复用的代码以供使用
namespace wanhe
{
/*
归并算法
最后修订时间:2024/2/18
作者:Wanhe
*/
//结尾标识常量,取极大值
const int FLAG=2147483647;
//形式1：内部排序,指针型
/*
*@brief 归并算法，此函数将在一个数组中[p1...p2]内有序与[p2,p3]内有序的部分进行排序.
*@return void
*@param p1 指向第一个有序部分的开头的指针
*@param p2 指向第一个有序部分的结尾，同时也是第二个有序部分的开头的指针
*@param p3 指向第二个有序部分的结尾的指针
*@note 该函数三个指针需指向同一个数组。
*/
// //结尾标识常量,取极大值
// const int FLAG=2147483647;
//归并算法
template <typename T>
void merge(T *p1,T *p2 ,T *p3)
{
    T *arr1 = new T;
    T *arr2 = new T;
    //将两个区间内的值复制
    int i = 0;
    for(; p1 + i <= p2 ; i++)
        *(arr1+i) = *(p1 + i);
    *(arr1+i) =  FLAG;
    for(i = 1; p2 + i <= p3 ; i++)
        *(arr2+i-1) = *(p2 + i);
    *(arr2+i-1) = FLAG;
    for(int i = 0,j = 0;p1 <= p3 ;p1++)
    {
        if(arr1[i] <= arr2[j])
          {
            *p1 = arr1[i];
            i++;
        }
        else 
        {
            *p1 = arr2[j];
            j++;
        }
    } 
}
// 归并方法二：
template <typename T>
void merge2(T array,int p ,int t  ,int r)
{
    T arr1[t - p + 2];
    T arr2[r - t + 1];
    //复制数组
    for(int i = 0;i <t - p + 1;i++)
        arr1[i] = array[p+i];
    arr1[t - p + 1] =FLAG;
    for(int i = 0;i < r - t;i++)
        arr2[i] = array[t + 1 + i];
    arr2[r - t] = FLAG;
    for(int i = 0,j = 0;i + j <r - p + 1;)
    {
        if(arr1[i] <= arr2[j])
        {
            array[i+j] =arr1[i];
            i++;
        }
        else 
        {
            array[i+j] = arr2[j];
            j++;
        }

    }
}
/**
 * @brief 归并排序算法，将同一数组[p...r]范围内的数进行排序
 * @return void
 * @tparam T 
 * @param p 排序开始位置指针
 * @param r 排序结束位置指针
 * @note 本函数采用分治思想，将数组拆分并用归并算法进行排序。
 */
template <typename T>
void mergeSort(T*  p,T* r)
{
    if(p < r)
    {
        T* q = p + (r - p) / 2;
        mergeSort(p,q);
        mergeSort(q + 1, r);
        merge(p,q,r);
    }
}
//归并排序方法2
template <typename T>
void mergeSort2(T* p,T* r)
{
     if(p < r)
    {
        T* q = p + (r - p) / 2;
        mergeSort2(p,q);
        mergeSort2(q + 1, r);
        merge2(p,q,r);
    }
}

}
/*** 计算斐波那契数列的第n项
 * @param n 斐波那契数列的项数
 * @return 第n项的值
 * @note 该函数使用递归方法计算斐波那契数列，时间复杂度较高，适用于较小的n值。
 */
int Fibonacci(int n)
{
    if(n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return Fibonacci(n-1) + Fibonacci(n-2);
}

//图的基本实现

/**
 * @brief 图的邻接矩阵表示
 * @tparam T 图中顶点的数据类型
 */
template <typename T>
class GraphMatrix
{
    private:
        int maxVertices; //最大顶点数
        int numVertices; //当前顶点数
        int numEdges;    //当前边数
        T* vertices;     //顶点数组
        int** adjMatrix; //邻接矩阵
    public:
        //构造函数
        GraphMatrix(int maxV);
        //折构函数
        ~GraphMatrix();
        //添加顶点
        void addVertex(T vertex);
        //添加边
        void addEdge(int src, int dest, int weight = 1);
        //打印邻接矩阵
        void printMatrix();
        //获取顶点数量
        int getVertexCount() { return numVertices; }
        //获取顶点数据
        T getVertex(int index) { return vertices[index]; }
        //判断两个顶点之间是否有边
        bool isEdge(int src, int dest) { return adjMatrix[src][dest] != 0; }

};
template <typename T>
GraphMatrix<T>::GraphMatrix(int maxV)
{
    maxVertices = maxV;
    numVertices = 0;
    numEdges = 0;
    vertices = new T[maxVertices];
    adjMatrix = new int*[maxVertices];
    for(int i = 0; i < maxVertices; i++)
    {
        adjMatrix[i] = new int[maxVertices];
        for(int j = 0; j < maxVertices; j++)
        {
            adjMatrix[i][j] = 0; //初始化为无边
        }
    }
}
template <typename T>
GraphMatrix<T>::~GraphMatrix()
{
    delete[] vertices;
    for(int i = 0; i < maxVertices; i++)
    {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}
template <typename T>
void GraphMatrix<T>::addVertex(T vertex)
{
    if(numVertices < maxVertices)
    {
        vertices[numVertices++] = vertex;
    }
}

template <typename T>
void GraphMatrix<T>::addEdge(int src, int dest, int weight)
{
    if(src >= 0 && src < numVertices && dest >= 0 && dest < numVertices)
    {
        adjMatrix[src][dest] = weight;
        adjMatrix[dest][src] = weight; //无向图
        numEdges++;
    }
}

template <typename T>
void GraphMatrix<T>::printMatrix()
{
    for(int i = 0; i < numVertices; i++)
    {
        for(int j = 0; j < numVertices; j++)
        {
            std::cout << adjMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

/** @brief 图的邻接表表示
 * @tparam T 图中顶点的数据类型
 */
template <typename T>
class GraphList
{
    private:
        struct Node
        {
            int dest;
            int weight;
            Node* next;
        };
        struct Vertex
        {
            T data;
            Node* head;
        };
        int maxVertices;
        int numVertices;
        int numEdges;
        Vertex* vertices;
    public:
        GraphList(int maxV);
        ~GraphList();
        void addVertex(T vertex);
        void addEdge(int src, int dest, int weight = 1);
        void printList();
};

template <typename T>
GraphList<T>::GraphList(int maxV)
{
    maxVertices = maxV;
    numVertices = 0;
    numEdges = 0;
    vertices = new Vertex[maxVertices];
    for(int i = 0; i < maxVertices; i++)
    {
        vertices[i].head = nullptr;
    }
}

template <typename T>
GraphList<T>::~GraphList()
{
    for(int i = 0; i < numVertices; i++)
    {
        Node* current = vertices[i].head;
        while(current)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] vertices;
}

template <typename T>
void GraphList<T>::addVertex(T vertex)
{
    if(numVertices < maxVertices)
    {
        vertices[numVertices++].data = vertex;
    }
}

template <typename T>
void GraphList<T>::addEdge(int src, int dest, int weight)
{
    if(src >= 0 && src < numVertices && dest >= 0 && dest < numVertices)
    {
        Node* newNode = new Node{dest, weight, vertices[src].head};
        vertices[src].head = newNode;
        //无向图
        newNode = new Node{src, weight, vertices[dest].head};
        vertices[dest].head = newNode;
        numEdges++;
    }
}

template <typename T>
void GraphList<T>::printList()
{
    for(int i = 0; i < numVertices; i++)
    {
        std::cout << vertices[i].data << ": ";
        Node* current = vertices[i].head;
        while(current)
        {
            std::cout << "-> (" << current->dest << ", " << current->weight << ") ";
            current = current->next;
        }
        std::cout << std::endl;
    }
}
#endif