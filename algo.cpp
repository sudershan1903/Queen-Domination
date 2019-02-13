#include<iostream>
using namespace std;
int main()
{
    int i=0,j=0,n=8;
    for(i=0;i<n/2;i++)
    {
        j=n/2+2*i-1;
        cout<<endl<<i<<"\t\t\t\t"<<j;
    }
    return 0;
}
