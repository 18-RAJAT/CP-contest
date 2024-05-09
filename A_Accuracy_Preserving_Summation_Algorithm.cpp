#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;
#define int long long

struct Algo
{
    char type;
    vector<int>val;
};
double check_condition(double x,int*exp)
{
    *exp=0;
    if(x==0.0) return 0.0;
    while(abs(x)>=1.0)
    {
        x/=2.0;
        ++*exp;
    }
    while(abs(x)<0.5)
    {
        x*=2.0;
        --*exp;
    }
    return x;
}

Algo sum_sequence(const vector<double>&seq)
{
    Algo ans;
    if(seq.size()==1)
    {
        ans.type='d';
        ans.val.push_back(1);
    }
    else if(seq.size()==2)
    {
        ans.type='d';
        ans.val.push_back(1);
        ans.val.push_back(2);
    }
    else if(seq.size()==3)
    {
        ans.type='d';
        ans.val.push_back(1);
        ans.val.push_back(2);
        ans.val.push_back(3);
    }
    else
    {
        if(seq.size()%2==0)
        {
            ans.type='d';
            for(int i=1;i<=seq.size();++i)
            {
                ans.val.push_back(i);
            }
        }
        else
        {
            ans.type='f';
            int exp=0;
            double sum=0.0;
            for(int i=0;i<seq.size();++i)
            {
                sum+=check_condition(seq[i],&exp);
            }
            ans.val.push_back(exp);
            ans.val.push_back(sum);
        }
    }
    return ans;
}

void sol()
{
    int N;
    cin>>N;
    vector<double>seq(N);
    for(int i=0;i<N;++i)
    {
        cin>>seq[i];
    }

    Algo ans=sum_sequence(seq);

    cout<<"{"<<ans.type<<":";
    for(int i=0;i<ans.val.size();++i)
    {
        cout<<ans.val[i];
        if(i<ans.val.size()-1) cout<<",";
    }
    cout<<"}"<<endl;
}

signed main()
{
    sol();
    return 0;
}