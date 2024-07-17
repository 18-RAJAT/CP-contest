#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int r,g,b;
    cin>>r>>g>>b;
    string c;
    cin>>c;
    multiset<int>st={r,g,b};
    if(c=="Blue")st.erase(st.find(b));
    if(c=="Green")st.erase(st.find(g));
    if(c=="Red")st.erase(st.find(r));
    cout<<*st.begin();
}
signed main()
{
    sol();
    return 0;
}