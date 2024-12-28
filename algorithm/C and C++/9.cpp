/*
冒泡排序
最后修订时间:2024/2/15
作者:Wanhe
*/

/*
*@return void
*@param array 要排序的数组
*@param length 数组的长度
*@note 冒泡排序，此函数将数组按从大到小排序
*/
template <typename T>
void bubbleSort(T array,int length)
{
    for(int i = 0; i < length ;i++)
    {
        for(int j = 0 ; j < length - 1 ; j++)
        {
            if(array[j] < array[j+1])
            {
                int t = array[j];
                array[j] = array[j+1];
                array[j+1] = t;
            }
        }
    }
}