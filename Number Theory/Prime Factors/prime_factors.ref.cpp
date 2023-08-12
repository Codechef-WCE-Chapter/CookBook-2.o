#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void primeFactors(int n){
    for(int i = 2; i <= n; ++i){
        int cnt = 0;
        while(n % i ==0){
            cnt++;
            n = n/i;
        }
        if(cnt != 0){
            cout<<i<<"^"<<cnt<<" ";
        }
    }
    cout<<"\n";
}

void primeFactorsOptimized(int n){
    for(int i = 2; i*i <= n; ++i){
        int cnt = 0;
        while(n % i ==0){
            cnt++;
            n = n/i;
        }
        if(cnt != 0){
            cout<<i<<"^"<<cnt<<" ";
        }
    }
    if(n > 1) cout<<n<<"^"<<1<<"\n";
    else cout<<"\n";
}

int N = 1e6;
vector<int>primes(N+1);
void primeFactorsUsingSieve(){
    for(int i = 0; i <= N; ++i){
        primes[i] = i;
    }
    for(int i = 2; i*i <= N; ++i){
        if(primes[i] == i){
            for(int j = i*i; j<= N; j+=i){
                if(primes[j] == j){
                    primes[j] = i;
                }
            }
        }
    }
}

void primeSpf(int n){
    while(n > 1){
        cout<<primes[n]<<" ";
        n = n / primes[n];
    }
    cout<<"\n";
}

int main()
{
    cout<<"Using basic method: \n";
    primeFactorsUsingSieve();
    primeFactors(72);
    primeFactors(100);
    primeFactors(31);
    cout<<"Using a bit optmized method: \n";
    primeFactorsOptimized(72);
    primeFactorsOptimized(100);
    primeFactorsOptimized(31);
    cout<<"Using Sieve method: \n";
    primeSpf(72);
    primeSpf(100);
    primeSpf(31);
    return 0;
}