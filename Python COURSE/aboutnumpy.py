import numpy as np
import numpy.linalg  # 矩阵相关需要模块

print("1.\n")
a = [[1, 2, 3, 4, 5], [6, 7, 8, 9, 10]]
b = np.array(a)
print(b)
print(b.ndim)
print(b.shape)
print(b.size)
print(b.dtype)  # 数组中出现一个float就会全部转化为float
print(b.itemsize)
print("-" * 30)

print("2.\n")
c = np.arange(1, 11, 1)
print(c)
print("-" * 30)

print("3.\n")
d = np.ones((5, 5), dtype="float")
print(d)
print("-" * 30)

print("4.\n")
e = np.eye(5)
print(e)
print("-" * 30)

print("5.\n")
f = np.full((5, 5), 7)
print(f)
print("-" * 30)

print("6.\n")
g = np.empty((5, 5), int)
print(g)
print("-" * 30)

print("7.\n")
h = np.ones_like(a)  # 顾名思义生成一个形状和a一样的全1数组，此外还有zeros_liike,full_like
print(h)
print("-" * 30)

print("8.\n")
i = np.linspace(1, 10, num=10, endpoint=True)  # flase为不包括结束值
print(i)
print("-" * 30)

print("9.\n")
j = np.random.rand(2, 2,
                   3)  # 参数中的数字的定义是，从后往前来看，以此为例子，表示三个数一组，一共两组，而这两组组成的一个组又有两组
print(j)
print("-" * 30)

print("10.\n")
k = np.random.randn(2, 2, 3)  # 定义与上面的一样，只不过是标准正态分布的数
print(k)
print("-" * 30)

print("11.\n")
l2 = np.random.randint(1, 12, size=(5, 5))  # size是形状，数是1-12，不包括12之间
print(l2)
print("-" * 30)

print("12.\n")
# np.random.normal(loc,scale,size)生成size个服从正态分布的随机数N~（loc,scale)
# 和正常列表一样的索引与切片

print("13.\n")
# 逻辑索引：遵从[行，列]的索引（多维情况下）
print(b)
print("-" * 30)
print(b[1, 3])
print("-" * 30)
print(b[1, :])  # 取第一行
print("-" * 30)
print(b[:, 3])  # 取第四列
print("-" * 30)
print(b[0:2, 1:3])  # 取第一道第二行，第二到第三列
print("-" * 30)
print(b[:, b[0, :] > 4])  # 取第一行大于4的所有列
print("-" * 30)
print(b[b[:, 0] > 4, :])  #
print("-" * 30)

print("14.\n")
m = b.reshape(5, 2)  # 不改变原来数组元素，返回一个新形状的数组，前后两数组元素必须一样
print(m)
print("-" * 30)

print("15.\n")
m.resize(2, 5)  # 与上面一样，但会改变原数组，新数组可大于原始大小，包含原来数组的副本
print(m)
print("-" * 30)

print("16.\n")
m = m.flatten()  # 降维成一维
print(m)
print("-" * 30)

print("17.\n")
m = m.tolist()  # 将数组转换成列表
print(m, type(m))
print("-" * 30)

print("18.\n")
m = np.array(m)
m = m.astype(float)  # 转换成新类型
print(m)
print("-" * 30)

print("19.\n")
print(b)
n = np.stack([b, b, b], axis=-1, out=None)  # 将多个形状一样的进行堆叠,会生成新维度
print(
    n
)  # 解释：如果axis参数为0，则将数组进行竖向堆叠（纵向串糖葫芦），axis=1时为水平操作，aixs=-1时为三维堆叠（理解为向电脑屏幕外堆叠?）
print("-" * 30)

print("20.\n")
o = np.hstack([c, c])  # 横向串糖葫芦
print(o)
print("-" * 30)

print("21.\n")  # 拼接
p = np.concatenate([b, b, b], axis=1)
print(p)
print("-" * 30)

# 数组的拼接删除
# 删除delete即可，修改直接复制

print("22.\n")
# where用法
q = np.where(b > 5, 2, 0)  # 满足条件输出2，不满足输出0（针对b数组中每个元素而言）
print(q)
q = b[np.where(b > 3)]  # 输出的是索引,当然此处又用了b取下标，输出的是元素
print(q)
print("-" * 30)

print("23.\n")
# 数组与标量的运算是按元素来的，所以有正常的计算就行
# "+"
r = np.add(p, p)
print(r)
print("-" * 30)

# "-"
s = np.subtract(p, p)
print(s)
print("-" * 30)

t = np.multiply(p, p)
print(t)
print("-" * 30)

# like "y=np.ways(x,y)"
# "/"=divide
# "//"=floor_divide
# "-"=negative
# "**"=power
# "%"=remainder...
# "=="=equal
# "!="=not_equal
# "<"=less
# "<="=less_equal
# ">"=greater
# ">="greater_equal
#  np.abs(x)计算元素的绝对值
#  np.sqrt(x)计算每个元素的平方根
#  np.square(x)计算每个元素的平方
#  np.ceil(x)计算大于等于每个元素的最小值
#  np.floor(x)计算小于等于每个元素的最大值
#  np.exp(x[,out])计算每个元素的指数值
#  np.log(x)计算自然对数
#  np.log10(x) 计算底为10的对数
#  np.log2(x) 计算底为2的对数

# 矩阵相关：
A = np.array([[1, 1, 1], [0, 2, 5], [2, 5, -1]])
B = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
X = np.array([6, -4, 27])
# 相乘
C = np.dot(A, B)
print(C)
print("-" * 30)

# 逆矩阵
D = numpy.linalg.inv(A)
print(A)
print("-" * 30)

# 解决线性方程组
ans = numpy.linalg.solve(A, X)
print(ans)
print("-" * 30)

# 求特征值,特征向量,eig方法不太懂用法
E = numpy.linalg.eigvals(A)
print(E)
F = numpy.linalg.eigvalsh(A)
print(F)
print("-" * 30)

# svd 奇异值分解（不理解

# 求行列式
G = numpy.linalg.det(A)
print(G)
print("-" * 30)
