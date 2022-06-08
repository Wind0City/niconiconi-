import pandas as pd

a = pd.read_csv(r"D:\code\PY\study\数据分析及可视化作业\score.txt")
df = pd.DataFrame(a)
print(df)
df1 = df.iloc[0:3]
df2 = df.iloc[3:6]
df3 = df.iloc[6:9]
df4 = df.iloc[9:12]
print(df1)
print(df2)
print(df3)
print(df4)
xh_ave = df1['成绩'].mean()
xh_tol = df1['成绩'].sum()
zm_ave = df2['成绩'].mean()
zm_tol = df2['成绩'].sum()
xj_ave = df3['成绩'].mean()
xj_tol = df3['成绩'].sum()
xl_ave = df4['成绩'].mean()
xl_tol = df4['成绩'].sum()
a = "{0:<10}{1:<5.1f}{2:>10.2f}"+6

print(a.format('小红', xh_tol, xh_ave))
print(a.format('张明', zm_tol, zm_ave))
print(a.format('小江', xj_tol, xj_ave))
print(a.format('小李', xl_tol, xl_ave))
