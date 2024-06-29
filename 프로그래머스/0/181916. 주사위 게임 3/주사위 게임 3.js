function solution(a, b, c, d) {
    var answer = 0;
    let arr = [0, 0, 0, 0, 0, 0, 0]; // 0~6
    let num = [0, 0, 0, 0, 0]; // 0~4
    arr[a]++;
    arr[b]++;
    arr[c]++;
    arr[d]++;
    
    for(let i = 1; i<arr.length; i++){
        if(arr[i] > 0) num[arr[i]]++;
    }
   
    if(num[4] === 1){
        for(let i =1; i<arr.length; i++){
            if(arr[i] === 4) answer = i * 1111;
        }
    }
    else if(num[3] === 1) {
         let p, q;
         for(let i =1; i<arr.length; i++){             
             if(arr[i] === 3) p = i;
             if(arr[i] === 1) q = i;
        }
        answer = (10 * p + q) ** 2;
    }
    else if(num[2] === 2) {
         let p = null, q = null
         for(let i =1; i<arr.length; i++){             
             if(p === null && arr[i] === 2) p = i;
             if(p !== null && arr[i] === 2) q = i;
        }
        answer = (p+q) * Math.abs(p-q);
    }
    else if(num[2] === 1) {
         let p = null, q = null, r = null
         for(let i =1; i<arr.length; i++){             
             if(arr[i] === 2) p = i;
             if(q === null && arr[i] === 1) q = i;
             if(q !== null && arr[i] === 1) r = i;
        }
        answer = q*r;
    }
    else if(num[1] === 4) {
        answer = 7;
        for(let i =1; i<arr.length; i++){
            if(arr[i] > 0) answer = Math.min(answer, i);
        }
    }
    
    return answer;
}

// 4 
// 3 1
// 2 2
// 2 1 1
// 1 1 1 1