#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int N = 1e6;
vector<int>spf(N + 1);
vector<int>hpf(N + 1);
vector<bool>isPrime(N+1,1);
void sieve(){
    for(int i = 0; i <= N; ++i){
        spf[i] = i;
        hpf[i] = i;
    }
    isPrime[0] = isPrime[1] = 0;
    spf[0] = spf[1] = 0;
    for(int i = 2; i*i <= N; ++i){
        if(spf[i] == i){
            for(int j = i*2 ; j <= N; j+=i){
                isPrime[j] = 0;
                hpf[j] = i;
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

int main()
{
    sieve();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<"Smallest Prime Factor of "<<n<<" is "<<spf[n]<<"\n";
        cout<<"Highest Prime Factor of "<<n<<" is "<<hpf[n]<<"\n";
    }
   return 0;
}