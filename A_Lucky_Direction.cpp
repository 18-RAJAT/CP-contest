#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string d;
    cin>>d;
    if(d=="N")cout<<"S"<<endl;
    else if(d=="S")cout<<"N"<<endl;
    else if(d=="E")cout<<"W"<<endl;
    else if(d=="W")cout<<"E"<<endl;
    else if(d=="NE")cout<<"SW"<<endl;
    else if(d=="SW")cout<<"NE"<<endl;
    else if(d=="NW")cout<<"SE"<<endl;
    else cout<<"NW"<<endl;
}
signed main()
{
    sol(); 
    return 0;
}