function solution(arr, queries) {
    var answer = [];
    for(let i =0; i< queries.length; i++){
        let ans = Number.MAX_VALUE;
        for(let j = queries[i][0]; j<=queries[i][1]; j++){
            if(queries[i][2] < arr[j]) ans = Math.min(ans, arr[j]);
        }
        if(ans === Number.MAX_VALUE) answer.push(-1);
        else answer.push(ans);
    }
    return answer;
}