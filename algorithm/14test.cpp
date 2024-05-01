/*
题目:BF算法
最后修订时间：2024/5/1
作者：Wanhe
备注:Brute-Force算法也称简单匹配算法，采用穷举法查找目标字符串
未完成
*/
/**
 * @brief BF算法
 * @param str1 要查找的字符串的首地址
 * @param str2 目标查找片段
 * @param length1 要查找的数组的长度
 * @param length2 目标查找片段长度
 * @param Pos 查找位置的偏置
 */
bool BruteForceSearch(char *str1, char *str2, int length1, int length2, int Pos)
{
  char *p1, *p2;   // 指向两个字符串的指针
  p1 = str1 + Pos; // p1赋值首地址+偏置
  p2 = str2;
  int tag = 0; // 是否相同标志
  // 遍历str1
  for (int i = 0; i < length1; i++)
  {
    // 从p1位置开始与str2对比
    for (int j = 0; j < length2 && tag == 0; j++)
    {
      if (*(p1 + j) == *(p2 + j))
      {
      }
      else
      {
        tag = 1;
        break;
      }
    }
    if (tag == 1)
    {
      p1++;
      tag = 0;
    }
    else
    {
      return true;
    }
  }
  return false;
}

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
  // 原字符串
  cout << "Please input a string less than 25 letters." << endl;
  char str[25];
  int i = 0;
  char c;
  c = cin.get();
  while (c != '\n')
  {
    if (i < 25)
    {
      str[i] = c;
      i++;
    }
    else
    {
      cout << "space full" << endl;
      break;
    }
    c = cin.get();
  }
  // 查找字符串
  cout << "Please input a string you want to search,but it must less than " << i << " letters" << endl;
  char str2[25];
  int j = 0;
  c = cin.get();
  for (; c != '\n'; j++)
  {
    if (i < 25)
      str2[j] = c;
    else
    {
      cout << "space full" << endl;
      break;
    }
    c = cin.get();
  }
  // 查找对比
  if (BruteForceSearch(str, str2, i, j, 0))
  {
    cout << "Found." << endl;
  }
  else
    cout << "No found." << endl;
}