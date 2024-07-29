function solution(arr)
{
    let answer = [];
    let previousNum = 11;
    arr.forEach((element) => {
        if(previousNum != element) {
            answer.push(element);
            previousNum = element;
        }
    })
    return answer;
}