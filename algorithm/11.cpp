/*
归并排序算法
最后修订时间:2024/2/16
作者:Wanhe
Tips:分治思想典型案例
此算法需要用到10.cpp中的算法
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
