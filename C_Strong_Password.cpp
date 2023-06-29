#include<bits/stdc++.h>
using namespace std;
void sol()
{
	string s,l,r;
    int m;
    cin>>s>>m>>l>>r;
    int n=s.size()-1;

    for(int i=m-1;i>=0;--i)
    {
        unordered_set<char>st;
        for(int j=l[i];j<=r[i];++j)
        {
            st.insert(j);
        }
        while(!st.empty() && n>=0)
        {
            if(st.count(s[n]));
            {
                st.erase(s[n]);
            }
            --n;
        }
        if(!st.empty())
        {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
    	sol();   
    }
}