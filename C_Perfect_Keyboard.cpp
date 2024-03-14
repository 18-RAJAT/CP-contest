#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    string str="";
    int ans=-1;
    deque<char>dq;
    // dq.push_back(s[0]);
    map<char,int>mp;
    mp.clear();
    bool possible=false;
    for(int i=0;i<n;i++)
    {
        if(dq.size()<2)
        {
            dq.push_back(s[i]);
            // ans=i;
            ans++;
            mp[s[i]]++;
        }
        else
        {
            if(ans==dq.size()-1)
            {
                if(dq[ans-1]==s[i])
                {
                    ans--;
                }
                else
                {
                    if(mp[s[i]]==0)
                    {
                        dq.push_back(s[i]);
                        // ans=i;
                        ans++;
                        mp[s[i]]++;
                    }
                    else
                    {
                        possible=true;
                    }
                }
            }
            //this case when ans==0 is not needed because it is already handled in the next else if condition
            else if(ans==0 && dq.size()>1)
            {
                if(dq[ans+1]==s[i])
                {
                    ans++;
                }
                else
                {
                    if(mp[s[i]]==0)
                    {
                        dq.push_front(s[i]);
                        ans=0;
                        mp[s[i]]++;
                    }
                    else
                    {
                        possible=true;
                    }
                }
            }
            else
            {
                if(dq[ans-1]==s[i])
                {
                    ans--;
                }
                else if(dq[ans+1]==s[i])
                {
                    ans++;
                }
                else
                {
                    possible=true;
                }
            }
        }
    }
    if(possible)
    {
        cout<<"NO\n";
    }
    else
    {
        cout<<"YES\n";
        for(int i=0;i<dq.size();++i)
        {
            cout<<dq[i];
        }
        char ch='a';
        ch--;
        for(int i=0;i<26;++i)
        {
            ch++;
            if(mp[ch]==0)
            {
                cout<<ch;
            }
        }
        cout<<endl;
    }
    assert(dq.size()<=n && dq.size()>=1);
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