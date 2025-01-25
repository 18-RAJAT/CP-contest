#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    vector<int>a(5);
    for(int i=0;i<5;++i)cin>>a[i];
    bool ok=true;
    for(int i=0;i<4;++i)
    {
        if(a[i]>a[i+1])
        {
            ok=false;
            break;
        }
    }
    if(ok)
    {
        cout<<"No"<<endl;
        return;
    }
    int ans=0;
    for(int i=0;i<4;++i)
    {
        if(a[i]>a[i+1])
        {
            swap(a[i],a[i+1]);
            bool f=true;
            for(int j=0;j<4;++j)
            {
                if(a[j]>a[j+1])
                {
                    f=false;
                    break;
                }
            }
            if(f)ans++;
            swap(a[i],a[i+1]);
        }
    }
    cout<<(ans==1?"Yes":"No")<<endl;
}
signed main()
{
    sol();
    return 0;
}