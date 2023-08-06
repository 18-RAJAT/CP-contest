#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        long long cnt1=count(a,a+n,1);
        long long sum=accumulate(a,a+n,0LL);
        cout<<((n==1 || sum<cnt1+n)?"NO":"YES")<<"\n";
    }
}