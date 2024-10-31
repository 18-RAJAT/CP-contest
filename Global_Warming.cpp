#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 998244353;
const int MAX = 200005;

// Precompute factorial and inverse factorial
ll fact[MAX], inv_fact_arr[MAX];

// Fast exponentiation
ll power_pow(ll x, ll y, ll mod_val) {
    ll res = 1;
    x %= mod_val;
    while(y > 0){
        if(y & 1LL){
            res = res * x % mod_val;
        }
        x = x * x % mod_val;
        y >>=1LL;
    }
    return res;
}

// Function to compute binomial coefficients
ll C(int n, int k){
    if(n <0 || k <0 || n <k ) return 0;
    return (fact[n] * inv_fact_arr[k] % MOD ) * inv_fact_arr[n -k] % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // Precompute factorial
    fact[0] =1;
    for(int i=1;i<MAX;i++) fact[i] = fact[i-1] * i % MOD;
    
    // Precompute inverse factorial
    inv_fact_arr[MAX-1] = power_pow(fact[MAX-1], MOD-2, MOD);
    for(int i=MAX-2;i>=0;i--){
        inv_fact_arr[i] = inv_fact_arr[i+1] * (i+1) % MOD;
    }
    
    int T;
    cin >> T;
    while(T--){
        int N, K;
        cin >> N >> K;
        if(K <1 || K > N-1){
            // No valid sequences
            cout << "0\n";
            continue;
        }
        int n = N-2;
        int k = K-1;
        ll total_sequences = C(n, k);
        // Compute (N-1) * C(n,k) % MOD
        ll sum_of_heights = ((ll)(N-1) * total_sequences) % MOD;
        
        ll sum_c_total =0;
        // Iterate over h from1 to N-1
        for(int h=1; h<=N-1; h++){
            int t = h-1;
            if(t <1){
                // When t=0, no valid sequences with max depth <1
                continue;
            }
            // Compute c(n, k, t) using inclusion-exclusion
            // c(n,k,t) = Sum_{m=0}^{floor(k/h)} (-1)^m C(k,m) C(n -m*h +m, k -m)
            ll c_sum =0;
            int max_m = k / h;
            for(int m=0; m<=max_m; m++){
                // Check if n - m*h +m >= k -m
                if((ll)(n) - (ll)(m)*h + m < (ll)(k) - m){
                    continue;
                }
                ll comb1 = C(k, m);
                ll comb2 = C(n - (ll)m*h + m, k - m);
                if(comb2 ==0){
                    continue;
                }
                // Compute sign: (-1)^m
                if(m %2 ==1){
                    // Subtract
                    c_sum = (c_sum + MOD - (comb1 * comb2 % MOD)) % MOD;
                }
                else{
                    // Add
                    c_sum = (c_sum + (comb1 * comb2 % MOD)) % MOD;
                }
            }
            sum_c_total = (sum_c_total + c_sum) % MOD;
        }
        // Compute final sum_of_heights = (N-1)*C(n,k) - sum_c_total
        sum_of_heights = (sum_of_heights + MOD - sum_c_total) % MOD;
        cout << sum_of_heights << "\n";
    }
}