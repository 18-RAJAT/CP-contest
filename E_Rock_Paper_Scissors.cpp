#include<bits/stdc++.h>
using namespace std;

int alice[3];
int bob[3];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<3;++i)
    {
        cin>>alice[i];
    }
    for(int i=0;i<3;++i)
    {
        cin>>bob[i];
    }
    int maximumNumberOfRounds=0;

    maximumNumberOfRounds=min(alice[0],bob[1])+min(alice[1],bob[2])+min(alice[2],bob[0]);
    if((bob[0]+bob[2])<alice[0])
    {
        cout<<alice[0]-bob[0]-bob[2]<<" "<<maximumNumberOfRounds<<"\n";
    }
    else if((bob[1]+bob[0])<alice[1])
    {
        cout<<alice[1]-bob[0]-bob[1]<<" "<<maximumNumberOfRounds<<"\n";
    }
    else if((bob[2]+bob[1])<alice[2])
    {
        cout<<alice[2]-bob[1]-bob[2]<<" "<<maximumNumberOfRounds<<"\n";
    }
    else
    {
        cout<<"0"<<" "<<maximumNumberOfRounds<<"\n";
    }
    return 0;
}