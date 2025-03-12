"""
题目：KMP字符串匹配算法
最后修订时间:2025/3/12
作者: whsialcx
备注: 该算法实现了KMP算法，用于在字符串str1中查找子串str2的位置。
      KMP算法通过使用前缀数组(next数组)来避免重复匹配，提高匹配效率。
      若找到匹配子串，则返回子串在父串中的起始位置，否则返回-1。
      本程序用于演示KMP算法的实现和应用。
"""
def Kmp(str1,str2):#从str1中寻找str2，返回str1的开始值
    if str1 is None or str2 is None or len(str2) < 1 or len(str1) < 1:
        return -1
    i1 = 0
    i2 = 0
    next = nextget(str2)
    while i1 < len(str1) and i2 < len(str2):
        if str1[i1] == str2[i2]:
            i1 += 1
            i2 += 1
        elif i2 == 0 or next[i2] == -1:
            i1 += 1
        else:
            i2 = next[i2]
    if i2 == len(str2):#i2越级了，表示str1中找到了匹配的字符串
        return i1 - i2
    else:
        return -1
#..................i - 1,i。此时要求i位置的next[i]，n是第i - 1位置的最长前后缀的长度，比较next[n]和str[i]的值
#如果相等，则next[i]就是n + 1 ；  如果不相等就去比较next[next[n]]和str[i]的值，直到相等或者n为0，
def nextget(str):#最长相等前缀和后缀，不算上自身
    next = [0] * len(str)
    next[0] = -1
    next[1] = 0
    n = 0#n既是前一个位置的最长相等前后缀的值，也是后一个位置将要比较的位置的下标
    i = 2#i从下标为2的位置开始
    while i < len(str):
        if str[i] == str[next[i - 1]] or str[i] == next[n]:#str[i] == next[n]
            n += 1
            next[i] = n
            i += 1
        elif n > 0 or next[n] > -1:
            n = next[n]#关键***
        else:
            next[i] = 0
            i += 1
    return next
str1 = 'abcstkwascbaabbabbstkscabbstkzabcde'
str2 = 'abbstkscabbstkz'
print(Kmp(str1,str2))