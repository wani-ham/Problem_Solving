function solution(babbling) {
    var answer = 0;
    let words = ['aya', 'ye', 'woo', 'ma'];
    
    babbling.forEach((babble) => {
        let count = 0;
        for (const word of words) {
            if (babble.includes(word)) {
                babble = babble.replace(word, "1");
                count++;
            }
            
            if (babble === "1".repeat(count)) {  // if babble, "11..1"
                answer++;
                break;
            }
        }
    })
    
    return answer;
}