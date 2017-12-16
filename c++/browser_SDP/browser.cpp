#include "browser.hpp"

Browser::Browser()
{
}

void Browser::start()
{
    Tab defaultTab;

    while(true)
    {
        std::string newCommand; getline(std::cin, newCommand);
        std::vector<std::string> commands = splitter(newCommand);

        toLower(commands.at(0));
        std::string operation = commands.at(0);

        if(operation == "forward")
        {
            if(_dll.end().getElem() == _navigator.getElem())
                continue;

            ++_navigator;
        }

        else if(operation == "back")
        {
            if(_dll.begin().getElem() == _navigator.getElem())
                continue;

            --_navigator;
        }

        else if (operation == "insert")
        {
            if(commands.size() <= 1)
                continue;

            if(_dll.isEmpty())
            {
                _dll.insert(Tab(commands.at(1)));
                _navigator = _dll.begin();

                continue;
            }

            _dll.insert(Tab(commands.at(1)), _navigator);
            ++_navigator;
        }

        else if (operation == "remove")
        {
            _dll.remove(_navigator);

            if(_dll.isEmpty())
            {
                _navigator = DoubleLinkedListIterator<Tab>();
                defaultTab = Tab();
            }
        }

        else if (operation == "go")
        {
            if(commands.size() <= 1)
                continue;

            if(_dll.isEmpty())
            {
                _dll.insert(Tab(commands.at(1)));
                _navigator = _dll.begin();

                continue;
            }

            *_navigator = Tab(commands.at(1));
        }

        else if (operation == "print")
        {
            if(_dll.isEmpty())
            {
                std::cout << defaultTab << std::endl;
                continue;
            }

            for(DoubleLinkedListIterator<Tab> it = _dll.begin(); it; ++it)
                std::cout << ((it.getElem() == _navigator.getElem())?">":"") << *it << std::endl;
        }

        else if (operation == "sort")
        {
            if(_dll.isEmpty())
            {
                std::cout << defaultTab << std::endl;
                continue;
            }

            if(commands.size() <= 1)
                continue;

            toLower(commands.at(1));
            if(commands.at(1) == "url")
            {
                Tab::sortType = Tab::SortTypes::ByURL;
                _dll.sort();
                _navigator = _dll.begin();
            }
            else if(commands.at(1) == "time")
            {
                Tab::sortType = Tab::SortTypes::ByTime;
                _dll.sort();
                _navigator = _dll.begin();
            }
        }
    }
}

std::vector<std::string> Browser::splitter(std::string str)
{
    std::vector<std::string> ret;

    const unsigned int MAX_CHAR_LEN = 128;
    int i = 0;
    auto charArrGetter = [&MAX_CHAR_LEN]() -> char*
    {
        char* newWord = new char[MAX_CHAR_LEN];
        for(int i=0; i<MAX_CHAR_LEN; ++i)
            newWord[i] = '\0';
        return newWord;
    };
    char* newWord = charArrGetter();
    bool alreadyInserted = true;

    for(std::string::iterator it = str.begin(); it != str.end(); ++it)
    {
        if(*it != ' ')
        {
            alreadyInserted = false;
            newWord[i++] = *it;
        }
        else
        {
            if(alreadyInserted)
                continue;

            ret.push_back(std::string(newWord));
            delete newWord;
            newWord = nullptr;
            newWord = charArrGetter();
            i = 0;
            alreadyInserted = true;
        }
    }

    if(newWord)
        ret.push_back(std::string(newWord));

    delete newWord;
    newWord = nullptr;
    return ret;
}

void Browser::toLower(std::string& str)
{
    std::transform(str.begin(), str.end(), str.begin(), [](char in) -> char
    {
        if(in <= 'Z' && in >= 'A')
            return in - ('Z'-'z');
          return in;
    });
}
