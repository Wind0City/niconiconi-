import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv(r"D:\code\PY\study\数据分析及可视化作业\data.csv")
df.dropna(how='any', inplace=True)
""" 将数据中的所有空值删除。 """

for i in range(len(df['总价'])):
    item = df['总价'].iloc[i]
    item = list(item)
    del (item[-1])
    item = "".join(item)
    item = eval(item)
    df['总价'].iloc[i] = item
for i in range(len(df['建筑面积'])):
    item = df['建筑面积'].iloc[i]
    item = list(item)
    del (item[-1])
    del (item[-1])
    item = "".join(item)
    item = eval(item)
    df['建筑面积'].iloc[i] = item
for i in range(len(df['单价'])):
    item = df['单价'].iloc[i]
    item = list(item)
    del (item[-1])
    del (item[-1])
    del (item[-1])
    del (item[-1])
    item = "".join(item)
    item = eval(item)
    df['单价'].iloc[i] = item
""" 将“总价”、“建筑面积”、“单价”对应数据中的字符去掉，仅保留数字部分，并将数字转换为float类型。 """

df_jingkai = df.loc[df['区域'] == '经开']
df_jingkai = df_jingkai.sort_values('单价', axis=0, ascending=False)
""" 筛选“经开”区的房子信息，并以单价由高到低排列 """

data1 = df['总价'].groupby(df['区域']).mean()
x = data1.index
heigh = data1.values
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
plt.bar(x, height=heigh, width=0.5, align='center', color='pink')
for a, b in zip(x, heigh):
    plt.text(a, b, round(b, 2), ha="center")
plt.title("各区域二手房均价柱状图")
plt.savefig(r"D:\code\PY\study\数据分析及可视化作业\各区域二手房均价柱状图.png")
plt.show()
""" 分类汇总各区域二手房均价，并以柱形图展现分析结果。 """

plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
data2 = df.groupby(df['区域']).count()
x = data2['单价']
plt.pie(x, labels=data2.index, autopct='%1.1f%%', radius=1.1)
plt.title("各区域二手房数量饼图")
plt.savefig(r"D:\code\PY\study\数据分析及可视化作业\各区域二手房数量饼图.png")
plt.show()
""" 分类汇总各区域二手房数量，并以饼图展现分析结果 """
