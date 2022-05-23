import numpy as np

a = [[1, 2, 3, 4, 5], [0.6, 0.07, 0.08, 0.09, 0.16]]
b = [[16, 17, 18, 19, 20], [11, 12, 13, 14, 15]]
a = np.array(a)
b = np.array(b)
print(a)
print(b)
print("-" * 30)

# sum(a,axis=None)
x = np.sum(a, 0)  # 0代表竖向算和
print(x)
y = np.sum(b, 1)  # 1为横向算和
print(y)
print("-" * 30)

# mean(a，axis=none),沿轴的元素的总和除以元素的数量
z = np.mean(a, 0)  # 竖向求和算期望
print(z)
c = np.mean(a, 1)  # 横向求和算期望
print(c)
print("-" * 30)

# average(a,axis=None,weith=None)平均值，
d = np.average(a, 0)
print(d)
e = np.average(b, 1)
print(e)
print("-" * 30)

# std(a,axis=none)#标准差
f = np.std(a, 0)
print(f)
g = np.std(b, 1)
print(g)
print("-" * 30)

# var(a,axis=None)#方差
h = np.var(a, 0)
print(h)
i = np.var(b, 1)
print(i)
print("-" * 30)

# 上述方法的个人理解：
'''
将数组理解成中学的统计图表，对应以上各种方法
axis参数则对应不同的轴参数，不做限制时是对所有的数组元素的方法
'''

# min(a),max(a)计算数组a中元素的最小值、最大值
# argmin(a),argmax(a)计算数组a中元素的最小值、最大值的降一维后下标
# unravel_index(index,shape)根据shape将一维下标index转换成多维下标
# ptp(a)计算数组a中元素最大值与最小值的差
# meadian(a)计算数组a中元素的中位数(中值)

# np.sort(a,axis)返回排序新数组
j = np.sort(a, 0)  # 按照列排，表现为最小的为左上角（二位情况）
print(j)
k = np.sort(b, 1)  # 按行排，各行自行排，左边为最小
print(k)
print("-" * 30)

l1 = np.argsort(a)  # np.argsort()返回升序排序后的索引值,一般默认是从小到大排序，但用此方法可以用[::-1]来进行逆向排序
print(l1)
print("-" * 30)
