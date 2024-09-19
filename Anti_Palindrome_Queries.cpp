#include <bits/stdc++.h>
using namespace std;
#define int long long
void Combination(const vector<int>& a,int n,map<int,vector<int>>& count)
{
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=3;++j)
        {
            count[j][i]=count[j][i-1]+(a[i]==j);
        }
    }
}
string Query(int l,int r,const map<int,vector<int>>& count)
{
    if((r-l+1)&1)
    {
        return "No";
    }
    int ans=0,check=(r-l+1)/2;
    array<int,3>Palindrome;
    for(int i=1;i<=3;++i)
    {
        Palindrome[i-1]=count.at(i)[r]-count.at(i)[l-1];
        ans+=(Palindrome[i-1]>=check);
    }
    if(ans>0 && all_of(Palindrome.begin(),Palindrome.end(),[check](int x){return x<=check;}))
    {
        return "Yes";
    }
    return "No";
}

signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector<int>a(n+1);
        map<int,vector<int>>count;
        count[1]=vector<int>(n+1,0);
        count[2]=vector<int>(n+1,0);
        count[3]=vector<int>(n+1,0);
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
        }
        Combination(a,n,count);
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            cout<<Query(l,r,count)<<endl;
        }
    }
    return 0;
}