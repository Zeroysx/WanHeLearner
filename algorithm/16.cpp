/*
题目:最大子数组问题
最后修订时间：2024/5/1
作者:Wanhe
备注:未完成
问题描述：一个含有含符号数的数组，求其中拥有最大和的最大子数组
*/
// 定义一个极大数
const int MAX_NUM = 2147483647;
const int MIN_NUM = -MAX_NUM;
/*分治法*/
/**
 * @brief 函数返回的数据结构
 *
 */
typedef struct RetData
{
    int left;
    int right;
    double sum;
};
/**
 * @brief 求最大子数组区间并返回最大子数组中值的合
 *
 * @param array 原数组
 * @param low 查找区间的左端下标
 * @param mid 查找区间的中间下标
 * @param high 查找区间的右侧下标
 * @return RetData 返回一个RetData型的数据，left为最大子数组的做下标，right为最大子数组的右下标，sum为数组中值的和
 */
RetData FindMaxCrossingSubarray(double array[], int low, int mid, int high)
{
    double left_sum = MIN_NUM;
}
