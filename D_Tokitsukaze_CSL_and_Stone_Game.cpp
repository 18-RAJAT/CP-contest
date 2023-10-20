#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    auto win=[&]()->void
    {
        cout<<"sjfnb";
    };
    auto lose=[&]()->void
    {
        cout<<"cslnb";
    };
    int a[n];
    int sum=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sort(a,a+n);
    int bad=0;
    int cnt1=-1,cnt2=-1;
    for(int i=1;i<n;++i)
    {
        if(a[i]==a[i-1])
        {
            bad++;
            cnt1=i-1,cnt2=i;
        }
    }
    if(bad>=2)
    {
        lose();
        return;
    }
    if(bad==1)
    {
        if(a[0]==0)
        {
            lose();
            return;
        }
        if(a[0]==1)
        {
            a[0]--;
            bad--;
        }
        if(a[cnt1]==0)
        {
            lose();
            return;
        }
        if(cnt1!=0 && a[cnt1]-1==a[cnt1-1])
        {
            lose();
            return;
        }
        if(cnt1!=n-1 && a[cnt1]-1==a[cnt1+1])
        {
            lose();
            return;
        }
        if(cnt2!=n-1 && a[cnt2]-1==a[cnt2+1])
        {
            lose();
            return;
        }
        if(cnt2!=0 && a[cnt2]-1==a[cnt2-1])
        {
            lose();
            return;
        }
        if(cnt1!=0 && a[cnt1]-2==a[cnt1-1])
        {
            lose();
            return;
        }
        if(cnt1!=n-1 && a[cnt1]-2==a[cnt1+1])
        {
            lose();
            return;
        }
        if(cnt2!=n-1 && a[cnt2]-2==a[cnt2+1])
        {
            lose();
            return;
        }
    }
    if(n==1 && a[0]==0)
    {
        lose();
        return;
    }
    if(sum%2==0)
    {
        win();
    }
    else if(bad==1)
    {
        win();
    }
    else if(bad==2)
    {
        lose();
    }
    else if(bad==0)
    {
        lose();
    }
    else
    {
        lose();
    }
}
signed main()
{
    sol();
    return 0;
}