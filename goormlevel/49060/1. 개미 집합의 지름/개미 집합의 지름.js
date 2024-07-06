// Node.js에서 표준 입력 처리
const readline = require('readline');
let rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});
const input = [];
rl.on('line', (line) => {
    input.push(line.split(' ').map(Number));
    if (input.length == 2){
        rl.close();
    }
});
rl.on('close', () => {
    const [N, D] = input[0];
    const ant = input[1].sort((a, b) => a - b);
		let start = 0, end = 0;
    let length = 0;
    while (start < N && end < N) {
        if (ant[end] - ant[start] <= D) {
            length = Math.max(length, end - start + 1);
            end++;
        } else {
            start++;
        }
    }
    console.log(N - length);
});