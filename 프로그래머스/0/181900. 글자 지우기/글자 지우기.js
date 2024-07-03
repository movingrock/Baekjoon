function solution(my_string, indices) {
    var answer = '';
    let idx = 0;
    indices.sort((a, b) => {return a - b});
    for(let i =0; i<my_string.length; i++){
        if(i === indices[idx]){
            idx++;
            continue;
        }
        answer += my_string[i];
    }
    return answer;
}