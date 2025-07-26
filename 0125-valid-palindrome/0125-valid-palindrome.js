/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    let temp = "";

    for(let ch of s){
        if(/[a-z0-9]/i.test(ch)){
            temp += ch.toLowerCase();
        }
    }

    let i = 0;
    let j = temp.length-1;

    while(i < j){
        if(temp[i] != temp[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
};