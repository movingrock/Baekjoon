function solution(myString) {
    var answer = '';
    for(let i =0 ; i<myString.length; i++){
        if(myString[i] === "a") answer += "A";
        else if(myString[i] === myString[i].toUpperCase() && myString[i] !== "A") answer += myString[i].toLowerCase();
        else answer += myString[i];
    }
    return answer;
}