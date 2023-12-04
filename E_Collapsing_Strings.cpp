#include<bits/stdc++.h>
using namespace std;
#define int long long

int node[26][1000005];
int node_value[1000005];
int node_cnt=1,sum=0,ans=0;

int get(string s)
{
    node_cnt=0;
    int n=s.size();
    int ans=0;
    for(int i=0;i<n;++i)
    {
        ans+=s[i]-'0';
    }
    return ans;
}
void add(string s)
{
    int cur=0;
    for(int i=0;i<s.size();++i)
    {
        if(node[s[i]-'a'][cur])
        {
            cur=node[s[i]-'a'][cur];
        }
        else
        {
            node[s[i]-'a'][cur]=node_cnt;
            cur=node_cnt++;
        }
        // node[s[i]-'a'][cur]=node[s[i]-'a'][cur]?node[s[i]-'a'][cur]:node_cnt;
        node_value[cur]++;
    }
}

int occur(string s)
{
    int cur=0;
    int sum=0;
    for(int i=0;i<s.size();++i)
    {
        if(node[s[i]-'a'][cur])
        {
            cur=node[s[i]-'a'][cur];
        }
        else
        {
            break;
        }
        sum+=node_value[cur];
    }
    return sum;
}
void sol()
{
    int n;
    cin>>n;
    string word_dict[n];
    word_dict->resize(n+1);
    memset(node,0,sizeof(node));
    for(int i=1;i<=n;++i)
    {
        cin>>word_dict[i];
        sum+=word_dict[i].size()*(n*2);//inc for each word
        // cout<<sum;
        add(word_dict[i]);
    }
    for(int i=1;i<=n;++i)
    {
        // sort(word_dict[i].begin(),word_dict[i].end());
        reverse(word_dict[i].begin(),word_dict[i].end());
        sum-=occur(word_dict[i])*2;
    }
    cout<<sum<<endl;
}
signed main()
{
    sol();
    return 0;
}