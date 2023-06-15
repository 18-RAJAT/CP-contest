#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],height[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i]>>height[i];
    }
    int count=1;
    for(int i=1;i<n-1;++i)
    {
        if(a[i-1]<a[i]-height[i])
        {
            count++;
        }
        else if(a[i+1]>a[i]+height[i])
        {
            a[i]+=height[i];
            count++;
        }
    }
    if(n<=1)
    {
        cout<<count<<"\n";
    }
    else
    {
        cout<<count+1<<"\n";
    }
}