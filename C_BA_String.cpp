#include<bits/stdc++.h>
using namespace std;
#define int long long
int store[100005];
void sol()
{
    int n,k,x;
    cin>>n>>k>>x;
    string s;
    cin>>s;
    s='a'+s;
    reverse(s.begin(),s.end());
    int count=0,chars=0;
    for(int i=0;s[i];++i)
    {
        if(s[i]=='*')
        {
            chars++;
        }
        else if(chars>=1)
        {
            int res=(chars*k+1);
            store[++count]=(x-1)%res,x/=res;
            chars=0;
        }
    }
    reverse(s.begin(),s.end());
    sort(store,store+count);
    for(int i=1;s[i];++i)
    {
        if(s[i]=='a')
        {
            cout<<'a';
        }
        else if(i==1 || s[i-1]!='*')
        {
            while(store[count]--)
            {
                cout<<'b';
            }
            count--;
        }
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