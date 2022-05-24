/*
multiset介绍:
1.multiset是按照特定顺序存储元素的容器，其中的元素是可以重复的。
2.在multiset中，时间保存的是<value，value>键值对，multiset元素不可以修改，修改了可能就不是二叉搜索树了，所以元素总是const的，但是可以删除和插入multiset容器。
3.在内部，multiset中的元素总是按照内部的比较规则所指定的特定弱排序准则进行排序。
4.multiset底层结构为平衡二叉树(红黑树)。

注意：
1. multiset中再底层中存储的是<value, value>的键值对
2. mtltiset的插入接口中只需要插入即可
3. 与set的区别是，multiset中的元素可以重复，set是中value是唯一的
4. 使用迭代器对multiset中的元素进行遍历，可以得到有序的序列
5. multiset中的元素不能修改
6. 在multiset中找某个元素，时间复杂度为O(logN)
7. multiset的作用：可以对元素进行排序
*/


/*
multimap介绍:
multimap和map基本相同，主要的不同是map键值对中的key是不可以重复的，
multimap中键值对中的key是可以重复的。

注意：
1.只是说key，没有说value。value可以重复，也可以不重复。
2.multimap保存的键值对中的key值不可以修改，但是对应的value可以修改。
3.multimap中没有重载operator[]，因为如果想按照key去找value，由于multimap中key可以重复，就不知道返回哪个value的引用了。
*/


/*
个人理解:
multimap与multiset，除了有重复键与元素和不能修改之外，与map和set并无区别，对应的题目对应着使用就行
最最最重要的:多个相同的关键字存储在容器中时，则会相邻存储；(multimap)!!!!!!
所以查找元素可以使用find+count，lower-bound+upper-bound来查找!!!
*/