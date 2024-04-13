#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string x,y;
    cin>>x>>y;
    int n=x.size();
    for(int i=0;i<n;++i)
    {
        if(x[i]==y[i])
        {
            continue;
        }
        //skip
        if(x[i]>y[i]){}
        else
        {
            swap(x[i],y[i]);
        }
        for(int j=i+1;j<n;++j)
        {
            //skip
            if(x[j]<y[j]){continue;}
            else
            {
                swap(x[j],y[j]);
            }
        }
        break;
    }
    cout<<x<<endl<<y<<endl;
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