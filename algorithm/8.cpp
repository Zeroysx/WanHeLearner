/*
选择排序
最后修订时间;2024/2/14
作者:Wanhe
*/

/*
*@return  void
*@param A 要处理的数组
*@param length 数组的长度
*@note 选择排序,此算法将数组从大到小排列
*/
template <typename T>
void selectSort(T array[],int length)
{
    for(int i=0;i < length;i++)
    {
        T t=array[i];
        T *max=array[i];
        for(int j = i+1; j < length ; j++)
            if(*max < array[j])
                max = &array[j];
        array[i] = *max;
        *max = t; 
    }
}