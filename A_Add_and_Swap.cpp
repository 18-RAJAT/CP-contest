#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    vector<int>ops;
    ops.reserve(500000);
    int ok=0;
    while(!is_sorted(a.begin(),a.end()) && ops.size()<500000)
    {
        bool op=false;
        for(int i=0;i<n-1;++i)
        {
            if(a[i]>a[i+1])
            {
                int tmp=a[i];
                a[i]=a[i+1]+k;
                a[i+1]=tmp;
                ops.push_back(i+1);
                op=true;
                if(ops.size()>=500000)break;
            }
        }
        if(!op)break;
    }
    if(is_sorted(a.begin(),a.end()) && ops.size()<=500000)
    {
        cout<<"Yes\n"<<ops.size()<<endl;
        for(int i=0;i<ops.size();++i)cout<<ops[i]<<" \n"[i==ops.size()-1];
    }
    else cout<<"No"<<endl;
}
signed main()
{
    sol();
    return 0;
}