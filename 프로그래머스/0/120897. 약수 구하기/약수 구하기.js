function solution(n) {
    let answer = [];
    for(let i = 1; i <= n; n%i==0 ? answer.push(i++) : i++);
    return answer;
}