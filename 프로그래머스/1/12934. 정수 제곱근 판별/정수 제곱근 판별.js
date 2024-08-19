function solution(n) {
    let answer = 0;
    let tmpSqrt = Math.floor(Math.sqrt(n));
    if (tmpSqrt ** 2 === n) {
        answer = (tmpSqrt + 1) ** 2;
    } else {
        answer = -1;
    }
    return answer;
}