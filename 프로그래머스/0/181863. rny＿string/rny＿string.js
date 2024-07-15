function solution(rny_string) {
    var answer = '';
    for(let i =0; i<rny_string.length; i++){
        answer += rny_string[i] === "m" ? "rn" : rny_string[i];
    }
    return answer;
}