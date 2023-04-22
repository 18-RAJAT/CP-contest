#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int main()
{
    long long int nCoordinate,mCoordinate;

    long long int cityNetwork[N];memset(cityNetwork,0,sizeof(cityNetwork));
    long long int cityTower[N];memset(cityTower,0,sizeof(cityTower));

    auto distance=[&](long long int minimalR)->bool
    {
        long long int initialStart=1;
        for(long long int i=1;i<=mCoordinate;++i)
        {
            while(initialStart<=nCoordinate and cityNetwork[initialStart]>=cityTower[i]-minimalR and cityNetwork[initialStart]<=cityTower[i]+minimalR)
            {
                initialStart++;
            }
            if(nCoordinate<initialStart)
            {
                return true;
            }
        }
        return false;
    };

    auto binarySearchToOptimalDistance=[&](long long int left,long long int right)->long long int
    {
        while(left<right)
        {
            long long int mid=left+(right-left)/2;
            if(distance(mid))
            {
                right=mid;
            }
            else
            {
                left=mid+1;
            }
        }
        return left;
    };
    
    cin>>nCoordinate>>mCoordinate;
    for(long long int i=1;i<=nCoordinate;++i)
    {
        cin>>cityNetwork[i];
    }
    for(long long int i=1;i<=mCoordinate;++i)
    {
        cin>>cityTower[i];
    }

    sort(cityNetwork+1,cityNetwork+nCoordinate+1);
    sort(cityTower+1,cityTower+mCoordinate+1);
    long long int source=0;
    long long int destination=2e9;

    cout<<binarySearchToOptimalDistance(source,destination);

    return 0;
}