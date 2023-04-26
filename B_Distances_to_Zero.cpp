#include<bits/stdc++.h>
using namespace std;


int main()
{
    long long int n;
    cin>>n;

    long long int left=-1000000001;
    long long int right=100000001;

    int array[n+1];
    int array1[n+1];
    // memset(array,0,sizeof(array));
    // memset(array1,0,sizeof(array1));
    for(int i=0;i<n;++i)
    {
        cin>>array[i];
    }
    for(int i=0;i<n;++i)
    {
        if(array[i]==0)
        {
            left=i;
        }
        array1[i]=i-left;
    }
    for(int i=n-1;i>=0;--i)
    {
        if(array[i]==0)
        {
            right=i;
            // array[i]=right-i;
        }
        array1[i]=min<long long>(array1[i],right-i);
    }
    for(int i=0;i<n;++i)
    {
        cout<<array1[i]<<" ";
    }
    return 0;
}