const BINARY = "01";

function binToDec(binary){
    if(/[^01]/.test(binary) || binary === "")
        return 0;
    
    let ret = 0;
    binary.split("").map((char, i) => {
        ret += (BINARY.indexOf(char)) * 2 ** (binary.length - (1 + i));
    });

    return ret;
}

class Binary{
    constructor(binary){
        this.binary = binary;
        this.decimal = binToDec(this.binary);
    }

    toDecimal(){ return this.decimal; }
};

export default Binary;