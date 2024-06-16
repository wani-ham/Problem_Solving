function solution(n) {
    let visited =[[]];
    let answer = Array.from(Array(n), () => Array(n).fill(0));  // initialize with 0
    
    // direction
    let dir = [
        [0, 1],  // right
        [1, 0],  // down
        [0, -1],  // left
        [-1, 0],  // up
    ];
    
    let i = 0, 
        cnt = 0,
        x = 0,
        y = 0,
        nextX = 0,
        nextY = 0;
    
    while (cnt < n*n) {
        while (true) {
            answer[x][y] = (cnt++) + 1;
            nextX = x + dir[i%4][0];
            nextY = y + dir[i%4][1];
            // If out of boundary (or) visited -> update next start point and break
            if((nextX < 0 || n <= nextX || nextY < 0 || n <= nextY) || (answer[nextX][nextY] != 0)) {
                i++;
                x += dir[i%4][0];
                y += dir[i%4][1];
                break;
            }
            x = nextX;
            y = nextY;
        }
    }
    return answer;
}