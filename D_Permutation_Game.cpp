#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k,pb,ps;
    cin>>n>>k>>pb>>ps;
    vector<int>a(n),p(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>p[i];
    }
    int maximum=0;
    auto check=[&](int position,int move,int ans,int maximum,int current)->int
    {
        int i=0;
        while(i<n && move>0)
        {
            current=p[position-1]*move+ans;
            ans+=p[position-1];
            position=a[position-1];
            move--;
            if(current>maximum)
            {
                maximum=current;
            }
            i++;
        }
        return maximum;
    };
    maximum=check(pb,k,0,0,0);
    int max_Bodya=maximum;
    maximum=check(ps,k,0,0,0);
    int max_Sasha=maximum;
    if(max_Bodya>max_Sasha)
    {
        cout<<"Bodya";
    }
    else if(max_Bodya<max_Sasha)
    {
        cout<<"Sasha";
    }
    else
    {
        cout<<"Draw";
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