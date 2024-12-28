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

//方法二:
/**
 * @brief 参数为数组下标的归并法
 * 
 * @tparam T 
 * @param array 要排序的数组
 * @param p 排序部分开始位置下标
 * @param t 排序部分中间下标
 * @param r 排序部分结尾下标
 */
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