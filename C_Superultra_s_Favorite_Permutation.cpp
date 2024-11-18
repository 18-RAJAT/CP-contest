#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    if(n<5)
    {
        cout<<"-1"<<endl;
        return;
    }
    else
    {
        vector<int>neg,pos;
        for(int i=1;i<=n;++i)
        {
            if(i&1)neg.push_back(i);
            else pos.push_back(i);
        }
        auto it=find_if(neg.begin(),neg.end(),[&](int x){return x==5;});
        if(it!=neg.end())
        {
            iter_swap(it,neg.end()-1);
        }
        auto it1=find_if(pos.begin(),pos.end(),[&](int x){return x==4;});
        if(it1!=pos.end())
        {
            rotate(pos.begin(),it1,it1+1);
        }
        auto it2=find_if(neg.begin(),neg.end(),[&](int x){return x==3;});
        if(it2!=neg.end())
        {
            swap(*it2,neg.back());
            neg.pop_back();
        }
        auto it3=find_if(pos.begin(),pos.end(),[&](int x){return x==2;});
        if(it3!=pos.end())
        {
            rotate(pos.begin(),it3,it3+1);
        }
        auto it4=find_if(neg.begin(),neg.end(),[&](int x){return x==1;});
        if(it4!=neg.end())
        {
            rotate(neg.begin(),it4,it4+1);
        }
        // cout<<neg.size()<<" "<<pos.size()<<endl;
        // for(auto& it:neg)cout<<it<<" ";
        // cout<<endl;
        // for(auto& it:pos)cout<<it<<" ";
        // cout<<endl;
        vector<int>ans=neg;
        ans.insert(ans.end(),pos.begin(),pos.end());
        for(auto& it:ans)
        {
            if(it>=1)cout<<" ";
            cout<<it;
        }
        cout<<endl;
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