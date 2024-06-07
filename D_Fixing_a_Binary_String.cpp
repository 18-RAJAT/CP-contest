#include<bits/stdc++.h>
using namespace std;
#define int long long
char ch[100005];
bool recur(int n,int k)
{
    for(int i=1;i<k;++i)
    {
        if(ch[0]!=ch[i])return false;
    }
    for(int i=k;i<n;++i)
    {
        if(ch[i]==ch[i-k])return false;
    }
    return true;
}
void sol()
{
    int n,k;
    cin>>n>>k;
    cin>>ch;
    if(recur(n,k))
    {
        cout<<n<<endl;
        return;
    }
    int i=0;
    while(i<n)
    {
        int j=i+1;
        while(j<n && ch[i]==ch[j])
        {
            j++;
        }
        if(j-i!=k)
        {
            int calc=i+((j-i)%k-k)%k+k;
            reverse(ch+calc,ch+n);
            cout<<(recur(n,k)?calc:-1)<<endl;
            return;
        }
        i=j;
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