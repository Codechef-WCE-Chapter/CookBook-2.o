#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool isPrime(int n){
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        if(n%i == 0) cnt++;
    }
    return cnt==2;
}

bool isPrimeOptimized(int n){
    if(n < 2) return false;
    for(int i = 2; i*i <= n; ++i){
        if(n % i == 0) return false;
    }
    return true;
}

int countFactors(int n){
    int cnt = 0;
    for(int i = 2; i*i <= n; ++i){
        if(n%i == 0){
            if(n/i == i) cnt++;
            else cnt+=2;
        }
    }
}

void sieve(){
    int N = 1e6;
    vector<bool>isPrime(N+1,true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i*i <= N; ++i){
        if(isPrime[i]){
            for(int j = i*i; j <= N; j+=i){
                isPrime[j] = false;
            }
        }
    }
}


int findPrimeFactorsSieve(int n){
    vector<int>spf(n+1);
    for(int i = 0; i <= n; ++i){
        spf[i] = i;
    }
    for(int i = 2; i*i <= n; ++i){
        if(spf[i] == i){
            for(int j = i*i; j <= n; j+=i){
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
    int cnt = 0;
    while(n != 1){
        cnt++;
        n = n/spf[n];
    }
    return cnt;
}


int main()
{
   return 0;
}