#include<bits/stdc++.h>
using namespace std;
#define int long long
string recur(vector<int>& a)
{
    map<int,int>freq;
    for(auto& x:a)
    {
        freq[x]++;
    }
    string sign;
    for(auto& it:freq)
    {
        sign+=to_string(it.first)+":"+to_string(it.second)+",";
    }
    return sign;
}
void sol()
{
    int N=5,M=5;
    set<string>st;
    for(int i=0;i<N;++i)
    {
        vector<int>a(M);
        for(int j=0;j<M;++j)
        {
            cin>>a[j];
        }
        string sign=recur(a);
        st.insert(sign);
    }
    cout<<st.size()<<endl;
}
signed main()
{
    sol();
    return 0;
}