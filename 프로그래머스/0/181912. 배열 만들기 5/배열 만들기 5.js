function solution(intStrs, k, s, l) {
    var answer = [];
    for(let i =0; i<intStrs.length; i++){
        let n = Number(intStrs[i].substr(s, l));
        if(n > k) answer.push(n);
    }
    return answer;
}