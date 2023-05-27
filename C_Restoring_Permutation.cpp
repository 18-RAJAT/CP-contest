#include<bits/stdc++.h>
using namespace std;

void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto&it:a)
    {
        cin>>it;
    }
    vector<int>checkTime(2*n);
    unordered_set<int>permutation;
    // for(int i=0;i<n;++i)
    for(auto&itr:a)
    {
        permutation.insert(itr);
    }
    deque<int>FindLexicographically(2*n+1,0);
    for(int i=0;i<n;++i)
    {
        checkTime[2*i]=a[i];
    }
    for(int i=1;i<=2*n;++i)
    {
        if(permutation.find(i)==permutation.end())
        {
            // FindLexicographically.push_back(i);
            FindLexicographically[i]=1;
        }
    }
    int ok=1;
    for(int i=0;i<n;++i)
    {
        bool flag=false;
        for(int j=a[i]+1;j<=2*n;++j)
        {
            if(FindLexicographically[j]==1)
            {
                FindLexicographically[j]=0;
                checkTime[2*i+1]=j;
                flag=true;
                break;
            }
        }
        if(not flag&1)
        {
            ok=0;
            break;
        }
    }
    // for(int i=0;i<2*n;++i)
    // {
    //     cout<<checkTime[i]<<" "<<checkTime[i+1]<<"\n";
    // }
    if(not ok)
    {
        cout<<-1<<"\n";
        return;
    }
    else
    {
        for(auto&it:checkTime)
        {
            cout<<it<<" ";
        }
    }
    cout<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        sol();
    }
    return 0;
}