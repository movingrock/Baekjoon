function solution(str_list, ex) {
    var answer = '';
    for(let i of str_list){
        if(i.indexOf(ex) < 0) answer += i;
    }
    return answer;
}