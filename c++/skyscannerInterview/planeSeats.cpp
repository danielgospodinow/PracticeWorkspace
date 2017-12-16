#include <vector>

typedef unsigned int uint;

int getMinPrice(int reqSeats, std::vector<std::vector<int>> seatPrices)
{
    const int MAX_PRICE = 10000;
    int minPrice = MAX_PRICE * reqSeats;

    for(uint i=0; i < seatPrices.size(); ++i)
    {
        for(uint j=0; j < seatPrices[i].size() - reqSeats + 1; ++j)
        {
            bool shouldContinue = true;

            for(uint k=j; k < j+reqSeats; ++k)
            {
                if(seatPrices[i][k] == -1)
                {
                    shouldContinue = false;
                    break;
                }
            }

            if(!shouldContinue)
                continue;

            int sum = 0;
            for(uint k=j; k < j+reqSeats; ++k)
                sum += seatPrices[i][k];

            if(sum < minPrice)
                minPrice = sum;
        }
    }

    return minPrice;
}

/*
 * The task is to get the reqSeats seats next to eachother
 * in a plane for the lowest cost. There are unavaivable seats (-1).
 * Example:
 *
 * 14 6  1 -1 -1 -1
 * 4  14 7 6  6  6
 */
