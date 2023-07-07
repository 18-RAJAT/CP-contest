#include<bits/stdc++.h>
using namespace std;
void sol()
{
    int n;
    cin>>n;
    int a[100005];
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    int ans=0;
    set<int>st;
    st.clear();
    st.insert(0);

    for(int i=1;i<=n;++i)
    {
        a[i]^=a[i-1];
        for(auto it:st)
        {
            ans=max<int>(ans,a[i]^it);
        }
        st.insert(a[i]);
    }
    cout<<ans<<"\n";
}
int main()
{
	int t;
	cin>>t;
	while(t-->0)
	{
        sol();
	}
	return 0;
}