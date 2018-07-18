function divideToSecondDigit(numOne, numTwo){
    return Math.round(numOne / numTwo * 100) / 100;
}

class SpaceAge {
    constructor(seconds){
        this.seconds = seconds;

        let earthOrbit = 31557600;
        this.times = {
            Earth: divideToSecondDigit(this.seconds, earthOrbit),
            Mercury: divideToSecondDigit(this.seconds, 0.2408467 * earthOrbit),
            Venus: divideToSecondDigit(this.seconds, 0.61519726 * earthOrbit),
            Mars: divideToSecondDigit(this.seconds, 1.8808158 * earthOrbit),
            Jupiter: divideToSecondDigit(this.seconds, 11.862615 * earthOrbit),
            Saturn: divideToSecondDigit(this.seconds, 29.447498 * earthOrbit),
            Uranus: divideToSecondDigit(this.seconds, 84.016846 * earthOrbit),
            Neptune: divideToSecondDigit(this.seconds, 164.79132 * earthOrbit),
        };

        for(const planet in this.times) {
            this['on' + planet] = () => {
                return this.times[planet];
            }
        }
    }
};

export default SpaceAge;