#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<long long int>Array(n);
    for(auto& itr:Array)
    {
        cin>>itr;
    }

    unordered_map<long long,long long>subsegments;
    long long count=0;
    long long prefixSum=0;
    subsegments[0]++;
    for(int i=0;i<n;++i)
    {
        prefixSum+=Array[i];
        if(subsegments[prefixSum]>0)
        {
            subsegments.clear();
            subsegments[0]++;
            prefixSum=Array[i];
            subsegments[Array[i]]++;
            count++;
        }
        else
        {
            subsegments[prefixSum]++;
        }
    }
    cout<<count<<"\n";
}