#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        int n,k;
        cin>>n>>k;
        vector<long long int>*a=new vector<long long int>(n);
        vector<long long int>*b=new vector<long long int>(n);
        vector<long long int>*temp=new vector<long long int>(n);
        vector<pair<long long int,long long int>>pairs;

        for(int i=0;i<n;i++)
        {
            cin>>(*a)[i];
            pairs.emplace_back(make_pair((*a)[i],i));
        }
        sort(pairs.begin(),pairs.end());
        for(int i=0;i<n;i++)
        {
            cin>>(*b)[i];
        }
        sort(b->begin(),b->end());
        for(int i=0;i<n;i++)
        {
            (*temp)[pairs[i].second]=(*b)[i];
        }
        for(int i=0;i<n;i++)
        {
            cout<<(*temp)[i]<<" ";
        }
        cout<<"\n";
        
        delete a;
        delete b;
        delete temp;
    }   
}