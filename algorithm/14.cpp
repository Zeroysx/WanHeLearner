/*
题目:BF算法
最后修订时间：2024/3/29
作者：Wanhe
备注:Brute-Force算法也称简单匹配算法，采用穷举法查找目标字符串
*/


/**
 * @brief BF算法
 * @param str1 要查找的字符串的首地址
 * @param str2 目标查找片段
 * @param length1 要查找的数组的长度
 * @param length2 目标查找片段长度
 * @param Pos 查找位置的偏置
*/
bool BruteForceSearch(char *str1,char *str2 ,int length1,int length2,int Pos)
{
    char *p1,*p2;
    p1 = str1;
    p2 = str2;
    int tag = 0;
    for(int i = 0;i < length1;i++)
    {
      for(int j = 0; j < length2 && tag == 1;j++)
      {
        if(*(p1 + j) !=*(p2 + j))
        {
            
        }
      }
        
    }
    
}

