const InRange = (x, y, n) => {
    return x>=0 && x<n && y>=0 && y<n;
}

function solution(n) {
    let answer = Array.from(Array(n), () => Array(n).fill(0));
    let cnt = 1;
    let dx = [0, 1, 0, -1];
    let dy = [1, 0, -1, 0];
    let x = 0;
    let y = 0;
    let dir = 0;
    
    while(cnt <= n*n){
        answer[x][y] = cnt;
        
        let nx = x + dx[dir];
        let ny = y + dy[dir];

        if(!InRange(nx, ny, n) || answer[nx][ny] !== 0) {
            dir = (dir + 1) % 4;
        }
        
        x += dx[dir];
        y += dy[dir];
        cnt++;
    }
    
    return answer;
}