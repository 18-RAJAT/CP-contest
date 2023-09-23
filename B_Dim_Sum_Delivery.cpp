#include<bits/stdc++.h>
using namespace std;
#define int long long
string alice(int R, int C, int A, int B)
{
    if(R%2==1 || C%2==1)
    {
        return "YES";
    }
    if(A==1 && B==1)
    {
        return "NO";
    }
    return "NO";
}
void sol()
{
    int R,C,A,B;
    cin>>R>>C>>A>>B;
    cout<<alice(R,C,A,B)<<endl;
}
signed main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<": ";
        sol();
    }
    return 0;
}