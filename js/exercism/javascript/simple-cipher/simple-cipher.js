function Cipher(cipher){
    this.key = getValidCipher();

    function getValidCipher() {
        if(cipher == undefined || cipher == null){
            var cipherLen = 100;
            return new Array(cipherLen + 1).join(" ").split("").map(() => {
                return String.fromCharCode(getRandomInt('a'.charCodeAt(), 'z'.charCodeAt()));
            }).join("");
        }

        cipher.split("").map(function(char) {
            if(char.charCodeAt() < 'a'.charCodeAt() || char.charCodeAt() > 'z'.charCodeAt()){
                new Error('Bad key');
            }
        });

        return cipher;
    }
}

Cipher.prototype.encode = function(str){
    return str.split("").map((char, i) => {
        return getNthCharFromAlphab(getPosInAlphabet(str[i].charCodeAt()) + getPosInAlphabet(this.key[i % this.key.length].charCodeAt()));
    }).join("");
};

Cipher.prototype.decode = function(str) {
    return str.split("").map((char, i) => {
        return getNthCharFromAlphab(getPosInAlphabet(str[i].charCodeAt()) - getPosInAlphabet(this.key[i].charCodeAt()));
    }).join("");
};

const alphabetSize = 26;

function getPosInAlphabet(char){
    return char - 'a'.charCodeAt();
}

function getNthCharFromAlphab(n) {
    if(n < 0) {
        n += alphabetSize;
    }

    return String.fromCharCode('a'.charCodeAt() + (n % alphabetSize));
}

function getRandomInt(min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

module.exports = Cipher;