#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int shuffledArray[n];
    memset(shuffledArray,0,sizeof(shuffledArray));

    for(int i=0;i<n;i++)
    {
        cin>>shuffledArray[i];
    }
    
    //all shuffledArray elements are distinct
    sort(shuffledArray,shuffledArray+n);

    int positiveLarge1=shuffledArray[n-1];

    //check if positiveLarge1 is divisible by all other elements of shuffledArray
    int copies[positiveLarge1+1];
    memset(copies,0,sizeof(copies));

    copies[0]=0;
    for(int i=1;i<=positiveLarge1;++i)
    {
        // if(positiveLarge1%shuffledArray[i]==0 and shuffledArray[i-1]!=1)
        // {
        //     shuffledArray[i]=1;
        // }
        //copies is use to store the divisibility of positiveLarge1 by all other elements of shuffledArray
        copies[i]=0;
        if((positiveLarge1%i)==0)
        {
            copies[i]=1;
        }
        else
        {
            copies[i]=0;
        }
    }
    // shuffledArray[n-1]=1;
    // sort(shuffledArray,shuffledArray+n);

    for(int i=0;i<n;++i)
    {
        //use copies to check if positiveLarge1 is divisible by all other elements of shuffledArray
        if(copies[shuffledArray[i]]==1)
        {
            copies[shuffledArray[i]]=0;
            shuffledArray[i]=0;
        }
    }
    sort(shuffledArray,shuffledArray+n);

    int positiveLarge2=shuffledArray[n-1];

    cout<<positiveLarge1<<" "<<positiveLarge2<<"\n";
}