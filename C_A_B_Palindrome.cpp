#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b;
    string s;
    cin>>a>>b>>s;
    int A=0,B=0;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='0')A++;
        if(s[i]=='1')B++;
    }
    a-=A,b-=B;
    int l=0,r=s.size()-1;
    while(l<=r)
    {
        if(s[l]!='?' && s[r]=='?')
        {
            (s[l]=='0')?a--:b--;
            s[r]=s[l],l++,r--;
            continue;
        }
        if(s[l]=='?' && s[r]!='?')
        {
            (s[r]=='0')?a--:b--;
            s[l]=s[r],l++,r--;
            continue;
        }
        l++,r--;
    }
    l=0,r=s.size()-1;
    while(l<=r)
    {
        if(s[l]=='?' && s[r]=='?')
        {
            if(a>=b)
            {
                s[l]='0',s[r]='0';
                (l==r)?a--:(a-=2,l++,r--);
                continue;
            }
            if(a<b)
            {
                s[l]='1',s[r]='1';
                (l==r)?b--:(b-=2,l++,r--);
                continue;
            }
        }
        if(s[l]!=s[r])
        {
            cout<<-1<<endl;
            return;
        }
        l++,r--;
    }
    cout<<(a==0 && b==0?s:"-1")<<endl;
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