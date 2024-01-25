#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int cnt1=0,cnt2=0,cnt3=0;
    auto left=[&](int x,int y)
    {
        return (x<<y);
    };
    auto right=[&](int x)
    {
        return (x>>1);
    };
    while(n>=1)
    {
        if(n&1)
        {
            (n==1)?cnt2+=left(n,cnt3):cnt1+=left(1,cnt3);
        }
        n=right(n);
        cnt3++;
    }
    cout<<cnt1<<" "<<cnt2<<endl;
}
void sol1()
{
    int n,k;
    cin>>n>>k;
    int div=n/k;
    int rem=n%k;
    int temp=div;
    while(k--)
    {
        cout<<temp<<" ";
        temp+=div;
        if(rem)
        {
            temp++;
            rem--;
        }
    }
    cout<<endl;
}
void sol2()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    // map<int,int> mp;
    // mp.clear();
    int ans=0,current_state=0;
    for(int i=0;i<n;++i)
    {
        // mp[a[i]]++;
        current_state+=a[i];
        if(m<=current_state)
        {
            ans++;
            current_state=0;
        }
    }
    cout<<ans<<endl;
}
void sol4()
{
    int n;
    cin>>n;
    function<string(int)>bin_pow=[&](int n)->string
    {
        string ans="";
        while(n!=0)
        {
            (n&1)?ans.push_back('1'):ans.push_back('0');
            n/=2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    };
    auto ease=[&](int b)->int
    {
        return (b&1);
    };
    function<int(int,int)> power=[&](int a,int b)->int
    {
        int ans=1;
        while(b)
        {
            if(ease(b))
            {
                ans*=a;
            }
            // a/=2;
            a*=a,b/=2;
        }
        return ans;
    };
    map<int,int>mp;
    string str=bin_pow(n);
    string hash="111111";
    int ctr=0,set;
    int sza=str.size();
    for(int i=0;i<str.size();++i)
    {
        if(str[i]==hash[ctr])
        {
            ctr++;
            if(ctr==2)
            {
                set=i+1;
                break;
            }
        }
        // if(str[i]!=hash[ctr])
        // {
        //     ctr=0;
            // if(ctr==2)
            // {
            //     set=i+1;
            //     break;
            // }
        // }
    }
    // cout<<1<<endl;
    if(ctr<2)
    {
        cout<<1<<endl;
        return;
    }
    int cnt=0;
    for(int i=set;i<str.size();++i)
    {
        if(str[i]=='0')
        {
            cnt++;
        }
    }
    cout<<power(2,cnt)<<endl;
}
void sol5()
{

}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol5();
    }
    return 0;
}