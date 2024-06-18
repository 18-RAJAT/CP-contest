#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a;
    int i,j,k;
    cout<<endl;
    cout<<"? 1 2\n\n";
    cin>>i;
    cout<<"? 1 3\n\n";
    cin>>j;
    cout<<"? 2 3\n\n";
    cin>>k;
    a.insert(a.end(),{(i+j+k)/2-k,i-((i+j+k)/2-k),j-((i+j+k)/2-k)});
    int q;
    for(int i=4;i<=n;++i)
    {
        cout<<"? 1 "<<i<<endl<<endl;
        cin>>q;
        a.push_back(q-a[0]);
    }
    cout<<"! ";
    for(int i=0;i<n;++i)cout<<a[i]<<" ";
}
signed main()
{
    sol();
    return 0;
}