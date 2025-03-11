/*
插入排序
最后修订时间：2024/2/14
作者:Wanhe
*/

/*
*@return void
*@param A 要处理的数组
*@param length 数组的长度
*@note 插入排序,此算法将数组从小到大排列
*/
template <typename T> 
void insertionSort(T A[],int length)
{
    for( int j = 1; j < length; j++)
    {
        int key = A[j];
        int i = j - 1;
        //比较并插入key
        while ( i >= 0 && A[i] > key)
        {
            A[i+1] = A[i];
            i--;
        } 
        A[i+1] = key;    
    }
}

