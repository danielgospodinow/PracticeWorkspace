class Transcriptor{
    constructor(){
        this.map = { G: 'C', C: 'G', T: 'A', A: 'U' };
    }

    toRna(dna){
        if(/[^GCTA]+/.test(dna)){
            throw new Error("Invalid input DNA.");
        }

        return dna.split("").map(char => this.map[char]).join("");
    }
}

export default Transcriptor;