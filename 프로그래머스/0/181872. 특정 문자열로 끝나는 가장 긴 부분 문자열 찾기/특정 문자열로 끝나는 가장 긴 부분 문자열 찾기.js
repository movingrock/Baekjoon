function solution(myString, pat) {
    var answer = '';
    answer = myString.substr(0, myString.lastIndexOf(pat)+pat.length);
    return answer;
}