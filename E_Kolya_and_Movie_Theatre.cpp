#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,d;
    cin>>n>>m>>d;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    multiset<int>SelectedMovies;
    int current=0,ans=0;
    for(int i=0;i<n;++i)
    {
        if(a[i]<=0)continue;
        int LastDay=i+1;
        if(SelectedMovies.size()<m)
        {
            SelectedMovies.insert(a[i]);
            current+=a[i];
        }
        else
        {
            int minValue=*SelectedMovies.begin();
            if(minValue<a[i])
            {
                SelectedMovies.erase(SelectedMovies.begin());
                SelectedMovies.insert(a[i]);
                current=current-minValue+a[i];
            }
        }
        ans=max(ans,current-LastDay*d);
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