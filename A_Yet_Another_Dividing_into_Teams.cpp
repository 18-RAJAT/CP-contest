#include<bits/stdc++.h>
using namespace std;

void sol()
{
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;++i)
    {
        cin>>array[i];
    }
    int minimumNumberOfTeams=0;
    sort(array,array+n);
    for(int i=1;i<n;++i)
    {
        if(array[i]==1+array[i-1])
        {
            minimumNumberOfTeams=2;
            break;
        }
    }
    minimumNumberOfTeams=minimumNumberOfTeams==0?1:2;
    cout<<minimumNumberOfTeams<<"\n";
}

int main()
{
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
        sol();
    }
    return 0;
}