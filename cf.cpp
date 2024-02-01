#include<bits/stdc++.h>
using namespace std;
#define int long long
void sample()
{
    int n;
    cin>>n;
    (n==16 || n==17 || n==18)?cout<<"ADVITIYA"<<endl:cout<<"WAITING FOR ADVITIYA"<<endl;
}
void sample1()
{
    int r1,r2,r3,r4,r5;
    cin>>r1>>r2>>r3>>r4>>r5;
    int cnt=0;
    (r1==1)?cnt++:cnt+=0;
    (r2==1)?cnt++:cnt+=0;
    (r3==1)?cnt++:cnt+=0;
    (r4==1)?cnt++:cnt+=0;
    (r5==1)?cnt++:cnt+=0;
    (cnt>=4)?cout<<"YES"<<endl:cout<<"NO"<<endl;
}
void sample2()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    vector<int>ans;
    for(int i=0;i<n;++i)
    {
        int cnt=0;
        for(int j=0;j<=i;++j)
        {
            cnt+=a[j];
        }
        for(int j=i;j<n;++j)
        {
            cnt+=b[j];
        }
        ans.push_back(cnt);
    }
    for(auto& i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
void sol()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    int cnt=0;
    vector<int>ans;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        if(k<=a[i])
        {
            int x=a[i]%k;
            ans.push_back(x);
            cnt++;
        }
    }
    (cnt<=0)?cout<<"-1"<<endl:cout<<*min_element(ans.begin(),ans.end())<<endl;
}
void sol2()
{
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    auto longest_beautiful_substring=[&](string s)
    {
        int ans=0;
        int cnt=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]==s[0])
            {
                cnt++;
            }
            else
            {
                ans=max(ans,cnt);
                cnt=0;
            }
        }
        ans=max(ans,cnt);
        return ans;
    };
    for(auto& i:s)
    {
        string tmp=s;
        tmp+=i;
        cout<<longest_beautiful_substring(tmp)<<" ";
        s=tmp;
    }
    cout<<endl;
}
void sol3()
{
    int n,k;
    cin>>n>>k;
    int ok=1;
    vector<int>ans;
    for(int i=0;i<=k;++i)
    {
        (ok)?ans.push_back(1):ans.push_back(0);ok=not ok;
    }
    vector<int>odd,even;
    for(int i=1;i<=n;++i)
    {
        (i%2==0)?even.push_back(i):odd.push_back(i);
    }
    vector<int>aux;
    for(int i=0;i<ans.size();++i)
    {
        if(ans[i]==0)
        {
            aux.push_back(even.back());
            even.pop_back();
        }
        else
        {
            aux.push_back(odd.back());
            odd.pop_back();
        }
    }
    for(int i=0;i<aux.size();++i)
    {
        if(aux[i]%2==0)
        {
            while(!even.empty())
            {
                cout<<even.back()<<" ";
                even.pop_back();
            }
            cout<<aux[i]<<" ";
        }
        else
        {
            while(!odd.empty())
            {
                cout<<odd.back()<<" ";
                odd.pop_back();
            }
            cout<<aux[i]<<" ";
        }
    }
    cout<<endl;
}
void sol4()
{
    int x,q;
    cin>>x>>q;
    vector<int>v;
    function<void(int)>prime_fact=[&](int n)->void
    {
        while(n%2==0)
        {
            v.push_back(2);
            n/=2;
        }
        for(int i=3;i<=sqrt(n);i+=2)
        {
            while(n%i==0)
            {
                v.push_back(i);
                n/=i;
            }
        }
        if(n>=3)
        {
            v.push_back(n);
        }
    };
    prime_fact(x);
    // multimap<int,int>mp;
    map<int,int>mp;
    mp.clear();
    for(auto it:v)
    {
        // mp.insert({it,0});
        mp[it]++;
    }
    while(q--)
    {
        int tmp;
        cin>>tmp;
        int ans=1;
        tmp++;
        for(auto it:mp)
        {
            int cnt=0;
            int val=it.second;
            int ert=val*tmp;
            int compute=ert-val;
            // cout<<"compute: "<<compute<<endl; // 2 3 4 5 6 7 8 9 10 11 12 13 14 15
            if(val<=compute)
            {
                cnt++;
            }
            compute=val/(tmp-1);
            int div=tmp-1;
            // cout<<"find div: "<<div<<endl;
            if(val%div==0 && compute<val)
            {
                cnt++;
            }
            // else
            // {
            //     cnt+=2;
            // }
            ans*=cnt%1000000007;
        }
        cout<<ans%1000000007<<endl;
    }
}
void sol5()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    auto bit_and=[&](vector<int>a)->int
    {
        int ans=a[0];
        for(int i=1;i<a.size();++i)
        {
            ans&=a[i];
        }
        return ans;
    };
    auto bit_xor=[&](vector<int>a)->int
    {
        int ans=a[0];
        for(int i=1;i<a.size();++i)
        {
            ans^=a[i];
        }
        return ans;
    };
    function<int(vector<int>)>magical=[&](vector<int>a)->int
    {
        int ans=0;
        int i=0;
        while(i<a.size())
        {
            int j=i;
            while(j<a.size())
            {
                vector<int>tmp;
                for(int k=i;k<=j;++k)
                {
                    tmp.push_back(a[k]);
                }
                if(bit_and(tmp)==bit_xor(tmp))
                {
                    ans++;
                }
                j++;
            }
            i++;
        }
        return ans;
    };
    cout<<magical(a)<<endl;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sample2();
    }
    return 0;
}