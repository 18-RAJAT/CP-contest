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
double to_fp16(double x)
{
    //->check again
    if(isnan(x))
    {
        return NAN;
    }
    //state pause
    if(x==0.0)
    {
        return 0.0;
    }
    //pos
    if(x==numeric_limits<double>::infinity())
    {
        return numeric_limits<float>::infinity();
    }
    //neg
    if(x==-numeric_limits<double>::infinity())
    {
        return -numeric_limits<float>::infinity();
    }
    int sign=x<0?1:0;

    x=abs(x);
    int exp;
    double frac=check_condition(x,&exp);
    exp-=15;
    if(exp<-14)
    {
        frac=0.0;
        exp=-15;
    }
    else if(exp>15)
    {
        frac=numeric_limits<float>::infinity();
        exp=0;
    }
    else if(exp<-24)
    {
        frac=0.0;
        exp=0;
    }
    else if(exp>16)
    {
        frac=numeric_limits<float>::infinity();
        exp=0;
    }
    else if(exp==-15)
    {
        frac=0.0;
    }
    else if(exp==16)
    {
        frac=0.0;
        exp=0;
    }
    else
    {
        frac-=1.0;
    }
    int value=(sign<<15)|((exp+15)<<10)|(int)(frac*1024);
    value=(value>>16)|((value&0x0000FFFF)<<16);
    return *(float*)&value;
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
        ans.type='d';
        for(int i=1;i<=seq.size();++i)
        {
            ans.val.push_back(i);
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