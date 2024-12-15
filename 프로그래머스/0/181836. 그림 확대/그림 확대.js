function solution(picture, k) {
    var answer = [];
    for(let i of picture){
        let row = "";
        for(let j = 0; j < i.length; j++){
            for(let cnt = 0; cnt < k; cnt++){
                row += i[j];
            }
        }
        for(let cnt = 0; cnt < k; cnt++) answer.push(row);
    }
    return answer;
}