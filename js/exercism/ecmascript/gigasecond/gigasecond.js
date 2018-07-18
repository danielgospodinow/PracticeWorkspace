class Gigasecond {
    constructor(dater){
        this.dater = dater;
    }

    date(){
        return new Date(this.dater.getTime() + 10 ** 12);
    }
};

export default Gigasecond;