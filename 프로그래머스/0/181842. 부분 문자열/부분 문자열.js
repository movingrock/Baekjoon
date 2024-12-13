function solution(str1, str2) {
    var answer = 0;
    for(let i =0; i<= str2.length - str1.length; i++){
        if(str2.substring(i, i + str1.length) === str1) answer = 1;
    }
    return answer;
}