#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n/2;++i)
    {
        if(i%2==0)
        {
            swap(a[i],a[n-i-1]);
        }
    }
    for(int i=0;i<n;++i)
    {
        cout<<a[i]<<" ";
    }
}