#include <bits/stdc++.h>
using namespace std;

vector<int>primes;
void sieve(){
	int N = 86028121;
	vector<bool>isPrime(N+1,true);
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i*i <= N; ++i){
		if(isPrime[i]){
			for(int j = i*i; j <= N; j+=i){
				isPrime[j] = false;
			}
		}
	}
    for(int i = 2; i <= N; ++i){
        if(isPrime[i]) primes.push_back(i);
    }
}

int main() {
	sieve();
	int q;
	cin>>q;
	while(q--){
		int k;
		cin>>k;
		cout<<primes[k-1]<<"\n";
	}
	return 0;
}