#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n%2==1)
    {
        cout<<"-1";
        return;
    }
    int c1=0,c2=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='0')
        {
            c1++;
        }
        else
        {
            c2++;
        }
    }
    if(c1!=c2)
    {
        cout<<"-1";
        return;
    }
    vector<int>v;
    int a=0;
    while(a==0)
    {
        int c=0;
        string t="";
        int k=s.size();
        for(int i=0;i<k;++i)
        {
            if(s[i]==s[k-i-1])
            {
                if(s[i]=='1')
                {
                    v.push_back(i);
                    for(int j=0;j<i;++j)
                    t+=s[j];
                    t+="01";
                    for(int j=i;j<k;++j)
                    t+=s[j];
                }
                else
                {
                    v.push_back(k-i);
                    for(int j=0;j<k-i;++j)
                    t+=s[j];
                    t+="01";
                    for(int j=k-i;j<k;++j)
                    t+=s[j];
                }
                c++;
                break;
            }
        }
        s=t;
        if(c==0)
        {
            break;
        }
    }
    cout<<v.size()<<"\n";
    for(auto&it:v)
    {
        cout<<it<<" ";
    }
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
        cout<<"\n";
    }
    return 0;
}