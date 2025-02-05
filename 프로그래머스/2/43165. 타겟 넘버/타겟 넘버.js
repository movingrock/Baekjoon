let answer = 0;

const dfs = (numbers, target, index, sum) => {
    if(index === numbers.length){
        if(target === sum) answer++;
        return;
    }
    dfs(numbers, target, index+1, sum + numbers[index]);
    dfs(numbers, target, index+1, sum - numbers[index]);
}

function solution(numbers, target) {
    dfs(numbers, target, 0, 0);
    return answer;
}