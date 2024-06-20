function solution(array, commands) {
    var answer = [];
    
    for(let c = 0; c<commands.length; c++){
        let newArray = [];

        for(let i = commands[c][0]-1; i<= commands[c][1]-1; i++){
            newArray.push(array[i]);
        }

        newArray.sort((a, b) => {if(a > b) return 1; else if(a < b) return -1; else return 0;})

        answer.push(newArray[commands[c][2]-1]);
    }
    return answer;
}