#include<bits/stdc++.h>
using namespace std;

void sol()
{
    int n;
    cin>>n;
    vector<int>aux;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        if(aux.size()>=2)
        {
            int last=aux[aux.size()-1];
            int secondLast=aux[aux.size()-2];
            if(secondLast<=last and last<=x)
            {
                aux.pop_back();
            }
            else if(secondLast>=last and last>=x)
            {
                aux.pop_back();
            }
        }
        aux.push_back(x);
    }
    
    if(aux.size()==2)
    {
        if(aux[0]==aux[1])
        {
            aux.pop_back();
        }
    }
    cout<<aux.size()<<'\n';
}

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        sol();
    }
    return 0;
}