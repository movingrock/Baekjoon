function solution(myString) {
    var answer = [];
    let arr = myString.split("x");
    for(let i =0; i<arr.length; i++){
        if(arr[i] !== "") answer.push(arr[i]);
    }
    answer.sort();
    return answer;
}