#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int positive=0,negative=0;
    int prev=0,next=0;
    for(int i=0;i<n;++i)
    {
        if(a[i]>=0)
        {
            prev++;
        }
        else
        {
            swap<int>(prev,next);
            next++;
        }
        positive+=prev;
        negative+=next;
    }
    cout<<negative<<" "<<positive<<endl;
}
signed main()
{
    sol();
    return 0;
}