function solution(num_list, n) {
    var answer = [];
    let tmp = num_list.splice(n);
    for(let i=0; i < tmp.length; i++) answer.push(tmp[i]);
    tmp = num_list.splice(0, n);
    for(let i=0; i < tmp.length; i++) answer.push(tmp[i]);
    
    return answer;
}