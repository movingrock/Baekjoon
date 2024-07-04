function solution(arr) {
    var answer = [];
    let first = -1;
    let last = -1;
    for(let i =0; i<arr.length; i++){
        if(first === -1 && arr[i] === 2) first = i;
        else if(first !== -1 && arr[i] === 2) last = i;
    }
    
    if(first !== -1 && last !== -1){
        for(let i =first; i<=last; i++){
            answer.push(arr[i]);
        }
    }else if(first !== -1 && last === -1){
        answer.push(2);
    }
    
    
    if(answer.length === 0) answer.push(-1);
    return answer;
}