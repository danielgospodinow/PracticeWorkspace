/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Daniel Gospodinow
 * @idnumber 81531
 * @task 4
 * @compiler GCC
 *
 */

#include <iostream>
#include <string.h>
using namespace std;

string charToStr(char c);
bool collisionOnDiagonals(string attackingFigureCoord, string kingFigureCoord);
bool checkDownLeftDiag(string attackingFigureCoord, string kingFigureCoord);
bool checkDownRightDiag(string attackingFigureCoord, string kingFigureCoord);
bool checkUpRightDiag(string attackingFigureCoord, string kingFigureCoord);
bool checkUpLeftDiag(string attackingFigureCoord, string kingFigureCoord);
bool collisionOnLines(string attackingFigureCoord, string kingFigureCoord);
bool collisionOnCircle(string attackingFigureCoord, string kingFigureCoord);
bool isTurnValid(string turn);

int main(int argc, char *argv[])
{
    char attackingFigure = ' ', attackingFigureCoord[2], kingFigureCoord[2];
    cin >> attackingFigure >> attackingFigureCoord[0] >> attackingFigureCoord[1] >> kingFigureCoord[0] >> kingFigureCoord[1];

    if((!(((int)'a' <= (int) attackingFigureCoord[0] && (int) attackingFigureCoord[0] <= (int)'h' && (int)'1' <= (int)attackingFigureCoord[1] && (int)attackingFigureCoord[1] <= (int)'8') &&
           ((int)'a' <= (int) kingFigureCoord[0] && (int) kingFigureCoord[0] <= (int)'h' && (int)'1' <= (int)kingFigureCoord[1] && (int)kingFigureCoord[1] <= (int)'8'))) ||
            (attackingFigure != 'Q' && attackingFigure != 'B' && attackingFigure != 'N' && attackingFigure != 'R'))
        return 0;

    string afcStr = charToStr(attackingFigureCoord[0]) + charToStr(attackingFigureCoord[1]), kfcStr = charToStr(kingFigureCoord[0]) + charToStr(kingFigureCoord[1]);

    switch (attackingFigure) {
    case 'R': cout << ((afcStr == kfcStr || collisionOnLines(afcStr, kfcStr))?"Yes":"No") << endl; break;
    case 'B': cout << ((afcStr == kfcStr || collisionOnDiagonals(afcStr, kfcStr))?"Yes":"No") << endl; break;
    case 'Q': cout << ((afcStr == kfcStr || collisionOnDiagonals(afcStr, kfcStr) || collisionOnLines(afcStr, kfcStr))?"Yes":"No") << endl; break;
    case 'N': cout << ((afcStr == kfcStr || collisionOnCircle(afcStr, kfcStr))?"Yes":"No") << endl; break;
    default: break;
    }

    return 0;
}

bool checkDownLeftDiag(string attackingFigureCoord, string kingFigureCoord)
{
    if((char)(attackingFigureCoord[0] - 1) >= 'a' - 1 && (char)(attackingFigureCoord[1] - 1) >= '1' - 1)
        if(checkDownLeftDiag(charToStr((char)(attackingFigureCoord[0] - 1)) + charToStr((char)(attackingFigureCoord[1] - 1)), kingFigureCoord))
            return true;
    else
        return attackingFigureCoord == kingFigureCoord;
}

bool checkDownRightDiag(string attackingFigureCoord, string kingFigureCoord)
{
    if((char)(attackingFigureCoord[0] + 1) <= 'h' + 1 && (char)(attackingFigureCoord[1] - 1) >= '1' - 1)
        if(checkDownRightDiag(charToStr((char)(attackingFigureCoord[0] + 1)) + charToStr((char)(attackingFigureCoord[1] - 1)), kingFigureCoord))
            return true;
    else
        return attackingFigureCoord == kingFigureCoord;
}

