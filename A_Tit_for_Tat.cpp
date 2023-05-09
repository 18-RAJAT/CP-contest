#include<bits/stdc++.h>
using namespace std;

class sol
{
    int n,k;
    int* array;

    public:
    sol()
    {
        cin>>n>>k;
        array=new int[n];

        for(int i=0;i<n;++i)
        {
            cin>>array[i];
        }
        int pivot=0;
        while(pivot<n and k--)
        {
            // swap(array[pivot],array[n-1]);
            while(array[pivot]==0 and pivot<n-1)
            {
                pivot++;
            }
            array[pivot]--;
            array[n-1]++;
            // k--;
            // pivot++;
        }
        for(int i=0;i<n;++i)
        {
            cout<<array[i]<<" ";
        }
        cout<<"\n";
    }

    ~sol()
    {
        delete[] array;
    }
};

int main()
{
    int tc;
    cin>>tc;
    while(tc-->0)
    {
        sol solution;
    }
}