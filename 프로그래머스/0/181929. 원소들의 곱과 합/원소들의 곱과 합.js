function solution(num_list) {
    var answer = 0;
    let mul = 1;
    let sum = 0;
    for(let i=0; i<num_list.length; i++){
        mul *= num_list[i];
        sum += num_list[i];
    }
    if(mul < sum**2) answer = 1;
    else answer = 0;
    return answer;
}