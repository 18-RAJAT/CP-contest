#include<bits/stdc++.h>
using namespace std;
void sol()
{
    int a,b,c,k;cin>>a>>b>>c>>k;
    function<int(int,int)>power=[&](int b,int p)->int
    {
        int ans=1;
        while(p--)
        {
            ans*=b;
        }
        return ans;
    };
    int pw1=9*power(10,a-1);
    int pw2=9*power(10,b-1);

    if(pw1*pw2<k)
    {
        cout<<"-1"<<"\n";
    }
    else if(c==max<int>(a,b) or c==max<int>(a,b)+1)
    {
        int rhsMin=power(10,c-1);
        int rhsMax=power(10,c)-1;

        int vals1=power(10,a-1);
        int vals2=power(10,a)-1;

        int ert1=power(10,b-1);
        int ert2=power(10,b)-1;

        for(int i=vals1,j=vals2;i<=j;++i)
        {
            int mini=max<int>(ert1,rhsMin-i);
            int maxi=min<int>(ert2,rhsMax-i);

            if(maxi<mini)
            {
                continue;
            }
            int rangeOfAll=maxi-mini+1;
            if(rangeOfAll>k)
            {
                k-=rangeOfAll;
            }
            else
            {
                cout<<i<<" + "<<mini+k-1<<" = "<<i+mini+k-1<<"\n";
                return;
            }
        }
    }
    else
    {
        cout<<"-1"<<"\n";
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return(0-0);
}