#include<bits/stdc++.h>
using namespace std;
#define int long long
//last test bottom->up move and achieve(ALL)
int combination[6]={4,8,15,16,23,42};
void sol()
{    
    int a[4];
    for(int i=0;i<4;++i)
    {
        cout<<"? "<<i+1<<" "<<i+3<<endl;
        cin>>a[i];
    }
    do
    {
        int ok=0;
        for(int i=0;i<4;++i)
        {
            int lost=combination[i]*combination[i+2];
            if(lost!=a[i])
            {
                ok=1;
                break;
            }
        }
        if(!ok)break;
    }while(next_permutation(combination,combination+6));
    cout<<"!";
    for(int i=0;i<6;++i)
    {
        cout<<" "<<combination[i];
    }
}
signed main()
{
    sol();
    return 0;
}