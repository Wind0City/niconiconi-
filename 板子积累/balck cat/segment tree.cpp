#include<cmath>
#include<iostream>
#include<cstdio>
using namespace std;
const int N=50005;

void build_tree(int a[],int tree[],int node,int l,int r){
    if(l==r){
        tree[node]=a[l];
    }
    else{
        int mid=(l+r)>>1,leftnode=node<<1,rightnode=leftnode+1;
        build_tree(a,tree,leftnode,l,mid);
        build_tree(a,tree,rightnode,mid+1,r);
        tree[node]=tree[leftnode]+tree[rightnode];
    }
    
}

void update_tree_up(int tree[],int node,int start,int end,int i,int j){
    if(start==end){
        tree[node]+=j;
        return ;
    }
    int mid=(start+end)>>1,leftnode=node<<1,rightnode=leftnode+1;
    if(i<=mid){
        update_tree_up(tree,leftnode,start,mid,i,j);
    }
    else{
        update_tree_up(tree,rightnode,mid+1,end,i,j);
    }
    tree[node]=tree[leftnode]+tree[rightnode];
}

void update_tree_down(int tree[],int node,int start,int end,int i,int j){
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
    if(start>=i&&end<=j){
        return tree[node];
    }
    int mid=(start+end)>>1,leftnode=node<<1,rightnode=leftnode+1;int ans=0;
    if(i<=mid){
        ans+=query_tree(tree,leftnode,start,mid,i,j);
    }
    if(mid+1<=j){
        ans+=query_tree(tree,rightnode,mid+1,end,i,j);
    }
    return ans;
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