function solution(binomial) {
    var answer = 0;
    const arr = binomial.split(" ");
    if(arr[1] === "+"){
        answer = Number(arr[0]) + Number(arr[2]);
    }else if(arr[1] === "-"){
        answer = Number(arr[0]) - Number(arr[2]);
    }else if(arr[1] === "*"){
        answer = Number(arr[0]) * Number(arr[2]);
    }
    return answer;
}