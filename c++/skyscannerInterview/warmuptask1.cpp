#include <map>
#include <algorithm>
using namespace std;

int gemstones(vector <string> arr, int n)
{
    std::map<char, int> hasher;

    for(std::vector<string>::iterator it = arr.begin(); it != arr.end(); ++it)
    {
        std::vector<char> currentChars;

        for(std::string::iterator iit = (*it).begin(); iit != (*it).end(); ++iit)
        {
            if(std::find(currentChars.begin(), currentChars.end(), *iit) != currentChars.end())
                continue;
            else
                currentChars.push_back(*iit);

            std::map<char, int>::iterator mIter = hasher.find(*iit);

            if(mIter != hasher.end())
                ++(mIter->second);
            else
                hasher.insert(std::pair<char, int>(*iit, 1));
        }
    }

    int commonmGemStones = 0;
    for(std::map<char, int>::iterator it = hasher.begin(); it != hasher.end(); ++it)
        if(it->second == n)
            ++commonmGemStones;

    return commonmGemStones;
}

int main1() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = gemstones(arr, n);
    cout << result << endl;
    return 0;
}

/* Example:
 *   3
 *   abcdde
 *   baccd
 *   eeabg
 *
 *   2
 *
 *   Find common chars in all strings
 */
