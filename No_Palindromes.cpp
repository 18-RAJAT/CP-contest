#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int freq[26]={0};
    for(auto& c:s)freq[c-'a']++;
    int odd=0,res=0;
    char ch='\0';
    for(int i=0;i<26;++i)
    {
        if(freq[i]>0)
        {
            res++;
            if(freq[i]%2)
            {
                odd++;
                ch='a'+i;
            }
        }
    }
    if(odd>1)
    {
        cout<<"0"<<endl;
        return;
    }
    if(odd==1)
    {
        char rem='{';
        for(char c='a';c<='z';++c)
        {
            if(c!=ch && freq[c-'a']>0)
            {
                rem=c;
                break;
            }
        }
        if(rem<='z')cout<<"1\n"<<rem<<endl;
        else cout<<"-1"<<endl;
        return;
    }
    if(res<2)
    {
        cout<<"-1"<<endl;
        return;
    }
    string suf(n,'z'+1),ans="{";
    suf[n-1]=s[n-1];
    for(int i=n-2;~i;--i)suf[i]=min(s[i],suf[i+1]);
    for(int i=0;i<n-1;++i)
    {
        if(s[i]!=suf[i+1])
        {
            string t="";
            t+=s[i],t+=suf[i+1];
            if(t<ans)ans=t;
        }
    }
    if(ans!="{")cout<<"2\n"<<ans<<endl;
    else cout<<"-1"<<endl;
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