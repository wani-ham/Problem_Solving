function solution(s) {
    let numbers = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine'];    
    while(! /^\d+$/.test(s)) {  // until s is completely replaced with number
        for (let i in numbers) {
            // if word-string is in s -> replace to number
            if (s.includes(numbers[i])) s = s.replace(numbers[i], i);
        }
    }
    return parseInt(s);
}