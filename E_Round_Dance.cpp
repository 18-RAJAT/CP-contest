#include<bits/stdc++.h>
using namespace std;

vector<set<int>>* adj;
vector<bool>* visited;

int linear=0,cyclic=0;

void check(int x)
{
    adj=new vector<set<int>>(x);
    visited=new vector<bool>(x,false);

    linear=0;
    cyclic=0;
}

void dfs(int i,bool& detectCycle,int parent=-1)
{
    (*visited)[i]=true;
    for(auto it:(*adj)[i])
    {
        if(not(*visited)[it])
        {
            dfs(it,detectCycle,i);
        }
        else if(it!=parent)
        {
            detectCycle=true;
        }
    }
}

void sol()
{
    int n;
    cin>>n;

    check(n);

    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        x--;

        (*adj)[x].insert(i);
        (*adj)[i].insert(x);
    }
    int connected=0;
    for(int i=0;i<n;++i)
    {
        if(not (*visited)[i])
        {
            bool isCycle=false;
            (*visited)[i]=true;

            dfs(i,isCycle);
            if(isCycle)
            {
                cyclic++;
            }
            else
            {
                linear++;
            }
        }
    }
    cout<<cyclic+((not linear==0)?1:0)<<" "<<cyclic+linear<<"\n";//cnf

    delete adj;
    delete visited;
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