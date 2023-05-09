#include<bits/stdc++.h>
using namespace std;

void sol()
{
    string s;
    cin>>s;
    set<char>st;
    for(int i=0;i<s.size();i++)
    {
        st.insert(s[i]);
    }
    if(st.size()==1)
    {
        cout<<"-1"<<"\n";
    }
    else
    {
        cout<<s.size()-1<<"\n";
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}