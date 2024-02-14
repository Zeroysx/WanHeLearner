/*
插入排序

*/
//此算法将数组从小到大排列
template <typename T> 
void insertionSort(T[])
{
    for( int j = 1; j < sizeof(T);j++)
    {
        int key = T[j];
        int i = j - 1;
        //比较并插入key
        while ( i >= 0 && T[i] > key)
        {
            T[i+1] = T[i];
            i--;
        }
        A[i+1] = key;    
    }
}

