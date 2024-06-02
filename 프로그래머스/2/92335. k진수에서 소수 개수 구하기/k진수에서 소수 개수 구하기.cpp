#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(long long num){
    if(num < 2) return false;
    for(int i =2; i<= sqrt(num); i++){
        if(num % i == 0) return false;        
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    string num;
    string result = "";
    num = to_string(n);
    
    while(n != 0){
        result += to_string(n % k);
        n /= k;
    }
    reverse(result.begin(), result.end());
    
    string tmp = "";
    for(int i=0; i<result.length(); i++){
        if(result[i] != '0'){
            tmp +=result[i];
        }else if(result[i] == '0' && tmp != ""){
            long long change = stol(tmp);
            if(isPrime(change)){
                answer++;
            }
            tmp = "";
        }
    }
    
    if(tmp != ""){
        long long change = stol(tmp);
        if(isPrime(change)){
            answer++;
        }
    }
    
    return answer;
}
