#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)cin>>b[i];
    vector<pair<int,int>>heap(n);
    for(int i=0;i<n;++i)heap[i]=make_pair(a[i],i);
    make_heap(heap.begin(),heap.end(),greater<pair<int,int>>());
    int ans=0;
    for(int i=0;i<k;++i)
    {
        pop_heap(heap.begin(),heap.end(),greater<pair<int,int>>());
        auto [p,q]=heap.back();
        heap.pop_back();
        // int tmp=0;
        // for(int j=1;j<n;++j)
        // {
        //     if(a[tmp]<a[j])tmp=j;
        // }
        // int maxi=max_element(a.begin(),a.end())-a.begin();
        // ans+=a[maxi];
        if(p==0)break;
        // a[maxi]=max<int>(0,a[maxi]-b[maxi]);
        ans+=p;
        // if(all_of(a.begin(),a.end(),[](int check){return check==0;}))
        int maxi=max<int>(0,p-b[q]);
        if(maxi>=1)
        {
            heap.push_back(make_pair(maxi,q));
            push_heap(heap.begin(),heap.end(),greater<pair<int,int>>());
        }
        // {
        //     break;
        // }
        // if(a[tmp]==0)break;
        // ans+=a[tmp];
        // a[tmp]=max<int>(0,a[tmp]-b[tmp]);
    }
    cout<<ans<<endl;
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