#include<iostream>
#include<vector>
using namespace std;
const int mx = 1e6;
vector<bool> isPrime(mx+10,1);
int main(){
    isPrime[0] = isPrime[1] = 0;
    for(int i=2;i<=mx;i++){
        if(isPrime[i]){
            for(int j=i+i;j<=mx;j += i){
                isPrime[j] = 0;
            }
        }
    }
    return 0;
}