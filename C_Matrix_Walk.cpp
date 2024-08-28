#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e9;
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    set<int>st;
    for(int i=1;i<n;++i)
    {
        if(a[i]==a[i-1])
        {
            cout<<"NO";
            return;
        }
        if(abs(a[i]-a[i-1])==1)continue;
        else st.insert(abs(a[i]-a[i-1]));
    }
    if(st.size()>=2)cout<<"NO";
    else
    {
        st.insert(N);
        for(int i=1;i<n;++i)
        {
            int x=abs(a[i]-a[i-1])==1,y=min(a[i],a[i-1])%(*st.begin())==0;
            if(x && y)
            {
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"YES"<<endl;
        cout<<N<<" "<<(*st.begin())<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}