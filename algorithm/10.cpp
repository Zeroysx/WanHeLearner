/*
归并排序
最后修订时间:2024/2/15
作者:Wanhe
*/
//结尾标识常量
const int FLAG=-1;
//形式1：内部排序,指针型
/*
*@return void
*@param array 要排序的数组
*@param p1 指向第一个有序部分的开头的指针
*@param p2 指向第一个有序部分的结尾，同时也是第二个有序部分的开头的指针
*@param p3 指向第二个有序部分的结尾的指针
*@note 归并排序，此函数将在一个数组中[p1...p2]内有序与[p2,p3]内有序的部分进行排序.
*@note 注意此函数仅支持正数排序，数组含负数请修改FLAG的值
*未完成
*/
template <typename T>
void mergeSort(T array,T *p1,T *p2 ,T *p3)
{
    T *arr1 = new T;
    T *arr2 = new T;
    //将两个区间内的值复制
    int i = 0
    for(; p1 + i < p2 ; i++)
        *(arr1+i) = p1 + i;
    *(arr1+i) =  
    for(int i = 1; p2 + i < p3 ; i++)
        *(arr2+i) = p1 + i; 
    

}