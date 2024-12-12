#include<bits/stdc++.h>
using namespace std;
#define int long long

bool dup(const vector<int>&A)
{
    for(int i=1;i<A.size();++i)if(A[i]==A[i-1])return true;
    return false;
}
void sol()
{
    int n,l,r;
    cin>>n>>l>>r;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a.begin(),a.end());
    bool d=dup(a);
    if(n==2)
    {
        int f;
        (d)?f=0:f=a[0]^a[1];
        cout<<((l<=f && f<=r)?"YES":"NO")<<endl;
    }
    else if(n>12)
    {
        if(d)
        {
            cout<<((l<=0 && 0<=r)?"YES":"NO")<<endl;
        }
        else cout<<"NO"<<endl;
    }
    else
    {
        if(d)
        {
            cout<<((l<=0 && 0<=r)?"YES":"NO")<<endl;
        }
        else
        {
            int F=1;
            bool o=false;
            for(int i=0;i<n && !o;++i)
            {
                for(int j=i+1;j<n && !o;++j)
                {
                    int x=a[i]^a[j];
                    F*=x;
                    if(F>r)o=true;
                }
            }
            if(o)cout<<"NO"<<endl;
            else
            {
                cout<<((l<=F && F<=r)?"YES":"NO")<<endl;
            }
        }
    }
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}