#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int m;cin>>m;
    vector<int>books(m);
    unordered_map<int,int>bookPosition;
    for(int i=0;i<m;++i)
    {
        cin>>books[i];
        bookPosition[books[i]]=i;
    }
    int n;
    cin>>n;
    vector<int>borrowedBooks(n);
    for(int i=0;i<n;++i)
    {
        int position;
        cin>>position;
        int bookIndex=position-1;
        borrowedBooks[i]=books[bookIndex];
        books.erase(books.begin()+bookIndex);
    }
    for(int i=0;i<n;++i)
    {
        cout<<borrowedBooks[i]<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}