function solution(myString) {
    var answer = [];
    const arr = myString.split("x");
    for(let i =0; i<arr.length; i++){
        answer.push(arr[i].length);
    }
    return answer;
}