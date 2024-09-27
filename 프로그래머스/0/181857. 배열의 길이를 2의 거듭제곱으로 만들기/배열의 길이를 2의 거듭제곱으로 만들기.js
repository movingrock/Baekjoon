function solution(arr) {
    var answer = [];
    answer = arr;
    
    var l = arr.length;
    let i = 0;
    while(true){
        if(2**i < l) {
            i++;
        }else{
            break;
        }
    }
    while(answer.length < 2**i){
        answer.push(0)
    }
    return answer;
}