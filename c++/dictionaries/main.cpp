#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

std::vector<std::string> split(std::string const& str)
{
    auto isPartOfWord = [](char c) -> bool
    {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    };

    auto extractWord = [](std::vector<char> const& vec, std::vector<std::string> & ret)
    {
        std::string temp = "";

        for(int i=0; i<vec.size(); ++i)
            temp += vec[i];

        //Помислих си, че е нужно всеки string да е lowercase, ама не е така :D
        //std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

        if(temp != "")
            ret.push_back(temp);
    };

    std::vector<std::string> ret;
    std::vector<char> currentStr;

    for(int i=0; i<str.length(); ++i)
    {
        if(isPartOfWord(str[i]))
            currentStr.push_back(str[i]);
        else
        {
            extractWord(currentStr, ret);
            currentStr.clear();
        }
    }

    return ret;
}

void task3()
{
    std::string t1 = "In computing, a hash table (hash map) is a data structure used to implement an associative array, a structure that can map keys to values. A hash table uses a hash function to compute an index into an array of buckets or slots, from which the correct value can be found.", 
        t2 = "Ideally, the hash function will assign each key to a unique bucket, but this situation is rarely achievable in practice (usually some keys will hash to the same bucket)";

    std::vector<std::string> t1Split = split(t1);
    std::vector<std::string> t2Split = split(t2);

    std::map<std::string, int> matchingMap;
    int occurencies = 0;

    for(int i=0; i<t1Split.size(); ++i)
        matchingMap[t1Split[i]] = -1;

    for(int i=0; i<t2Split.size(); ++i)
        if(matchingMap[t2Split[i]] == -1)
            ++occurencies;

    std::cout << "Total occurencies between the two strings: " << occurencies << std::endl;
}

void task4()
{
    std::string t1 = "In computing, tashaci a hash table (hash map) is a data structure used to implement an associative array, a structure that can map keys to values. A hash table uses a hash function to compute an index into an array of buckets or slots, from which the correct value can be found.", 
        t2 = "Ideally, tashaci the hash function will assign each key to a unique bucket, but this situation is rarely achievable in practice (usually some keys will hash to the same bucket)";

    std::vector<std::string> t1Split = split(t1);
    std::vector<std::string> t2Split = split(t2);

    std::map<std::string, int> t1Words;
    for(int i=0; i<t1Split.size(); ++i)
        t1Words[t1Split[i]] = -1;

    std::map<std::string, int> t2Words;
    for(int i=0; i<t2Split.size(); ++i)
        t2Words[t2Split[i]] += 1;

    int totalUniqueWords = 0;
    for(auto iter = t2Words.begin(); iter != t2Words.end(); ++iter)
    {
        if(iter->second == 1 && t1Words[iter->first] == -1)
        {
            //std::cout << "Unique word: " << iter->first << std::endl;
            ++totalUniqueWords;
        }
    }

    std::cout << "Total t2 unique strings that are contained by t1: " << totalUniqueWords << std::endl;
}

void task5()
{
    std::string t = "In computing, a hash table (hash map) is a data structure used to implement an associative array, a structure that can map keys to values. A hash table uses a hash function to compute an index into an array of buckets or slots, from which the correct value can be found";
    std::vector<std::string> tSplit = split(t);

    std::map<std::string, int> words;
    std::pair<std::string, int> bestString = {"", 0};

    for(int i=0; i<tSplit.size(); ++i)
        words[tSplit[i]] += 1;

    for(auto iter = words.begin(); iter != words.end(); ++iter)
        if(iter->first.size() >= 3)
            if(iter->second > bestString.second)
                bestString = {iter->first, iter->second};

    std::cout << "Most common word with length 3 or more: " << bestString.first << std::endl;
}

int main()
{
    task3();
    task4();
    task5();

    return 0;
}