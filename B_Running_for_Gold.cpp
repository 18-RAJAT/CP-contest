#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Athlete
{
    int array[5];
};
bool check(const Athlete &a, const Athlete &b)
{
    int count=0;
    for(int i=0;i<5;++i)
    {
        count+=a.array[i]<b.array[i];
    }
    return count>=3?true:false;
}
void sol()
{
    int n;
    cin>>n;
    vector<Athlete>athletes(n);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<5;++j)
        {
            cin>>athletes[i].array[j];
        }
    }
    vector<int>Answer(n);
    for(int i=0;i<n;++i)
    {
        Answer[i]=i;
    }
    for(int i=0;i<n;++i)
    {
        //Randomly shuffle the array to get a random permutation
        swap(Answer[i],Answer[rand()%n]);
        
        //another way to shuffle the array
        // random_shuffle(Answer.begin(),Answer.end());
    }
    for(int i=0;i<n;++i)
    {
        bool ranks=true;
        for(int j=0;j<n && ranks;++j)
        {
            if(i!=j)
            {
                ranks&=check(athletes[Answer[i]],athletes[Answer[j]]);
            }
            // cout<<Answer[i]<<" "<<Answer[j]<<" "<<ranks<<endl;
        }
        if(ranks)
        {
            cout<<Answer[i]+1<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}