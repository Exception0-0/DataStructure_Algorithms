#include<iostream>
#define ll long long

ll iterative(ll number,ll power,ll modulo){
    ll ans = 1;
    while(power){
        if(power & 1){
            ans = ans * number % modulo;
        }
        number = number * number % modulo;
        power >>= 1;
    }
    return ans;
}

ll recursive(ll number,ll power,ll modulo){
    if(power == 1) return number;
    if(power & 1){
        return recursive(number,power-1,modulo) * number % modulo;
    }
    ll half = recursive(number,power/2,modulo);
    return half * half % modulo;
}
