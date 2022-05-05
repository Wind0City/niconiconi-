#include<bits/stdc++.h>
using namespace std;
const int N=200005;




int n,q;
char s[N];
int a[N]={0},tree[N<<2]={0},tree_lazy[N<<2]={0};

void push_down(int node,int start,int mid,int end){//lazy的向下推，，主要就是这个东西
    if(tree_lazy[node]){//如果有标记
        tree_lazy[node*2]^=1;//1^1=0,0^1=1,就是反转一下lazy标记
        tree_lazy[(node*2)+1]^=1;
        tree[node*2]=mid-start+1-tree[node*2];//操作是把数字个数减去1的个数，就把0和1的个数反转了，记录的是1的个数
        tree[(node*2)+1]=end-mid-tree[(node*2)+1];
        tree_lazy[node]=0;
    }
}

void build_tree(int node,int l,int r){
    if(l==r){
        tree[node]=a[l];
        return ;
    }
    int left_node=node<<1;int right_node=left_node+1;int mid=(l+r)>>1;
    build_tree(left_node,l,mid);
    build_tree(right_node,mid+1,r);
    tree[node]=tree[left_node]+tree[right_node];
}

void update_tree(int node,int start,int end,int l,int r){
    if(start>=l&&end<=r){
        tree[node]=(end-start+1)-tree[node];
        tree_lazy[node]^=1;
        return ;
    }
    int left_node=node<<1;int right_node=left_node+1;int mid=(start+end)>>1;
    push_down(node,start,mid,end);
    if(mid>=l){
        update_tree(left_node,start,mid,l,r);
    }
    if(mid<r){
        update_tree(right_node,mid+1,end,l,r);
    }
    tree[node]=tree[left_node]+tree[right_node];
}

long long query_tree(int node,int start,int end,int l,int r){
    if(start>=l&&end<=r){
        return tree[node];
    }
    int left_node=node<<1;int right_node=left_node+1;int mid=(start+end)>>1;
    push_down(node,start,mid,end);
    long long sum=0;
    if(mid>=l){
        sum+=query_tree(left_node,start,mid,l,r);
    }
    if(mid<r){
        sum+=query_tree(right_node,mid+1,end,l,r);
    }
    return sum;
}




int main()
{
    scanf("%d%d",&n,&q);
    scanf(" %s",s);
    for(int i=1;i<=n;i++){
        a[i]=s[i-1]-'0';
    }
    // for(int i=1;i<=n;i++){
    //     printf("%d",a[i]);
    // }
    build_tree(1,1,n);
    // for(int i=1;i<=31;i++){
    //     printf("%d",tree[i]);
    // }
    // printf("%d%d%d%d%d%d%d%d%d%d\n",
    //             tree[16],tree[17],tree[9],tree[10],tree[11],
    //                 tree[24],tree[25],tree[13],tree[14],tree[15]);
    while (q--)
    {
        int b,l,r;
        scanf("%d%d%d",&b,&l,&r);
        if(b==0){
            update_tree(1,1,n,l,r);
            // printf("%d%d%d%d%d%d%d%d%d%d\n",
            //     tree[16],tree[17],tree[9],tree[10],tree[11],
            //         tree[24],tree[25],tree[13],tree[14],tree[15]);
        }
        else if(b==1){
            printf("%lld\n",query_tree(1,1,n,l,r));
            // printf("%d%d%d%d%d%d%d%d%d%d\n",
            //     tree[16],tree[17],tree[9],tree[10],tree[11],
            //         tree[24],tree[25],tree[13],tree[14],tree[15]);
        }
    }
    return 0;
}

//题目大意：区间反转0和1



/*
题目描述
AKN 觉得第一题太水了，不屑于写第一题，所以他又玩起了新的游戏。在游戏中，他发现，这个游戏的伤害计算有一个规律，规律如下
拥有一个伤害串，是一个长度为 nn 的只含字符 0 和字符 1 的字符串。规定这个字符串的首字符是第一个字符，即下标从 11 开始。
给定一个范围 [l,~r][l, r]，伤害为伤害串的这个范围内中字符 1 的个数
会修改伤害串中的数值，修改的方法是把 [l,~r][l, r] 中所有原来的字符 0 变成 1，将 1 变成 0。
AKN 想知道一些时刻的伤害，请你帮助他求出这个伤害。



输入格式
输入的第一行有两个用空格隔开的整数，分别表示伤害串的长度 nn，和操作的个数 mm。
输入第二行是一个长度为 nn 的字符串 SS，代表伤害串。
第 33 到第 (m + 2)(m+2) 行，每行有三个用空格隔开的整数 op, l, rop,l,r。代表第 ii 次操作的方式和区间，规则是：
若 op = 0op=0，则表示将伤害串的 [l,~r][l, r] 区间内的 0 变成 1，1 变成 0。
若 op = 1op=1，则表示询问伤害串的 [l,~r][l, r] 区间内有多少个字符 1。



输出格式
对于每次询问，输出一行一个整数，代表区间内 1 的个数。


输入输出样例
输入
10 6
1011101001
0 2 4
1 1 5
0 3 7
1 1 10
0 1 4
1 2 6


输出
3
6
1
*/