#include <bits/stdc++.h>
#define nl "\n"
#define ll long long
#define loop x == '#' x == '@' ||x == '*'  x == '&'
#define loop1  x >= 'A'  and  x <= 'Z'
#define loop2 s.size() < 7
#define loop3
#define loop4
#define pb push_back
#define all(v) v.begin(),v.end()
#define vll vector<ll>
#define inf 1999999996000000010

using namespace std;
void solve()
{
     long long x,y,z;
         cin>>x>>y>>z;
          y = y + z;
          ll val = 0;
        long long total =(x*(x+1))/2;
     
         
        if((total%y) == 0 )
        {
            cout<<"POSSIBLE"<<endl;
            y = total/y;
             z  = z*y;
            total = x;
           
            
            vll vc(total+3);
            for(int i = 1; i <= total; i++) {
             if(i >= 1) {
                vc[i-1]=i;
            }
        }
            
            for(ll i = total-1;i >= 0; i--)
            {
                if(vc[i] <= z)
                
                    z = z - vc[i],
                    vc[i]=0;
                
            }
          
            for(auto it: vc){
                if(it != 0)
                   ++val;
            }
            
            cout<<val<<endl;
            for(int i =0; i < total; ++i) {
                if(vc[i] > 0 || vc[i] < 0) {
                
                    cout<<i+1<<" ";
                }
                
            }
            cout<<endl;
        }
        else{
            cout<<"IMPOSSIBLE";
            cout << endl;
        }
        }
    

int main() {
ll k;
  cin >> k;
 ll temp = k;
 while (k--) {
  cout << "Case #" << temp - k << ": ";
  solve();
 }

 return 0;
}