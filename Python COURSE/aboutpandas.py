import numpy as np
import pandas as pd
""" series：带标签的一维同类型数据的数组。是一种key-value型数据结构 """
data = {'A': 1, 'B': 2, 'C': 3, 'D': 4}
data1 = ['A', 'B', 'C', 'D']
data2 = np.array([1, 2, 3, 4])
index1 = ['a', 'b', 'c', 'd']

print("通过一维数组或序列创建Series:\n")

s = pd.Series(data, index=list('ABCD'))
print("s = pd.Series(data, index=list('ABCD'))")
print(s)
print('*' * 30)
s1 = pd.Series(data2, index1)
print("s1 = pd.Series(data1, index1)")
print(s1)
print('*' * 30)
print("\n" * 3)
print("通过字典的方式创建Series")
s2 = pd.Series(data1)
print("s2 = pd.Series(data1)")
print(s2)
print('*' * 30)
print("\n" * 3)
print("查看索引:  series.index\n查看值:   series.values ")
print("s.index:")
print(s.index)
print("s.values:")
print(s.values)
print('*' * 30)
print("\n" * 3)
print("切片")
print("通过标签进行切片:")
s3 = s1['a':'c']
print("s3 = s1['a':'c'],结果包含标签1和标签2")
print(s3)
s4 = s1[0:3]
print("通过位置进行切片")
print("s4 = s1[0:3],结果不包括结尾的位置")
print(s4)
print('*' * 30)
print("\n" * 3)

print(" DataFrame——带标签且大小可变的二维表格结构 ")
datax = np.random.randint(1, 12, size=(5, 5))
print("datax:")
print(datax)
indexx = ('a', 'b', 'c', 'd', 'e')
print("indexx:")
print(indexx)
columns = ['A', 'B', 'C', 'D', 'E']
print("columns:")
print(columns)
s5 = pd.DataFrame(datax, indexx, columns)
print("s5 = pd.DataFrame(datax, indexx, columns)")
print(s5)
print("访问：单独一行：s5.loc[行名],多行:s5.loc[[行名1,行名2]],列的话相同但不用loc方法")
print('*' * 30)
print("\n" * 3)

print("DataFrame常用属性")
print("s5:")
print(s5)
print("索引:index:s.index")
print(s5.index)
print("列名:columns:s.columns")
print(s5.columns)
print("元素:values:s.values")
print(s5.values)
print("类型:dtypes:s.dtypes")
print(s5.dtypes)
print("元素个数:size:s.size")
print(s5.size)
print("维度数:ndim:s.ndim")
print(s5.ndim)
print("数据形状（行列数目）:shape:s.shape")
print(s5.shape)
print('*' * 30)
print("\n" * 3)

print("查看DataFrame常用方法")
print("df.head(n)	读取开始n行数据，默认n=5")
print(s5.head(3))
print("df.tail()	读取最后n行数据，默认n=5")
print(s5.tail(3))
print("df.info()	df的简要说明（如索引、列数、列名、数据量、数据类型、缺失值、内存等）")
print(s5.info())
print("df.describe() ")
""" 对于数字列，describe() 返回基本统计信息：列中数据的值计数，平均值，标准差，最小值，最大值以及第 25，  """
""" 第 50和第75的中位数；对于字符串列，describe() 返回值计数， """
""" 唯一条目数，最常出现的值(top value) 以及最高值出现的次数(freq) """
print(s5.describe())
print('*' * 30)
print("\n" * 3)

print("数据抽取")
print("s5:")
print(s5)
print("抽取1行")
print(s5.iloc[0])
print(s5.loc['a'])
print("抽取1列")
print(s5.loc[:, 'A'])
print(s5.iloc[:, 0])
print(s5['A'])
print("抽取多行多列")
print(s5.iloc[1:3, 0:2])
""" 按照loc抽取时:s5.loc[[行名1,行名2]][[列名1,列名2]] """
""" 总结就是，iloc时按照numpy的下标索引访问，loc方法有对应的双中括号方法 """
print("按指定条件抽取,类比numpy的逻辑索引")
print("列标A大于6的所有行")
print(s5.loc[s5['A'] > 6])
print('*' * 30)
print("\n" * 3)

