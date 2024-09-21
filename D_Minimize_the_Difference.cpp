#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n+5);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int ok=1,Minimize_diff=LLONG_MAX;
    while(ok)
    {
        ok=0;   
        for(int i=0;i<n-1;++i)
        {
            if((a[i]-a[i+1])>0)
            {
                ok=1; 
                int ans=a[i]-a[i+1];
                ans=(ans+1)/2;
                a[i]-=ans; a[i+1]+=ans;
            }
        }
        Minimize_diff=min(Minimize_diff,*max_element(a.begin(), a.begin()+n) - *min_element(a.begin(), a.begin()+n));
    }
    int minVal=*min_element(a.begin(),a.begin()+n),maxVal=*max_element(a.begin(),a.begin()+n);
    Minimize_diff=min(Minimize_diff,maxVal-minVal);
    cout<<Minimize_diff<<endl;
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