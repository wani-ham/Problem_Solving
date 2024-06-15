function solution(numbers) {
    var answer = 0;
    numbers.forEach ((element) => {answer += element});
    return answer /= numbers.length;
}