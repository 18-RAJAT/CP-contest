#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    set<int>st;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        st.insert(x);
    }
    vector<int>ans;
    int nim=0;
    while(st.empty()==false)
    {
        int beg=*st.begin();
        ans.push_back(beg-nim);
        nim=beg;
        st.erase(st.begin());
    }
    int each=-1;
    for(int i=0;i<ans.size();++i)
    {
        if(ans[i]!=1)
        {
            each=i;
            break;
        }
    } 
    bool alice=true;
    ((~each)?(alice=each%2==0):(alice=ans.size()%2!=0));
    cout<<(alice?"Alice":"Bob")<<endl;
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