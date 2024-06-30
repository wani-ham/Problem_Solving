function solution(x) {
    let answer = true, sum = 0;
    let xStr = x.toString();
    [...xStr].forEach((num) => {sum += Number(num)});
    answer = x % sum === 0 ? true : false;
    return answer;
}