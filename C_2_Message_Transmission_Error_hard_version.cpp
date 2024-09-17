#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int>ComputeZFunction(string& s)
{
    int n=s.size();
    vector<int>Z(n);
    int left=0,right=0;
    for(int i=1;i<n;++i)
    {
        if(i<right)
        {
            Z[i]=min(right-i,Z[i-left]);
        }
        while(i+Z[i]<n && s[Z[i]]==s[i+Z[i]])Z[i]++;
        if(right<i+Z[i])left=i,right=i+Z[i];
    }
    return Z;
}
void sol()
{
    string s;
    cin>>s;
    vector<int>ZArray=ComputeZFunction(s);
    vector<int>::iterator ans=ZArray.end();
    for(int i=0;i<(s.size()+1)/2;++i)
    {
        if(ZArray[i]+i==s.size())
        {
            ans=ZArray.begin()+i;
            break;
        }
    }
    if(ans!=ZArray.end())
    {
        cout<<"YES"<<endl;
        cout<<string(s.begin()+distance(ZArray.begin(),ans),s.end());
    }
    else
    {
        cout<<"NO"<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}