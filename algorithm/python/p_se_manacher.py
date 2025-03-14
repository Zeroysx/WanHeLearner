'''
题目：Manacher算法
最后修订时间: 2025/3/14
作者: whsialcx
备注: 用于求解字符串中每个位置的回文半径。此算法具有较高的时间效率，为O(n)。
'''
def Manacher (number):
    n = len(number)
    number_r = [0] * n
    # right 表示当前已知回文的最右边位置
    right = 0
    # max_node 记录回文中心的索引
    max_node = 0
    for i in range(n):
        # 对称位置
        sy = 2 * max_node - i
        # 如果 i 处于已知回文的范围内
        if i < right:
            number_r[i] = min(number_r[sy], right - i)
        while i - number_r[i] >= 0 and i + number_r[i] < n and number[i - number_r[i]] == number[i + number_r[i]]:
            number_r[i] += 1
        if i + number_r[i] > right:
            right = i + number_r[i]
            max_node = i
    return number_r
sum = 'ddaabkbaaabk'
n = Manacher(sum)
print('\n')
for i in range(len(sum)):
    print(n[i])