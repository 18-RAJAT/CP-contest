#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    char column,row;
    cin>>column>>row;
    for(auto col='a';col<='h';++col)
    {
        if(col==column)
        {
            continue;
        }
        cout<<col<<row<<endl;
    }
    for(auto ro='1';ro<='8';++ro)
    {
        if(ro==row)
        {
            continue;
        }
        cout<<column<<ro<<endl;
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