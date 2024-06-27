function solution(arr, queries) {
    var answer = [];
    for(let i =0; i<queries.length; i++){
        [arr[queries[i][0]], arr[queries[i][1]]] = [arr[queries[i][1]], arr[queries[i][0]]]
    }
    answer = arr;
    return answer;
}