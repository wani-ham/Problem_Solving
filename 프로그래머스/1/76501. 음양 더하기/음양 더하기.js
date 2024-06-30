function solution(absolutes, signs) {
    let answer = 0;
    absolutes.forEach((num, index) => {answer = signs[index] ? answer + num : answer - num;})
    return answer;
}