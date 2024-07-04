function solution(n, slicer, num_list) {
    var answer = [];
    let a = slicer[0];
    let b = slicer[1];
    let c = slicer[2];
    switch(n){
        case 1:
            for(let i =0; i<=b; i++){
                answer.push(num_list[i]);
            }
            break;
        case 2:
            for(let i =a; i<num_list.length; i++){
                answer.push(num_list[i]);
            }
            break;
        case 3:
            for(let i = a; i<=b; i++){
                answer.push(num_list[i]);
            }
            break;
            
        case 4:
            for(let i =a; i<=b; i+=c){
                answer.push(num_list[i]);
            }
            break;
            
    }
    return answer;
}