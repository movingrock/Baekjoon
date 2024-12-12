function solution(rank, attendance) {
    var answer = 0;
    let arr = [];
    for(let i = 0; i<attendance.length; i++){
        if(attendance[i]) arr.push([rank[i], i]);
    }
    arr.sort((a, b) => a[0] - b[0]);
    console.log(arr);
    answer = arr[0][1]* 10000 + arr[1][1] * 100 + arr[2][1];
    return answer;
}