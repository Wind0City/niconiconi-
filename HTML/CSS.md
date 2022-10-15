[toc]
# 语法规范
主要构成：选择器以及一条或者多条声明
css写在head双标签中，再用style双标签进行定义
例：修改段落标签的字体颜色
```html
<head>
    <style>
        p{
            color: red;
            font-size:100px;
        }
    </style>
</head>
```
# 代码风格
样式格式：紧凑，展开（规范
样式大小写：小写字母
空格规范： 冒号后保留一个空格 选择器和大括号中间保留一个空格

# 基础选择器
选择器的作用：选择特定的标签用的
分类：基础选择器与复合选择器
## 标签选择器
将html标签名作为选择器
（是对所有的该类标签的改变
## 类选择器
差异化的选用不同的标签，单独选用使用一个时候，可以使用类选择器
```html
.red {
    color: red;
}
······
<li class="red">全部的red类变红色</li>
```
## 类选择器-多类名
标签中class中写多个属性，空格隔开
## id选择器
多和JavaScript搭配使用
以id属性来设置id选择器，css以#来定义
```html
    <style>
        #pink {
            color: pink;
        }
    </style>
······
   <div id="pink">id选择器只能调用一次</div>
```
## 通配符选择器
同*来定义，所有的标签元素都会变成同一个设置
# 字体属性
## font-family字体系列
用来设置字体格式，如宋体，微软雅黑。
`eg:p{font-family:'微软雅黑(Microsoft Yahei)',Arial}`
使用英文逗号隔开 
字体系列单词较多，一个用引号引起来
写多个字体系列，会在前一个没有的情况下，默认使用下一个(防止不兼容)
## font-size 字体大熊啊
`p{font-size:20px}`
px像素大小为网页的最常用单位，不同浏览器默认值不同
可以给body指定整个页面文字的大小
## font-weight 字体粗细
有多个属性：noramal:400默认 bold：700字体加粗 bolder 
最好的话给个数字就可以规范大小,注意数字不跟单位
`p{font-weight:700}`;
## font-style 文字样式
属性值：normal：正常样式  italic：斜体
## 字体复合属性(用一行代码规范多个属性,即简写的方式)
```htm
    body//顺序不能变
    {
        font: font-size font-weight font-size/line-height font-family
    }
```
顺序不能变
不需要设置的属性可以省略、
字号和字体必须同时出现才能连写
# 文本属性
## 文本颜色
```HTML
div{
    color:red;
}
```
颜色方法：字母；十六进制；**RGB**
RGB最方便实用（个人认为
## 对齐文本
`text-align`属性用于设置元素文本内容的**水平对齐方式**
可选属性：`left center right`
## 装饰文本
`text-decoration`用于添加下划线，删除线，上划线
什么都没有：none(可以用来去掉链接的默认文字)
下划线：underline 
上划线：overline
删除线：line-through
## 文本缩进
只缩进首行
`text-indent`:后面加数字像素(px)，代表缩进位置长短
也可以用em(相对单位)，就是当前元素**一个文字的大小**
## 行间距
`line height`用来设置行高，属性后跟像素单位px
行间距是包括上间距和文本高度和下间距
# css的引入方式
分为三种样式表：
- 行内式
    直接在标签内进行操作，写style：“相关属性设置”
- 内部样式表
    全部放在style里，style一般放在head里
- 外部样式表
    在外部定义一个css文件

设置css文件的步骤
1. 新建一个后缀未.css的文件
2. 在文件里直接写样式
3. 引入：用link标签引入 `<link rel="stylesheet" href="css文件名">` link+<kbd>TAB</kbd> 会自动补全
# Emmet 语法
## 快速生成HTML结构，输入标签按+ <kbd>TAB</kbd> 
生成多个相同标签 表现签名+*+个数
父子关系：`div>span`+TAB    
兄弟关系 `div>span`+"+"
生成带有类名和id的 `.类名`+<kbd>TAB</kbd>或者类名换成`#id号`(生成的都是div块)
生成的div类名是有顺序的，可以用自增符号$*数量
想要生成的标签内部写内容可以用{}表示
## 快速生成css样式语法
(~~缩写就行~~)
(~~看提示就行~~)
(手动滑稽)
