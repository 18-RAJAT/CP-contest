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
    pair<array<int,2>,int>pr={{1,2},3};
    int game=3;
    bool ok=true;
    for(int i=0;i<n;++i)
    {
        if(a[i]==pr.first[0])
        {
            swap(game,pr.first[1]);
        }
        else if(a[i]==pr.first[1])
        {
            swap(game,pr.first[0]);
        }
        else
        {
            ok=false;
            break;
        }
    }
    cout<<((ok)?"YES":"NO")<<endl;
}
signed main()
{
    sol();
    return 0;
}