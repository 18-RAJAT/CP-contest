#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n;
    cin>>n;
    string temp="0";
    auto calculate_sum=[&](string& s)->int
    {
        int sum=0;
        for(auto& it:s)
        {
            sum+=(it-'0');
        }
        return sum;
    };
    temp+=s;
    int ans=0,sum=calculate_sum(s);
    int sz=temp.size();
    int i=sz-1,res=1;
    while(n<sum)
    {
        if(temp[i]!='0')
        {
            ans+=res*(10-(temp[i]-'0'));
            sum-=(temp[i]-'0');
            sum++;
            temp[i]='0';
            int j=i-1;
            while(j>=0 && temp[j]=='9')
            {
                temp[j]='0',j--,sum-=9;
            }
            temp[j]++;
        }
        i--,res*=10;
    }
    cout<<ans<<endl;
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