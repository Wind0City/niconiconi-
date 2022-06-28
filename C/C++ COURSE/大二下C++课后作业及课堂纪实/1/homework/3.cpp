//问题三
#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int n,i=0,j=1;
    int *p=new int [j*10];
    while(cin>>n)
    {
       
        p[i++]=n;
        if((i-1)==(j*10-1))
        {
            int *p=new int[(++j)*10];
        }
        if(n==0)
        {
            break;
        }
    }
    for ( i = 0;p[i]!=0; i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<endl;
    delete[] p;
    return 0;
}