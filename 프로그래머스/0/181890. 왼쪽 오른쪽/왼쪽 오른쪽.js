function solution(str_list) {
    var answer = [];
    let index = -1;
    let dir = "";
    for(let i =0; i<str_list.length; i++){
        if(str_list[i] === "l" || str_list[i] === "r") {index = i; dir = str_list[i]; break;}
    }
    if(dir === "l"){
        answer = str_list.splice(0, index);
    }else if(dir === "r"){
        answer = str_list.splice(index +1);
    }
    return answer;
}