function solution(my_string, target) {
    var answer = 0;
    for(let i = 0; i<= my_string.length - target.length; i++){
        if(my_string.substr(i, target.length) === target) answer = 1;
    }
    return answer;
}