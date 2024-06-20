#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    int i=0,j=n-1,ans=0;
    set<int>st;
    while(i<j)
    {
        while(s[i]!='(' && i<n)i++;
        while(s[j]!=')' && j>=0)j--;
        if(i<j && s[i]=='(' && s[j]==')')
        {
            ans++,st.insert(i+1),st.insert(j+1),i++,j--;
        }
    }
    cout<<((ans)?"1":"0")<<endl;
    if(ans)
    {
        cout<<st.size()<<endl;
        for(auto&it:st)cout<<it<<" ";
    }
}
signed main()
{
    sol();
    return 0;
}