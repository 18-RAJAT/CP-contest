#include<bits/stdc++.h>
using namespace std;

void sol()
{
    auto count=[&](vector<long long int>&a)->long long int
    {
        long long int cnt=0;
        set<vector<long long int>>st;
        while(1)
        {
            vector<long long int>b(a.size());
            for(long long int i=0;i<a.size();++i)
            {
                b[i]=a[i]^a[(i+1)%a.size()];
            }
            if(a==b)
            {
                return (st.count(b)>1?-1:cnt);
            }
            if(st.count(b))
            {
                return -1;
            }
            st.insert(b);
            a=b;
            ++cnt;
        }
        return -1;
    };
    long long int n;cin>>n;
    vector<long long int>a(n);
    for(long long int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    cout<<count(a)<<"\n";
}
int main()
{
    sol();
    return 0;
}