// answ = [[1], [13, 14, 31]]

// for i in range(2, 50):
//     arr = []
//     for x in answ[i - 1]:
//         arr.append(x * 10)
//     arr.append(10 ** i + 3)
//     arr.append(3 * 10 ** i + 1)
//     answ.append(arr)

// t = int(input())

// while t > 0:
//     t -= 1
//     n = int(input())
//     x = n // 2
//     for i in answ[x]:
//         print(i * i)

// convert c++
#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<"1\n";
        return;
    }
    cout<<196<<string(n-3,'0')<<endl;
    for(int i=0;i<n/2;++i)
    {
        cout<<1<<string(i,'0')<<6<<string(i,'0')<<9<<string(n-3-i*2,'0')<<endl;
        cout<<9<<string(i,'0')<<6<<string(i,'0')<<1<<string(n-3-i*2,'0')<<endl;
    }
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