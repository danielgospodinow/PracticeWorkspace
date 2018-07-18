function Pangram(str){
    this.string = str.toLowerCase();
}

Pangram.prototype.isPangram = function(){
    var boolArr = [];
    for(let i=0; i<alphabetSize; i++) {
        boolArr.push(false);
    }

    for(let c of this.string) {
        if(!isLowercaseChar(c)){
            continue;
        }

        boolArr[c.charCodeAt() - 'a'.charCodeAt()] = true;

        /* 
         * We can eventually check on every step if the bool array is full of "true"
         * to see whether we've got the required result for a pangram already.
         * This will eventually save us from iterating through a whole big string.
         * We can do this because the time for checking is O(constant) ~ O(1).
         */
    }

    for(i in boolArr) {
        if(boolArr[i] == false) {
            return false;
        }
    }
    
    return true;
}

function isLowercaseChar(char) {
    return (char.charCodeAt() >= 'a'.charCodeAt() && char.charCodeAt() <= 'z'.charCodeAt());
}

let alphabetSize = 26;

module.exports = Pangram;