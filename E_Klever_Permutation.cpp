#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>Answer;
    Answer.assign(n,-1);
    int first=1;
    for(int i=0;i<k;i+=2)
    {
        for(int j=i;j<n;j+=k)
        {
            Answer[j]=first;
            first++;
        }
    }
    int last=n;
    for(int i=1;i<k;i+=2)
    {
        for(int j=i;j<n;j+=k)
        {
            Answer[j]=last;
            last--;
        }
    }
    for(int i=0;i<n;++i)
    {
        cout<<Answer[i]<<" ";
    }
    cout<<endl;
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