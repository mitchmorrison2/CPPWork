#include <iostream>
#include <cstring>
#include <fstream>

#include "mstring.h"

using namespace std;

int* readInTeam1(int amtPlayers1);
int* readInTeam2(int amtPlayers2);
int** readInMatches();
void separateTeamsInfo(int *team1Nums, int *team2Nums, int** taggingInfo);
//void lowVerbosityOutput();

int main()
{
    int *team1Nums = nullptr, amtPlayers1 = 0;
    team1Nums = readInTeam1(amtPlayers1);
    int *team2Nums = nullptr, amtPlayers2 = 0;
    team2Nums = readInTeam2(amtPlayers2);
    int **taggingInfo = nullptr;
    taggingInfo = readInMatches();
    separateTeamsInfo(team1Nums, team2Nums, taggingInfo);
    return 0;
}

int* readInTeam1(int amtPlayers1) {
    char fileName[] = "Cowboys.txt";
    fstream fIn(fileName);
    if (!fIn.is_open()) cout << fileName << " not opening" << endl;
    char buffer[40], teamName[40];

    fIn.getline(teamName, 40);
    fIn >> amtPlayers1;
    int *playerNums = new int[amtPlayers1];
    mString *playerNames = new mString[amtPlayers1];
    int tempNum;

    int counter = 0;
    while (!fIn.eof()) {
        fIn >> tempNum;
        playerNums[counter] = tempNum;
        fIn >> buffer;
        playerNames[counter] = buffer;
        counter++;
        if (counter == amtPlayers1) {
            break;
        }
    }
    fIn.close();
    cout << "Team name: " << teamName << endl << "Num players: " << amtPlayers1 << endl;
    for (int i = 0; i < amtPlayers1; i++) {
        mString temp = playerNames[i];
        cout << "Player number: " << playerNums[i] << endl;
        cout << "Player name: " << playerNames[i] << endl;
    }
    cout << endl;
    return playerNums;
  }

int* readInTeam2(int amtPlayers2) {
    char fileName[] = "Sharks.txt";
    fstream fIn(fileName);
    if (!fIn.is_open()) cout << fileName << " not opening" << endl;
    char buffer[40], teamName[40];

    fIn.getline(teamName, 40);
    fIn >> amtPlayers2;
    int *playerNums = new int[amtPlayers2]; // = new int[amtPlayers];
    mString *playerNames = new mString[amtPlayers2]; // = new mString[amtPlayers];

    int tempNum; //copy into playerNums
    int counter = 0;
    while (fIn.is_open()) {
        fIn >> tempNum;
        playerNums[counter] = tempNum;
        fIn >> buffer;
        playerNames[counter] = buffer;
        counter++;
        if (counter == amtPlayers2) {
            break;
        }
    }
    fIn.close();

    cout << "Team name: " << teamName << endl << "Num players: " << amtPlayers2 << endl;
    for (int i = 0; i < amtPlayers2; i++) {
        mString temp = playerNames[i];
        cout << "Player number: " << playerNums[i] << endl;
        cout << "Player name: " << temp << endl;  //once friend << operator works this should work
    }
    cout << endl;
    return playerNums;
}

int** readInMatches() {
    char fileName[] = "match1.txt";
    fstream fIn(fileName);
    int rowsOfInfo, colCount = 4;
    fIn >> rowsOfInfo;
    int **taggingInfo = new int* [rowsOfInfo];
    for (int i = 0; i < rowsOfInfo; i++) {
        taggingInfo[i] = new int[colCount];
    }
    int rows = 0;
    int counter = 0;
    while(!fIn.eof()) {
        fIn >> taggingInfo[rows][counter];
        counter++;
        if (counter == colCount) {
            counter = 0;
            rows++;
        }
    }
    fIn.close();

    for (int x = 0; x < rowsOfInfo; x++) {
        for (int y = 0; y < colCount; y++) {
            cout << taggingInfo[x][y] << " ";
            if (y == colCount -1) cout << endl;
        }
    }
    cout << endl;
    return taggingInfo;
}

void separateTeamsInfo(int *team1Nums, int *team2Nums, int **taggingInfo) {



//    int team1tags[][] = 0; //create 2 arrays with their tags separate to simplify. Just use the first number from each row to distinguish teams
//    int team2tags[][] = 0;

}
