function solution(arr) {
    var answer = [];
    if(arr.length === 1) {
        answer = [-1];
    } else {
        let minNum = Math.min(...arr);
        arr.forEach((num) => {
            if(num !== minNum) answer.push(num);
        })
    }
    return answer;
}