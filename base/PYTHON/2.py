# 求水仙花数
for i in range(10**2,10**3):
    bai,shi,ge = map(int,str(i));
    if bai**3 + shi**3 +ge**3 == i:
        print(i);