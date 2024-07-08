function solution(num_list) {
    var answer = 0;
    let sum1 =0;
    let sum2 =0;
    for(let i =0; i<num_list.length; i++){
        if(i% 2 === 0) sum1 += num_list[i];
        else sum2 += num_list[i];
    }
    answer = Math.max(sum1, sum2);
    return answer;
}