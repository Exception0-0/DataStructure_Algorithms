ll fast_pow(ll number,ll power,ll modulo){
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

ll nCr(ll n,ll r){
    ll d = (fact[r] * fact[n-r]) % mod;
    return (fact[n] * fast_pow(d,mod-2,mod)) % mod;
}
