#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int numsA=0,numsB=0,numsC=0,count=1;
    for(int i=1;i<=n;++i)
    {
        char element;
        cin>>element;

        if(element=='a')
        {
            numsA++;
            numsA%=1000000007;
        }
        if(element=='b')
        {
            numsB+=numsA;
            numsB%=1000000007;
        }
        if(element=='c')
        {
            numsC+=numsB;
            numsC%=1000000007;
        }
        if(element=='?')
        {
            numsC*=3;
            numsC+=numsB;

            numsB*=3;
            numsB+=numsA;

            numsA*=3;
            numsA+=count;
            
            count*=3;

            numsA%=1000000007; numsB%=1000000007; numsC%=1000000007; count%=1000000007;
        }
    }
    cout<<numsC<<"\n";
    return 0;
}