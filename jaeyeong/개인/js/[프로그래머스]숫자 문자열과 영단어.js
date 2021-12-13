const myEnum = {
    0: 3,
    1: 2,
    2: 2,
    3: 4,
    4: 3,
    5: 3,
    6: 2,
    7: 4,
    8: 4,
    9: 3
}
function solution(s) {
    let answer = 0;
    for(let i=0;i<s.length;i++) {
        let key;
        let flag = true;
        switch(s[i]) {
            case('z'): key = 0; break;
            case('o'): key = 1; break;
            case('t'): key = s[i+1]==='w' ? 2:3; break;
            case('f'): key = s[i+1]==='o' ? 4:5; break;
            case('s'): key = s[i+1]==='i' ? 6:7; break;
            case('e'): key = 8; break;
            case('9'): key = 9; break;
            default: key = Number(s[i]); flag=false; break;
        }
        answer = answer*10 + key;
        if(flag) i += myEnum[key];
    }
    return answer;
}
const ans = solution("one4seveneight");
console.log(ans);