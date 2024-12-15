function solution(arr) {
    var answer = 1;
    let n = arr.length;
    for(let i = 0; i<n; i++){
        for(let j = i+1; j<n; j++){
            if(arr[i][j] !== arr[j][i]) answer = 0;
        }
    }
    return answer;
}