print("数据的增")
print("s5:")
print(s5)
print("按列增加数据:")
print("直接赋值")
s5['F'] = [5, 6, 7, 2, 3]
print(s5)
print("使用loc属性在DataFrame对象的最后增加一列")
s5.loc[:, 'G'] = (250, 520, 1314, 456, 333)
print(s5)
print("在指定位置插入一列:df.insert(columns,’列名’,数值)")
s5.insert(len(s5.columns), 'H', [789, 456, 123, 357, 159])
print(s5)
print('*' * 30)
print("按行增加数据")
print("使用loc属性增加一行数据")
s5.loc['f'] = np.arange(1, len(s5.columns) + 1, 1)
print(s5)
print("增加多行数据:将要增加的数据放在一个DataFrame对象中,通过append方法增加，并形成一个新的DataFrame对象")
s55 = pd.DataFrame({
    'A': [1, 2, 3],
    'B': [4, 5, 6],
    "C": [7, 8, 9],
    'D': [10, 11, 12],
    'E': [13, 14, 15],
    'F': [16, 17, 18],
    'G': [19, 20, 21],
    'H': [22, 23, 24],
})
index55 = ['g', 'h', 'i']
s55.index = index55
print(s55)
s5 = s5.append(s55)
print(s5)
print('*' * 30)
print("\n" * 3)

print("数据的删,分为假删除和真删除，假删除返回一个删除后的新数据，真删除直接操作")
s6 = s5.drop(['H'], axis=1)
print(s6)
s6 = s5.drop(columns='H')
print(s6)
s6 = s5.drop(labels='H', axis=1)
print(s6)
print("删除一行数据")
s6 = s5.drop(index='i')
print(s6)
s6 = s5.drop(labels='i', axis=0)
print(s6)
print("真删除")
s5.drop(['i'], inplace=True)
print(s5)
print("删除符合条件的行")
print("删除B列中含有在4.5.6中任意一个的所有行")
s6 = s5.drop(s5[s5['B'].isin([4, 5, 6])].index)
print(s6)
print("删除E列>6的所有行")
s6 = s5.drop(s5[s5['E'] > 6].index)
print(s6)
print('*' * 30)
print("\n" * 3)

print("修改行列标题直接改 修改数据先抽取再赋值")
""" 直接赋值  df.columns=[ ],df.index=[]  """
""" df.rename() eg:df.rename(index={'7':'张三'},inplace=True)右边代替左边"""
print('*' * 30)
print("\n" * 3)

print("数据统计")
print("求和:sum")
print("s5:")
print(s5)
print("逐行求和：")
print(s5.sum(axis=1))
print("简单应用：将逐行求的和作为新一列：")
s5['I'] = s5.sum(axis=1)
print(s5)
print("求均值")
add = s5.mean(axis=0)
print(add)
""" df=df.append(new,ignore_index=True)此种方法也行 """
s5.loc['i'] = add.values
print(s5)
print('*' * 30)
print("\n" * 3)

print("数据排序")
print("s5:")
print(s5)
print("按行或列值进行排序")
print("按'H'列的大小升序排序所有行（inplace=true代表替换原来的数据，即真修改）")
""" 第一个参数为要排序的列或行名称，按行axis=1，按列axis=0 """
s5.sort_values('H', axis=0, ascending=True, inplace=True)
print(s5)
print("按行或列索引进行排序")
s5.sort_index(axis=0, ascending=True, inplace=True)
print(s5)
print('*' * 30)
print("\n" * 3)

print("数据排名:根据Series或DataFrame对象的某几列的值进行排名，主要使用rank方法")
afrnak = s5.rank(axis=0, method='max')
print("每个数字对应的它在这一行的排名，如果axis=1，则代表它在这一列的排名")
print(afrnak)
""" 注意如果出现数据相同的，排名会尽量往大的靠，比如第一第二出了，但第三第四一样，那么这两人的排名都是第四 """
print("类似于高中排名单的应用（雾），先按每一列（各科成绩）排名，再按最后一列总成绩排序")
afrnak.sort_values('H', axis=0, ascending=True, inplace=True)
print("总体按照最后一列升序排序，其余的数据对应每个人各科的排名")
""" method:average:平均排名（默认值） """
"""min:最小值排名 max:最大值排名 first:按值在原始数据中出现的顺序分配排名 """
""" dense:密集排名，类似最小值排名，但是排名每次只增加1，即排名相同的数据只占一个名次。 """
print(afrnak)
print('*' * 30)
print("\n" * 3)

