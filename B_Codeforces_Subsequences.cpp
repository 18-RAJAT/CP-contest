#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;cin>>n;
    vector<long long int>array(10,1);
    long long int current=1;
    long long int index=0;

    while(current<n)
    {
        current/=array[index];
        array[index]++;
        current*=array[index];
        index=(index+1)%10;
    }

    auto printAllPossible=[&](char character,long long int numberOfTime)->auto
    {
        for(long long int i=0;i<numberOfTime;++i)
        {
            cout<<character;
        }
    };
    printAllPossible('c',array[0]);
    printAllPossible('o',array[1]);
    printAllPossible('d',array[2]);
    printAllPossible('e',array[3]);
    printAllPossible('f',array[4]);
    printAllPossible('o',array[5]);
    printAllPossible('r',array[6]);
    printAllPossible('c',array[7]);
    printAllPossible('e',array[8]);
    printAllPossible('s',array[9]);

    return 0;
}