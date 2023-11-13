#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>ans;
    set<int>st,check;
    st.clear(),check.clear();
    int ok=0;
    int size=0;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        if(x<0)
        {
            size--; 
            st.erase(abs(x));
        }
        else
        {
            size++;
            st.insert(x);
        }
        int sza=check.size();
        check.insert(x);
        if(sza==check.size())
        {
            cout<<"-1\n";
            return;
        }
        if(st.size()==0 && size==0)
        {
            ans.push_back(i-ok+1);
            ok+=i-ok+1;
            check.clear();
        }
    }
    if(st.size()!=0 || check.size()!=0)
    {
        cout<<"-1\n";
        return;
    }
    cout<<ans.size()<<endl;
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
}
signed main()
{
    sol();
    return 0;
}