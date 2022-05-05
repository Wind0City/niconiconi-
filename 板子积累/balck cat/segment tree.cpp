#include<cmath>
#include<iostream>
#include<cstdio>
using namespace std;
const int N=50005;

void build_tree(int a[],int tree[],int node,int l,int r){//建树
    if(l==r){//结束条件
        tree[node]=a[l];
    }
    else{
        int mid=(l+r)>>1,leftnode=node<<1,rightnode=leftnode+1;//mid是左边的区域最后，leftnode是左边区域的树的序号，rightnode是右边区域的树的序号
        build_tree(a,tree,leftnode,l,mid);//左边的
        build_tree(a,tree,rightnode,mid+1,r);//右边的
        tree[node]=tree[leftnode]+tree[rightnode];//向上推
    }
    
}

void update_tree_up(int tree[],int node,int start,int end,int i,int j){//更新一个点然后向上推
    if(start==end){//结束条件
        tree[node]+=j;
        return ;
    }
    int mid=(start+end)>>1,leftnode=node<<1,rightnode=leftnode+1;
    if(i<=mid){//如果在区间左边
        update_tree_up(tree,leftnode,start,mid,i,j);
    }
    else{//如果在区间右边
        update_tree_up(tree,rightnode,mid+1,end,i,j);
    }
    tree[node]=tree[leftnode]+tree[rightnode];
}

void update_tree_down(int tree[],int node,int start,int end,int i,int j){//同上
    if(start==end){
        tree[node]-=j;
        return ;
    }
    int mid=(start+end)>>1,leftnode=node<<1,rightnode=leftnode+1;
    if(i<=mid){
        update_tree_down(tree,leftnode,start,mid,i,j);
    }
    else{
        update_tree_down(tree,rightnode,mid+1,end,i,j);
    }
    tree[node]=tree[leftnode]+tree[rightnode];
}

int query_tree(int tree[],int node,int start,int end,int i,int j){
    if(start>=i&&end<=j){//如果一个区间就不用向下再找了，最下面的情况也包含了
        return tree[node];
    }
    int mid=(start+end)>>1,leftnode=node<<1,rightnode=leftnode+1;int ans=0;
    if(i<=mid){
        ans+=query_tree(tree,leftnode,start,mid,i,j);
    }
    if(mid+1<=j){
        ans+=query_tree(tree,rightnode,mid+1,end,i,j);
    }
    return ans;//本来就是求和
}





int main()
{
    int t,k=1;
    scanf("%d",&t);
    while(t--){
        int n,a[N],tree[N<<2];
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        build_tree(a,tree,1,1,n);
        // for(int i=1;i<=17;i++){
        //     printf("%d",tree[i]);
        // }
        printf("Case %d:\n",k++);
        char s[10];int i,j;
        scanf(" %s",s);
        while(s[0]!='E'){
            if(s[0]=='A'){
                scanf("%d%d",&i,&j);
                update_tree_up(tree,1,1,n,i,j);
                // for(int i=1;i<=17;i++){
                //     printf("%d",tree[i]);
                // }
            }
            else if(s[0]=='S'){
                scanf("%d%d",&i,&j);
                update_tree_down(tree,1,1,n,i,j);
                // for(int i=1;i<=17;i++){
                //     printf("%d",tree[i]);
                // }
            }
            else if(s[0]=='Q'){
                scanf("%d%d",&i,&j);
                printf("%d\n",query_tree(tree,1,1,n,i,j));
            }
            scanf(" %s",s);
        }
    }
    return 0;
}
//题目大意：维护和，单点修改，区间查询



/*
题目：

Lily特别喜欢养花，但是由于她的花特别多，所以照料这些花就变得不太容易。
她把她的花依次排成一行，每盆花都有一个美观值。如果Lily把某盆花照料的好的话，
这盆花的美观值就会上升，如果照料的不好的话，这盆花的美观值就会下降。有时，
Lily想知道某段连续的花的美观值之和是多少，但是，Lily的算术不是很好，
你能快速地告诉她结果吗?



Input
第一行一个整数T，表示有T组测试数据。
每组测试数据的第一行为一个正整数N (N<=50000)，表示Lily有N盆花。
接下来有N个正整数，第i个正整数ai (1<=ai<=50) 表示第i盆花的初始美观值。
接下来每行有一条命令，命令有4种形式：
（1）Add i j, i和j为正整数，表示第i盆花被照料的好，美观值增加j (j<=30)
（2）Sub i j, i和j为正整数，表示第i盆花被照料的不好，美观值减少j (j<=30)
（3）Query i j, i和j为正整数，i<=j，表示询问第i盆花到第j盆花的美观值之和
（4）End，表示结束，这条命令在每组数据最后出现
每组数据的命令不超过40000条


Output
对于第i组数据，首先输出"Case i:"和回车。
对于每个"Query i j"命令，输出第i盆花到第j盆花的美观值之和。


Sample Input
1
9
7 9 8 4 4 5 4 2 7
Query 7 9
Add 4 9
Query 3 6
Sub 9 6
Sub 3 3
Query 1 9
End 


Sample Output
Case 1:
13
30
50 

*/ 