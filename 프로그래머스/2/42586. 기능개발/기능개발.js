function solution(progresses, speeds) {
    var answer = [];
    
    let days = [];
    for(let i = 0; i<progresses.length; i++){
        let day = parseInt((100-progresses[i]) / speeds[i]);
        if((100-progresses[i]) % speeds[i] !== 0) day+= 1;
        days.push(day);
    }
    
    let now = days[0];
    let sum = 1;
    for(let i = 1; i<days.length; i++){
        if(days[i] <= now) sum++;
        if(days[i] > now){
            answer.push(sum);
            now = days[i];
            sum = 1;
        }
        
        if(i == days.length-1) answer.push(sum);
    }
    
    return answer;
}