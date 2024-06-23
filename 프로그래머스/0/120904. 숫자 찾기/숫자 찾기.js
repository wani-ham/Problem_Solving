function solution(num, k) {
    num = num.toString();
    let answer = num.indexOf(k.toString());
    return answer != -1 ? answer + 1 : -1;
}