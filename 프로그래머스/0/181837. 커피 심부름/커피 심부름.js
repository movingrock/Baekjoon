function solution(order) {
    var answer = 0;
    for(let i of order){
        if(i.indexOf("americano") !== -1 || i.indexOf("anything") !== -1) answer += 4500;
        else if(i.indexOf('cafelatte') !== -1) answer+= 5000;
    }
    return answer;
}