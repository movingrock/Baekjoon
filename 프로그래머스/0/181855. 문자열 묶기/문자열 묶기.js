function solution(strArr) {
    var answer = 0;
    let arr = new Array(31).fill(0);
    for(let i of strArr){
        arr[i.length]++;
    }
    for(let i = 1; i<=30; i++){
        answer = Math.max(answer, arr[i]);
    }
    return answer;
}