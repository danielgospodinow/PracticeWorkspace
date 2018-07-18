const ALPHABET_SIZE = 26;
const ALPHABET = "abcdefghijklmnopqrstuvwxyz";

class Pangram{
    constructor(str){
        this.string = str.toLowerCase();
    }

    isPangram(){
        let boolArr = new Array(ALPHABET_SIZE).fill(false);

        for(let c of this.string) {
            if(ALPHABET.indexOf(c) === -1) continue;

            boolArr[ALPHABET.indexOf(c)] = true;
        }

        return boolArr.every(x => x);
    }
}

export default Pangram;