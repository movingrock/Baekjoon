function solution(arr, k) {
    var answer = [];
    if(k %2 === 1){
        for(let i of arr) answer.push(i*k);
    }else{
        for(let i of arr) answer.push(i+k);
    }
    return answer;
}