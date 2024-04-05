#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    cout<<(s.find('R')!=string::npos?s.find_first_of('R')+1:s.find_last_of('L')+1)<<" "<<(s.find('R')!=string::npos?s.find_last_of('R')+2:s.find_first_of('L'));

}
signed main()
{
    sol();
    return 0;
}