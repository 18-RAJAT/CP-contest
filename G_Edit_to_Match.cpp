#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<string>s(n);
    for(int i=0;i<n;++i)cin>>s[i];
    struct TrieNode
    {
        int children[26],mn;
        TrieNode()
        {
            for(int i=0;i<26;++i)children[i]=-1;
            mn=INT64_MAX;
        }
    };
    vector<TrieNode>trie;
    trie.emplace_back();
    function<void(const string &)>insert=[&](const string &s)->void
    {
        int node=0;
        for(int i=0;i<s.size();++i)
        {
            int c=s[i]-'a';
            if(trie[node].children[c]==-1)
            {
                trie[node].children[c]=trie.size();
                trie.emplace_back();
            }
            node=trie[node].children[c];
            trie[node].mn=min<int>(trie[node].mn,s.size());
        }
    };
    function<int(const string &)>query=[&](const string &s)->int
    {
        int node=0,res=s.size();
        for(int i=0;i<s.size();++i)
        {
            int c=s[i]-'a';
            if(trie[node].children[c]==-1)break;
            node=trie[node].children[c];
            if(trie[node].mn!=INT64_MAX)
            {
                res=min<int>(res,s.size()+trie[node].mn-2*(i+1));
            }
        }
        return res;
    };
    for(int i=0;i<n;++i)
    {
        (i==0)?cout<<s[i].size()<<endl:cout<<query(s[i])<<endl;
        insert(s[i]);
    }
}
signed main()
{
    sol();
    return 0;
}