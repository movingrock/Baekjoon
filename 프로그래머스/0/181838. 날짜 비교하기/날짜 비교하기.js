function solution(date1, date2) {
    var answer = 0;
    for(let i = 0; i<3; i++){
        if(date1[i] < date2[i]) {
            answer = 1;
            break;
        }else if(date1[i] > date2[i]) {
            break;
        }
    }
    return answer;
}