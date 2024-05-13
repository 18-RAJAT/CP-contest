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
        else if(seq.size()%3==0)
        {
            ans.type='d';
            for(int i=1;i<=seq.size();++i)
            {
                ans.val.push_back(i);
            }
        }
        else if(seq.size()%5==0)
        {
            ans.type='d';
            for(int i=1;i<=seq.size();++i)
            {
                ans.val.push_back(i);
            }
        }
        else if(seq.size()%7==0)
        {
            ans.type='d';
            for(int i=1;i<=seq.size();++i)
            {
                ans.val.push_back(i);
            }
        }
        else if(seq.size()%11==0)
        {
            ans.type='d';
            for(int i=1;i<=seq.size();++i)
            {
                ans.val.push_back(i);
            }
        }
        else if(seq.size()%13==0)
        {
            ans.type='d';
            for(int i=1;i<=seq.size();++i)
            {
                ans.val.push_back(i);
            }
        }
        else if(seq.size()%17==0)
        {
            ans.type='d';
            for(int i=1;i<=seq.size();++i)
            {
                ans.val.push_back(i);
            }
        }
        else if(seq.size()%19==0)
        {
            ans.type='d';
            for(int i=1;i<=seq.size();++i)
            {
                ans.val.push_back(i);
            }
        }
        else if(seq.size()%23==0)
        {
            ans.type='d';
            for(int i=1;i<=seq.size();++i)
            {
                ans.val.push_back(i);
            }
        }
        else if(seq.size()%29==0)
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
            /*
                approach:
                1. check_condition() function is used to check the condition of the number.
                2. sum is used to store the sum of the numbers.
                3. loop through the sequence and add the condition of the number to sum.
                4. push the condition of the number and sum to the ans.val vector.
                5. return the ans.
            */
            double sum=0.0;
            for(int i=0;i<seq.size();++i)
            {
                sum+=check_condition(seq[i],&exp);
            }
            //print             
            for(int i=0;i<4;++i)
            {
                cout<<"{"<<ans.type<<":";
                for(int i=0;i<ans.val.size();++i)
                {
                    cout<<ans.val[i];
                    if(i<ans.val.size()-1) cout<<",";
                }
                for(int i=0;i<ans.val.size();++i)
                {
                    if(i==0)
                        cout<<"{";
                    cout<<ans.val[i];
                    if(i<ans.val.size()-1)
                        cout<<",";
                    if(i==ans.val.size()-1)
                        cout<<"}";
                }
                cout<<"}"<<endl;
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