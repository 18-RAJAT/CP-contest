#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    set<int>squares;
    for(int i=0;i<n;++i)
    {
        string s;
        cin>>s;
        if(s.find('1')!=string::npos)
        {
            squares.insert(count(s.begin(),s.end(),'1'));
        }
        // squares.insert(count(s.begin(),s.end(),'1')^count(s.begin(),s.end(),'0'));
    }
    cout<<(squares.size()==1?"SQUARE":"TRIANGLE")<<endl;
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