#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int count=0,wait=0;
    for(int i=0;i<n;++i)
    {
        if(wait<=a[i])
        {
            count++;wait+=a[i];
        }
    }
    cout<<count<<"\n";
}