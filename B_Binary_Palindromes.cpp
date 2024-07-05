#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s[n];
    int odd=0,even=0,one=0,zero=0;
    for(int i=0;i<n;++i)
    {
        cin>>s[i];
        for(auto& it:s[i])
        {
            (it=='1'?one++:zero++);
        }
        (s[i].length()%2==0)?even++:odd++;
    }
    if(odd==0)
    {
        if(one&1 || zero&1)
        {
            cout<<n-1<<endl;
            return;
        }
    }
    cout<<n<<endl;
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