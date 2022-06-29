//问题二：
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int n;
    cin>>n;

    int *p=new int [n];
    p[0]=1;p[1]=1;

    for (int i = 2; i < n; i++)
    {
        p[i]=p[i-1]+p[i-2];
    }
    
    for (int i = 0; i < n; i++)
    {
        cout<<p[i]<<"\t";
        if((i+1)%5==0)
        {
            cout<<endl;
        }
    }
    
    delete[] p;
    return 0;
} 