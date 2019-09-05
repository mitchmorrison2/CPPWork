#include <iostream>
#include <cstring>
#include <fstream>

#include "mstring.h"

using namespace std;

int* readInTeam1(int* team1amt);
int* readInTeam2(int* team2amt);
int** readInMatches(int *rowsPtr);
void separateTeamsInfo(int *team1Nums, int *team2Nums, int **taggingInfo, int rowsOfInfo, int amtPlayers1, int amtPlayers2, int **team1Tags, int **team2Tags);
//void lowVerbosityOutput();

//This is a comment in main driver

int main(int argc, char **argv) {

    int *team1Nums = nullptr;
    int amtPlayers1 = 0, amtPlayers2 = 0, rowsOfInfo = 0;
    int *team1amt = &amtPlayers1, *team2amt = &amtPlayers2, *rowsPtr = &rowsOfInfo;
    team1Nums = readInTeam1(team1amt);
    int *team2Nums = nullptr;
    team2Nums = readInTeam2(team2amt);
    int **taggingInfo = nullptr;
    taggingInfo = readInMatches(rowsPtr);
    int **team1Tags = new int*[rowsOfInfo];
    int **team2Tags = new int*[rowsOfInfo];
    separateTeamsInfo(team1Nums, team2Nums, taggingInfo, rowsOfInfo, amtPlayers1, amtPlayers2, team1Tags, team2Tags);
    return 0;
}

int* readInTeam1(int *team1amt) {
    char fileName[] = "Cowboys.txt";
    fstream fIn(fileName);
    if (!fIn.is_open()) {
        cout << fileName << " not opening" << endl;
    }
    char buffer[40], teamName[40];
    fIn.getline(teamName, 40);
    int numPlayers1;
    fIn >> numPlayers1;
    cout << numPlayers1 << endl;
    *team1amt = numPlayers1;
    int *playerNums = new int[numPlayers1];
    mString *playerNames = new mString[numPlayers1];
    int tempNum;

    int counter = 0;
    while (fIn.is_open()) {
        fIn >> tempNum;
        playerNums[counter] = tempNum;
        fIn >> buffer;
        playerNames[counter] = buffer;
        counter++;
        if (counter == *team1amt) {
            break;
        }
    }
    fIn.close();
    cout << "Team name: " << teamName << endl << "Num players: " << numPlayers1 << endl;
    for (int i = 0; i < numPlayers1; i++) {
        mString temp = playerNames[i];
        cout << "Player number: " << playerNums[i] << endl;
        cout << "Player name: " << playerNames[i] << endl;
    }
    cout << endl;
    return playerNums;
  }

int* readInTeam2(int* team2amt) {
    char fileName[] = "Sharks.txt";
    fstream fIn(fileName);
    if (!fIn.is_open()) cout << fileName << " not opening" << endl;
    char buffer[40], teamName[40];
    fIn.getline(teamName, 40);
    fIn >> *team2amt;
    int *playerNums = new int[*team2amt];
    mString *playerNames = new mString[*team2amt]; // = new mString[amtPlayers];
    int tempNum; //copy into playerNums

    int counter = 0;
    while (fIn.is_open()) {
        fIn >> tempNum;
        playerNums[counter] = tempNum;
        fIn >> buffer;
        playerNames[counter] = buffer;
        counter++;
        if (counter == *team2amt) {
            break;
        }
    }
    fIn.close();

    cout << "Team name: " << teamName << endl << "Num players: " << *team2amt << endl;
    for (int i = 0; i < *team2amt; i++) {
        mString temp = playerNames[i];
        cout << "Player number: " << playerNums[i] << endl;
        cout << "Player name: " << temp << endl;  //once friend << operator works this should work
    }
    cout << endl;
    return playerNums;
}

int** readInMatches(int *rowsPtr) {
    char fileName[] = "match1.txt";
    fstream fIn(fileName);
    int colCount = 4;
    int rowsAmt;
    fIn >> rowsAmt;
    *rowsPtr = rowsAmt;
    int **taggingInfo = new int* [*rowsPtr];
    for (int i = 0; i < *rowsPtr; i++) {
        taggingInfo[i] = new int[colCount];
    }
    int row = 0;
    int counter = 0;
    while(!fIn.eof()) {
        fIn >> taggingInfo[row][counter];
        counter++;
        if (counter == colCount) {
            counter = 0;
            row++;
        }
    }
    fIn.close();

    for (int x = 0; x < *rowsPtr; x++) {
        for (int y = 0; y < colCount; y++) {
            cout << taggingInfo[x][y] << " ";
            if (y == colCount -1) cout << endl;
        }
    }
    cout << endl;
    return taggingInfo;
}

void separateTeamsInfo(int *team1Nums, int *team2Nums, int **taggingInfo, int rowsOfInfo, int amtPlayers1, int amtPlayers2, int **team1Tags, int **team2Tags) {
    int counterTeam1 = 0, counterTeam2 = 0;

    for (int r = 0; r < rowsOfInfo; r++) { //rows of info needs to be passed properly or called by readInMatches method so it passes back proper information
         for (int w = 0; w < amtPlayers1; w++) {
              if (taggingInfo[r][0] == team1Nums[w]) {
                  team1Tags[counterTeam1] = taggingInfo[r]; //place tag into new 2d array
                  cout << team1Tags[w] << endl;
                  counterTeam1++;
                  break;
              }
         } //inside for loop
            for (int y = 0; y < amtPlayers2; y++) {
                 if (taggingInfo[r][0] == team2Nums[y]) {
                   team2Tags[counterTeam2] = taggingInfo[r]; //place tag into new 2d array
                   cout << team2Tags[y] << endl;
                   counterTeam2++;
                   break;
                 }
            } //inside for loop
    } //outside for loop
}
