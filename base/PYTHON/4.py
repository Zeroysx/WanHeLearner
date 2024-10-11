'''
4、树池有1、2、3、4四个数字组成的没位数都不相同的所有三位数
2024/10/11
'''
digits = (1,2,3,4);
for i in digits:
    for j in digits:
        for k in digits:
            if i != j and j != k and i != k:
                print(i*100 + j * 10 + k );