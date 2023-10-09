#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.length();
    int pos;
    cin>>pos;
    stack<char>st,st2;
    char ans;
    int idx=0;
    for(int i=0;i<n;++i)
    {
        //considering the case when pos is negative
        int calc=n-i;//no of ele
        if(pos-(calc)>=1)
        {
            pos-=calc;
        }
        //considering the case when pos is positive
        else
        {
            idx=i;
            break;
        }
    }
    for(int i=0;i<n;++i)
    {
        while(!st.empty() && st.top()>s[i] && idx>=1)
        {
            st.pop();
            idx--;
        }
        // while(idx>=1)
        // {
        //     st.pop();
        //     idx--;
        // }
        st.push(s[i]);
    }
    while(idx>=1)
    {
        st.pop();
        idx--;
    }
    while(!st.empty())
    {
        st2.push(st.top());
        st.pop();
    }
    // while(!st2.empty())
    // {
    //     cout<<st2.top();
    //     st2.pop();
    // }
    for(int i=0;i<pos;++i)
    {
        ans=st2.top();
        st2.pop();
    }
    cout<<ans;
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