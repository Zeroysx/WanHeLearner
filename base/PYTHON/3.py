'''
3、判断一个整数是否为素数
2024/10/11
'''
import math

n = input("Input an integer:");
n = int(n);
m = math.ceil(math.sqrt(n) + 1);
for i in range(2,m):
    if n % i == 0 and i < n:
        print("No");
        break;
else:
    print("Yes");