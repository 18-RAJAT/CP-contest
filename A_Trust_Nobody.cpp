#include<bits/stdc++.h>
using namespace std;

void sol()
{
    int n;
    cin>>n;
    vector<int>array(n);
    for(int i=0;i<n;++i)
    {
        cin>>array[i];
    }
    for(int i=0;i<n;++i)
    {
        long long int liars=0;
        for(int j=0;j<n;++j)
        {
            if(i<array[j])
            {
                // liars+=array[j]-i;
                liars++;
            }
        }
        if(liars==i)
        {
            cout<<i<<"\n";
            return;
        }
    }
    cout<<-1<<"\n";
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