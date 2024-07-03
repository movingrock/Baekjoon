function solution(my_string) {
    var answer = new Array(52).fill(0);
    console.log("A".charCodeAt());
    console.log("Z".charCodeAt());
    console.log("a".charCodeAt());
    console.log("z".charCodeAt());
    for(let i =0; i<my_string.length; i++){
        let c = my_string[i].charCodeAt();
        if(c >= 65 && c<= 90) answer[my_string[i].charCodeAt()-65]++;
        else if(c>=97 && c<=122) answer[my_string[i].charCodeAt()-71]++;
    }
    return answer;
}