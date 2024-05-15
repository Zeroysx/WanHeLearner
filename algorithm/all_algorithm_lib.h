#ifndef WANHE_LIB
#define WANHE_LIB
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
//结尾标识常量,取极大值
const int FLAG=2147483647;
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




#endif