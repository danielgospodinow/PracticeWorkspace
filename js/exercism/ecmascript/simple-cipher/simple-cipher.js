const alphabetSize = 26;
const ALPHABET = 'abcdefghijklmnopqrstuvwxyz';

const charIndex = ALPHABET.indexOf.bind(ALPHABET);

function getCharFromAlphabet(n){
    return ALPHABET[( n + ALPHABET.length) % ALPHABET.length];
}

function getRandomInt(min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

class Cipher {
    constructor(key){
        this.key = this._getValidKey(key);
    }
    
    encode(str){
        this._normalizeKeyLength(str);

        return str.split('').map((char, i) => {
            return getCharFromAlphabet(charIndex(char) + charIndex(this.key[i]));
        }).join('');
    }

    decode(str){
        this._normalizeKeyLength(str);

        return str.split('').map((char, i) => {
            return getCharFromAlphabet(charIndex(char) - charIndex(this.key[i]));
        }).join('');
    }

    _normalizeKeyLength(str){
        if(this.key.length < str.length){
            this.key = this.key.repeat(Math.ceil(str.length / this.key.length));
        }
    }

    _getValidKey(key){
        if(key === undefined || key === null){
            return Array(100).fill().map(() => {
                return getCharFromAlphabet(getRandomInt(0, alphabetSize-1));
            }).join('');
        }
    
        if(!/^[a-z]+$/.test(key)){
            throw new Error("Bad key");
        }
    
        return key;
    }
}

export default Cipher;
