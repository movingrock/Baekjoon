function solution(arr1, arr2) {
    var answer = 0;
    let diff = arr1.length - arr2.length;
    if(diff > 0) answer = 1;
    else if(diff < 0) answer = -1;
    else {
        let sum1 = 0;
        let sum2 = 0;
        for(let i of arr1) sum1 += i;
        for(let i of arr2) sum2 += i;
        if(sum1 > sum2) answer = 1;
        else if (sum1 < sum2) answer = -1;
        else answer = 0;
    }
    return answer;
}