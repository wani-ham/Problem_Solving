function solution(num_list) {
    let answer = [];
    for(let i = num_list.length - 1; 0 <= i; answer.push(num_list[i--]));
    return answer;
}