function solution(arr, k) {
    var answer = [];
    for(let i =0; i<arr.length && answer.length < k; i++){
        if(!answer.includes(arr[i])) answer.push(arr[i]);
    }
    while(answer.length < k){
        answer.push(-1)
    }
    return answer;
}