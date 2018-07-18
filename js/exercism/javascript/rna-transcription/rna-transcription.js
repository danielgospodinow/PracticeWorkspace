var sampleInputs = ["ACGTGGTCTTAA", "GATGGAACTTGACTACGTAAATT", "GACACGGACGACGAGCGGCATGCTGATCG"];

function getRna(dna) 
{
    function getRnaChar(char) 
    {
        switch (char)
        {
            case 'G': return 'C'; break;
            case 'C': return 'G'; break;
            case 'T': return 'A'; break;
            case 'A': return 'U'; break;
            default: return ''; break;
        }
    }
    
    var dnaChars = ['G', 'C', 'T', 'A'];
    var rna = [];
    for (i in dna)
    {
        if(!dnaChars.includes(dna[i]))
        {
            throw "Invalid DNA input";
        }

        rna.push(getRnaChar(dna[i]));
    }

    return rna.join("");
};

for (i in sampleInputs)
{
    console.log(getRna(sampleInputs[i]));
}