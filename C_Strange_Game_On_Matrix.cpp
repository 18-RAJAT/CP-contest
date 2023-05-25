#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,m,k;
    cin>>n>>m>>k;

    vector<vector<long long int>>matrix(n,vector<long long int>(m));

    for(auto& row:matrix)
    {
        for(auto& col:row)
        {
            cin>>col;
        }
    }
    long long int total=0,required=0;
    for(long long int i=0;i<=m-1;++i)
    {
        long long int position =-1;
        long long int colMaximum=0;
        long long int currentRequired=0;
        for(long long int j=0;j<=n-1;++j)
        {
            if(matrix[j][i])
            {
                position=j;

                long long int count=0;
                long long int remaining=k;
                for(long long int X=j;X<=n-1 and --remaining;++X)
                {
                    count+=matrix[X][i];
                }
                if(colMaximum<count)
                {
                    colMaximum=count;
                    currentRequired++;
                }
            }
        }
        if(position!=-1)
        {
            total+=colMaximum;
            required+=currentRequired-1;
        }
    }
    cout<<total<<" "<<required<<"\n";
}