print("数据汇总:groupby函数:")
print("s5")
print(s5)
print("H列按照A列的不同类型分类后各自的和,（比如A列都是1的所有H列元素和）")
print(s5['H'].groupby(s5["A"]).sum())
""" 举例如下: """
""" print(df[“评分”].groupby([df[“地区”],df[“类型”]]).mean()) """
""" #上面语句的功能是输出表格所有数据中不同地区不同类型的评分数据平均值"""
print("数据的统计信息")
print(s5.describe())
""" 数据透视表是相当于包含group以及dataframe数据相关函数功能的分析工具 """
""" ，很高端，但也很难理解，建议自行查阅(I am too vegetables) """
print('*' * 30)
print("\n" * 3)

print("数据合并-merge")
""" ,merge方法是按照两个DataFrame对象列名相同的列进行合并， """
""" 即两个DataFrame对象必须具有同名的列。返回合并后DataFrame对象 """
pd.set_option('display.unicode.east_asian_width', True)
""" 上方代码用来规范数据显示 """
l1 = pd.DataFrame({
    "学号": [201, 202, 203],
    "大英": [66, 99, 69],
    "高数": [77, 56, 95],
    "C": [99, 98, 99]
})
l2 = pd.DataFrame({
    "学号": [201, 202, 203],
    "python": [66, 99, 69],
    "高数": [77, 56, 95],
    "摆烂": [99, 98, 99]
})
l3 = pd.DataFrame({
    "学号": [204, 205, 206],
    "大英": [67, 985, 68],
    "高数": [787, 556, 975],
    "C": [9, 9, 9]
})
print("l1:")
print(l1)
print("l2")
print(l2)
l12 = pd.merge(l1, l2, how="left")
print("left")
print(l12)
l12 = pd.merge(l1, l2, how='right')
print("right")
print(l12)
l12 = pd.merge(l1, l2, how='outer')
print("outer")
print(l12)
l12 = pd.merge(l1, l2, how='inner')
print("inner")
print(l12)
l12 = pd.merge(l1, l2, how='outer', on='学号')
print("on")
print(l12)
l16 = pd.merge(l1, l3, how='outer', on='学号')
print("pd.merge(l1, l3, how='outer', on='学号')")
print(l16)
print("数据合并-concat")
l13 = pd.concat([l1, l2], axis=1)
print("pd.concat([l1,l2],axis=1)!=merge?")
print(l13)
l13 = pd.concat([l1, l3], axis=0)
print("pd.concat([l1,l3],axis=0)")
print(l13)
l13 = pd.concat([l1, l3], axis=0, keys=['l1', 'l2'])
print("pd.concat([l1,l3],axis=0, keys=['l1', 'l2'])")
print(l13)
l13 = pd.concat([l1, l2], axis=1, join='outer')
print("pd.concat([l1,l2],axis=1, join='outer')")
print(l13)
print("横向合并用merge，纵向用contact(只是建议，当然横向也可以contact，但是会全部拼接，看个人处理)")
""" 遇到重复的列标但数据不同会自动打上尾椎 """
print('*' * 30)
print("\n" * 3)

print("日期时间处理")
time = pd.DataFrame({
    'year': [2018, 2018, 2018],
    'month': [1, 1, 2],
    'day': [1, 8, 1]
})
print("time:")
print(time)
time['日期时间处理'] = pd.to_datetime(time)
print("after pd.to_datetime(time):")
print(time)
""" l12在上面一块的代码 """
newl12 = l12.set_index(time["日期时间处理"])
print(newl12)
newl112 = newl12.resample('W').sum().head()
print(newl112)
""" 重采样resample()对时间序列的频率进行调整，将时间序列从一个频率转换到另一个频率。 """
""" 不在频率范围内计入下一个，频率范围内没有赋值为0 ,!这些数据只是一个时点数据 """
print("rolling函数")
""" 数据波动较大时，某一点的数据就不能很好地表现它本身的特性。可以将某个点的取值扩大到包含这个点的一段区间，用区间来判断，这个区间就是窗口。 """
print("np.round(df['收盘'].rolling(window=20,center=False).mean(),2)")
""" window: 时间窗口的大小 """
""" min_periods:每个窗口最小包含的观测值数量 """
""" center:布尔型，是否从中间位置开始取数，默认值为False。 """
print("计算20天的收盘均价()rolling函数更多建议自行查阅(●°u°●) 」")
