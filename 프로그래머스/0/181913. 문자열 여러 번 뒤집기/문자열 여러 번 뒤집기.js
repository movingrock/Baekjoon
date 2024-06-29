function solution(my_string, queries) {
    var answer = '';
    for(let i =0; i<queries.length; i++){
        let tmp = my_string.substring(queries[i][0], queries[i][1]+1);
        let arr = tmp.split("").reverse().join("");

        my_string = my_string.slice(0, queries[i][0]) + arr + my_string.slice(queries[i][1]+1);
    }
    answer = my_string;
    return answer;
}