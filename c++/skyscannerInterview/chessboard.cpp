#include <map>
#include <vector>
#include <string>

typedef unsigned int uint;

char getBestChar(std::map<char, int>& charCount)
{
    char bestC = '\0';
    int maxCount = -1;

    for(std::map<char, int>::iterator it = charCount.begin(); it!=charCount.end(); ++it)
    {
        if(it->second > maxCount)
        {
            bestC = it->first;
            maxCount = it->second;
        }
    }

    charCount[bestC] = 0;
    return bestC;
}

int solver(char solverChar, char helperChar, std::vector<std::string>& input)
{
    int lineLen = input[0].length();
    bool odd = lineLen % 2;

    int count = 0;

    for(uint i=0; i<input.size(); ++i)
    {
        for(uint j=0; j<input[i].length(); ++j)
        {
            if(input[i][j] != solverChar)
                ++count;

            if(odd || j != lineLen - 1)
                swap(solverChar, helperChar);
        }
    }

    return count;
}

int solve(std::vector<std::string> input)
{
    std::map<char, int> charCount;

    for(uint i=0; i<input.size(); ++i)
        for(uint j=0; j<input[i].length(); ++j)
            ++charCount[input[i][j]];

    char fbChar = getBestChar(charCount),
            sbChar = getBestChar(charCount);

    int firstWay = solver(fbChar, sbChar, input),
            secondWay = solver(sbChar, fbChar, input);

    return std::min(firstWay, secondWay);
}


/*
 * The input is a NxN matrix with chars.
 * The task is to return the minimum of
 * changes that need to be performed
 * in order to make the matrix a chessboard
 * i.e to make the matrix from 2 chars
 * which are like 'black' and 'white'
 * (no two neighbour cells have the same value, etc)
 */
