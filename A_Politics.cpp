#include<bits/stdc++.h>
using namespace std;

void sol()
{
    long long n,k;
    cin>>n>>k;
    string members;
    cin>>members;

    long long maximumNoOfMembers=1;
    for(int i=0;i<n-1;++i)
    {
        string meet;
        cin>>meet;

        // auto isSame=[&](string &a,string &b)->bool
        // {
        //     for(int i=0;i<k;++i)
        //     {
        //         if(a[i]!=b[i])
        //         {
        //             return false;
        //         }
        //     }
        //     return true;
        // };
        // maximumNoOfMembers+=!isSame(members,meet);

        if(members==meet)
        {
            maximumNoOfMembers+=1;
        }
        // maximumNoOfMembers+=members!=meet;
        // else
        // {
        //     members=meet;
        // }
    }
    cout<<maximumNoOfMembers<<"\n";
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