#include<bits/stdc++.h>
using namespace std;

void sol()
{
    long long int n;
    cin>>n;

    vector<long long int>array(n);

    for(auto &it:array)
    {
        cin>>it;
    }

    map<long long int,long long int>magicTriples;
    for(auto &it:array)
    {
        magicTriples[it]++;
    }
    //ncr
    function<long long int(long long int,long long int)>ncr=[&](long long int n,long long int r)->long long int
    {
        if(n<r)
        {
            return 0;
        }
        if(n==r)
        {
            return 1;
        }
        if(r==1)
        {
            return n;
        }
        if(r==0)
        {
            return 1;
        }
        return ncr(n-1,r-1)+ncr(n-1,r);
    };

    long long int count=0;
    for(auto& it:magicTriples)
    {
        // count+=it.second*(it.second-1)*(it.second-2)/6;
        if(it.second>=3)
        {
            // count+=ncr(it.second,(long long)3)*6;
            count+=(it.second-1)*(it.second-2)*it.second;///6;
        }
        for(int i=2;i*i<=it.first;++i)
        {
            if(it.first%i==0)
            {
                if(magicTriples.find(it.first/i)!=magicTriples.end() and magicTriples.find(it.first*i)!=magicTriples.end())
                // cout<<it.first<<" "<<i<<" "<<it.first/i<<" "<<it.first*i<<"\n";

                count+=it.second*magicTriples[it.first/i]*magicTriples[it.first*i];

                if(it.first==i*i)
                {
                    // continue;
                    break;
                }
                // else if(magicTriples.find(i)!=magicTriples.end() and magicTriples.find(it.first/i)!=magicTriples.end())
                // {
                //     count+=it.second*magicTriples[i]*magicTriples[it.first/i];
                // }

                if(magicTriples.find(i)!=magicTriples.end() and magicTriples.find(it.first*(it.first/i))!=magicTriples.end())
                {
                    count+=it.second*(magicTriples[i]*magicTriples[it.first*(it.first/i)]);
                    // cout<<it.first<<" "<<i<<" "<<it.first/i<<" "<<it.first*i<<"\n";
                }
                // else if(magicTriples.find(it.first/i)!=magicTriples.end() and magicTriples.find(it.first*(it.first/i))!=magicTriples.end())
                // {
                //     count+=it.second*(magicTriples[it.first/i]*magicTriples[it.first*(it.first/i)]);
                //     // cout<<it.first<<" "<<i<<" "<<it.first/i<<" "<<it.first*i<<"\n";
                // }
                // else if(magicTriples.find(i)!=magicTriples.end() and magicTriples.find(it.first*(it.first/i))!=magicTriples.end())
                // {
                //     count+=it.second*(magicTriples[i]*magicTriples[it.first*(it.first/i)]);
                //     // cout<<it.first<<" "<<i<<" "<<it.first/i<<" "<<it.first*i<<"\n";
                // }
            }
        }
        if(it.first!=(long long)1 and magicTriples.find((long long) 1)!=magicTriples.end() and magicTriples.find(it.first*it.first)!=magicTriples.end())
        {
            count+=it.second*magicTriples[(long long)1]*magicTriples[it.first*it.first];
        }
        // else if(magicTriples.find(it.first*it.first)!=magicTriples.end())
        // {
        //     // count+=it.second*(it.second-1)*magicTriples[it.first*it.first]/2;
        //     count+=it.second*magicTriples[1]*magicTriples[it.first*it.first];
        // }
        // cout<<it.first<<" "<<count<<"\n";
    }
    cout<<count<<"\n";
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
