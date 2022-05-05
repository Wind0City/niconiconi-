#include<bits/stdc++.h>
using namespace std;
const int N=200005;




int n,q;
char s[N];
int a[N]={0},tree[N<<2]={0},tree_lazy[N<<2]={0};

void push_down(int node,int start,int mid,int end){
    if(tree_lazy[node]){
        tree_lazy[node*2]^=1;
        tree_lazy[(node*2)+1]^=1;
        tree[node*2]=mid-start+1-tree[node*2];
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