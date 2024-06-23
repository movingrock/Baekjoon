function solution(a, b) {
    var answer = 0;
    if(String(a)+String(b) >= 2*a*b) answer = Number(String(a)+String(b));
    else answer = 2*a*b;
    return answer;
}