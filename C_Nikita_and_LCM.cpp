#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a,int b)
{
    while(b!=0)
    {
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
void sol()
{
    int n;cin>>n;
    vector<int>a(n);
    for(auto&i:a)
    {
        cin>>i;
    } 
    vector<int>unique;
    sort(a.begin(),a.end());
    map<int,int>freq;
    for(auto&i:a)
    {
        freq[i]++;
    }
    for(auto& it:freq)
    {
        unique.push_back(it.first);
    }
    int length_max=0;
    for(int i=unique.size()-1;~i;--i)
    {
        int valid_freq=freq[unique[i]];
        bool ok=false;
        for(int j=i-1;j>=0;--j)
        {
            int x=unique[i],y=unique[j];
            int both_take=x*y;
            int value_of_lcm=both_take/(gcd(x,y));
            if(unique.back()<value_of_lcm)
            {
                ok=1,valid_freq=n;
                break;
            }
            if(freq[value_of_lcm]>=1 && value_of_lcm!=unique[i] && value_of_lcm!=0){continue;}
            valid_freq+=freq[unique[j]];
            unique[i]=value_of_lcm;
            if(freq[unique[i]]==0)length_max=max(length_max,valid_freq);
        }
        if(ok)length_max=n;
        if(freq[unique[i]]>=1){continue;}
        length_max=max(length_max,valid_freq);
    }
    cout<<length_max<<endl;
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