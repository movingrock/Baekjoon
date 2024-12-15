function solution(arr) {
    var answer = [[]];
    let diff = arr.length - arr[0].length;
    
    if(diff > 0){
        for(let i =0; i<arr.length; i++){
            for(let j = 0; j<diff; j++){
                arr[i].push(0);
            }
        }
    }else if(diff < 0){
        let tmp = [];
        for(let i = 0; i<arr[0].length; i++){
            tmp.push(0);
        }
        for(let i = 0; i<Math.abs(diff); i++){
            arr.push(tmp);
        }
    }
    answer = arr;
    return answer;
}