bool checkUpRightDiag(string attackingFigureCoord, string kingFigureCoord)
{
    if((char)(attackingFigureCoord[0] + 1) <= 'h' + 1 && (char)(attackingFigureCoord[1] + 1) <= '8' + 1)
        if(checkUpRightDiag(charToStr((char)(attackingFigureCoord[0] + 1)) + charToStr((char)(attackingFigureCoord[1] + 1)), kingFigureCoord))
            return true;
    else
        return attackingFigureCoord == kingFigureCoord;
}

bool checkUpLeftDiag(string attackingFigureCoord, string kingFigureCoord)
{
    if((char)(attackingFigureCoord[0] - 1) >= 'a' - 1 && (char)(attackingFigureCoord[1] + 1) <= '8' + 1)
        if(checkUpLeftDiag(charToStr((char)(attackingFigureCoord[0] - 1)) + charToStr((char)(attackingFigureCoord[1] + 1)), kingFigureCoord))
            return true;
    else
        return attackingFigureCoord == kingFigureCoord;
}

bool collisionOnDiagonals(string attackingFigureCoord, string kingFigureCoord)
{
    return  checkDownLeftDiag(attackingFigureCoord, kingFigureCoord) ||
                checkDownRightDiag(attackingFigureCoord, kingFigureCoord) ||
                checkUpRightDiag(attackingFigureCoord, kingFigureCoord) ||
                checkUpLeftDiag(attackingFigureCoord, kingFigureCoord);
}

string charToStr(char c)
{
    return string(1, c);
}

bool collisionOnLines(string attackingFigureCoord, string kingFigureCoord)
{
    if((kingFigureCoord.find(attackingFigureCoord[0]) != std::string::npos) || (kingFigureCoord.find(attackingFigureCoord[1]) != std::string::npos))
        return true;

    return false;
}

bool collisionOnCircle(string attackingFigureCoord, string kingFigureCoord)
{
    bool ret = false;

    string turn1 = charToStr(((char)attackingFigureCoord[0] + 1)) + charToStr(((char)attackingFigureCoord[1] + 2));
    string turn2 = charToStr(((char)attackingFigureCoord[0] - 1)) + charToStr(((char)attackingFigureCoord[1] + 2));
    string turn3 = charToStr(((char)attackingFigureCoord[0] - 2)) + charToStr(((char)attackingFigureCoord[1] + 1));
    string turn4 = charToStr(((char)attackingFigureCoord[0] + 2)) + charToStr(((char)attackingFigureCoord[1] + 1));
    string turn5 = charToStr(((char)attackingFigureCoord[0] - 2)) + charToStr(((char)attackingFigureCoord[1] - 1));
    string turn6 = charToStr(((char)attackingFigureCoord[0] + 2)) + charToStr(((char)attackingFigureCoord[1] - 1));
    string turn7 = charToStr(((char)attackingFigureCoord[0] - 1)) + charToStr(((char)attackingFigureCoord[1] - 2));
    string turn8 = charToStr(((char)attackingFigureCoord[0] + 1)) + charToStr(((char)attackingFigureCoord[1] - 2));

    if(isTurnValid(turn1) && turn1 == kingFigureCoord)
        return true;
    else if(isTurnValid(turn2) && turn2 == kingFigureCoord)
        return true;
    else if(isTurnValid(turn3) && turn3 == kingFigureCoord)
        return true;
    else if(isTurnValid(turn4) && turn4 == kingFigureCoord)
        return true;
    else if(isTurnValid(turn5) && turn5 == kingFigureCoord)
        return true;
    else if(isTurnValid(turn6) && turn6 == kingFigureCoord)
        return true;
    else if(isTurnValid(turn7) && turn7 == kingFigureCoord)
        return true;
    else if(isTurnValid(turn8) && turn8 == kingFigureCoord)
        return true;


    return ret;
}

bool isTurnValid(string turn)
{
    if((turn[0] >= 'a' && turn[0] <= 'h') &&
            (turn[1] >= '1' && turn[1] <= '8'))
        return true;

    return false;
}
