function solution(arr, delete_list) {
    var answer = [];
    for(let i of arr){
        let isSame = false;
        for(let j of delete_list){
            if(i == j) isSame = true;
        }
        if(!isSame) answer.push(i);
    }
    return answer;
}