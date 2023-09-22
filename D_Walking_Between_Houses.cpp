#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k,s;
    cin>>n>>k>>s;
    vector<int>ans;
    if(s<n || (n-1)*k<s)
    {
        cout<<"NO"<<endl;
        return;
    }
    int v=n,p=1,prev=1;
    int r,d;
    for(int i=0;i<k;i++)
    {
        r=k-i;
        if(s%r==0)
        {
            d=s/r;
            for(int j=0;j<r;j++)
            {
                if(prev>d)
                {
                    prev-=d;
                }
                else
                {
                    prev+=d;
                }
                ans.emplace_back(prev);
            }
            break;
        }
        else if(s-abs(v-p)<r)
        {
            bool f=false;
            if(v<p)
            {
                f=true;
            }
            while(s-abs(v-p)<r)
            {
                if(f)
                {
                    v++;
                }
                else
                {
                    p++;
                }
            }
            if(f)
            {
                ans.emplace_back(v);
            }
            else
            {
                ans.emplace_back(p);
            }
            swap(v,p);
        }
        else
        {
            ans.emplace_back(v);
            prev=v;
            s-=abs(v-p);
            swap(v,p);
        }
    }
    cout<<"YES"<<endl;
    for(auto& it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}
signed main()
{
    sol();
    return 0;
}