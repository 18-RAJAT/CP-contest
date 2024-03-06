#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    map<int,int>mp;
    set<int>seg1,seg2;
    mp.clear();
    seg1.clear();
    seg2.clear();
    for(int i=0;i<n;++i)
    {
        mp[a[i]]++;
    }
    int j=0;
    auto print=[&]()->void
    {
        cout<<seg1.size()+seg2.size()<<endl;
        for(auto i:seg1)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        for(auto i:seg2)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    };
    while(mp[j]>1)
    {
        seg1.insert(j);
        seg2.insert(j);
        j++;
    }
    if(mp[j]>=1)
    {
        cout<<-1<<endl;
    }
    else
    {
        int mex=0;
        for(int i=0;i<n;++i)
        {
            if(seg1.count(a[i]))
            {
                seg1.erase(a[i]);
            }
            if(seg1.size()==0)
            {
                mex=i+1;
                break;
            }
        }
        for(int i=mex;i<n;++i)
        {
            if(seg2.count(a[i]))
            {
                seg2.erase(a[i]);
            }
        }
        if(seg2.size()==0)
        {
            cout<<2<<endl;
            cout<<1<<" "<<mex<<endl;
            cout<<mex+1<<" "<<n<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
        // print();
    }
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