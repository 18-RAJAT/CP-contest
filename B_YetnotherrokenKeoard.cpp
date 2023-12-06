#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    vector<int>upper_character,lower_character;
    int n=s.size();

    auto is_upper=[](char c)->bool
    {
        return c>='A'&&c<='Z'?true:false;
    };
    
    auto is_lower=[](char c)->bool
    {
        return c>='a'&&c<='z'?true:false;
    };

    for(int i=0;i<n;++i)
    {
        if(s[i]=='B')
        {
            if(upper_character.size())
            {
                upper_character.pop_back();
            }
        }
        else if(s[i]=='b')
        {
            if(lower_character.size())
            {
                lower_character.pop_back();
            }
        }
        else if(is_upper(s[i]))
        {
            upper_character.push_back(i);
        }
        else if(is_lower(s[i]))
        {
            lower_character.push_back(i);
        }
        else
        {
            lower_character.push_back(i);
        }
    }
    set<int>st(lower_character.begin(),lower_character.end());
    for(auto& it:upper_character)
    {
        st.insert(it);
    }
    for(auto& it:st)
    {
        cout<<s[it];
    }
    cout<<endl;
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