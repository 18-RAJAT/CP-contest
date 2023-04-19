#include<bits/stdc++.h>
using namespace std;

int main()
{
    int testCase;
    cin>>testCase;
    while(testCase--)
    {
        int n;
        cin>>n;
        vector<int>array(n);
        for(auto& itr:array)
        {
            cin>>itr;
        }
        for(int i=0;i<n;++i)
        {
            array[i]+=i;
            array[i]=(array[i]%n+n)%n;
        }
        sort(array.begin(),array.end());

        array.erase(unique(array.begin(),array.end()),array.end());
        puts(array.size()==n?"YES":"NO");
    }
    return 0;
}