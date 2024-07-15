function solution(myString, pat) {
    var answer = 0;
    let newString = "";
    for(let i =0; i<myString.length; i++){
        newString += myString[i] === "A" ? "B" : "A";
    }
    if(newString.includes(pat)) answer = 1;
    return answer;
}