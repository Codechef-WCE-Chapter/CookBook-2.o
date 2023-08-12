// pow(a, b)-> returns a double and not precise


// Basics->
// a^b -> 2^13

// int a= 2, b = 13;
// int ans = 1;
// for(int i = 0; i<b; i++){
//     ans = ans*a;
// } //Steps -> 13

// cout<<ans<<endl;


// Optimised->
// // If Even
// 2^16 -> 2^8 X 2^8
// 2^8 -> 2^4 X 2^4
// 2^4 -> 2^2 X 2^2
// 2^2 -> 2^1 X 2^1
// Steps -> 4

// // If Odd
// 2^15 -> 2 X 2^14
// 2^14 -> 2^7 X 2^7
// 2^7 -> 2 X 2^6;
// 2^6 -> 2^3 X 2^3
// 2^3 -> 2 X 2^2
// 2^2 -> 2^1 X 2^1

/*

binExp(3,5) => 3*binExp(3,2)*binExp(3,2)
           => 3* binExp(3,1)*binExp(3,1)*binExp(3,1)*binExp(3,1)
           => 3* 3 * 3 *3 * 3 => 
*/

int binExp(int a, int b){
    //base condition
    if(b == 0) return 1;
    if(b % 2 != 0){
        return a * binExp(a, b/2) * binExp(a, b/2);
    }
    else{
        return binExp(a, b/2) * binExp(a, b/2);
    }
}

int binPow(int a, int b){
    int res = 1;
    while(b > 0){
        if(b%2 == 1){
            res*=a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}
/*


2^4 = (2X2)^2

*/
//Here every time we are calling the function two times -> TC -> Exponential

// Further Optimised->

int binExpOptimised(int a, int b){
    //base condition
    if(b == 0) return 1;
    int x = binExpOptimised(a, b/2);
    if(b % 2 != 0){
        return a * x * x;
    }
    else{
        return x * x;
    }
}
