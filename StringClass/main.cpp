#include <iostream>
#include <cstring>
#include <fstream>

#include "mstring.h"

using namespace std;

int* readInTeam1(int* team1amt, char* fileName1, char* team1Name);
int* readInTeam2(int* team2amt, char* fileName2, char* team2Name);
int** readInMatches(int *rowsPtr, char* matchFile);
void lowVerbosityOutput(int ** taggingInfo, int* team1Nums, int* team2Nums, int rowsOfInfo, char *team1Name, char *team2Name);

static int COLCOUNT = 4;

int main(int argc, char *argv[]) {

    if (argc > 6) cout << "Not correct amount of arguments" << endl;

    //declare and initialize arguments
    char* fileName1 = argv[1];
    char* fileName2 = argv[2];
    char* matchFile = argv[3];

    int *team1Nums = nullptr, *team2Nums = nullptr, **taggingInfo = nullptr; //team numbers and tagging arrays pointer declarations
    int amtPlayers1 = 0, amtPlayers2 = 0, rowsOfInfo = 0; //declaring some ints for later use
    int *team1amt = &amtPlayers1, *team2amt = &amtPlayers2, *rowsPtr = &rowsOfInfo; //creating references to these ints for pass

    char* team1Name = nullptr;
    char* team2Name = nullptr;

    //call functions, return filled in information to be passed again later
    team1Nums = readInTeam1(team1amt, fileName1, team1Name);
    team2Nums = readInTeam2(team2amt, fileName2, team2Name);
    taggingInfo = readInMatches(rowsPtr, matchFile);

    lowVerbosityOutput(taggingInfo, team1Nums, team2Nums, rowsOfInfo, team1Name, team2Name);
    return 0;
}

int* readInTeam1(int *team1amt, char* fileName1, char* team1Name) {
    //opening file from command line arg
    fstream fIn(fileName1);
    if (!fIn.is_open()) cout << fileName1 << " not opening" << endl;

    char buffer[40], teamName[40];
    team1Name = teamName;

    //getting team name and number of players
    fIn.getline(team1Name, 40);
    int numPlayers1;
    fIn >> numPlayers1;
    *team1amt = numPlayers1; //changes the ref variable

    //declare playerNums and names arrays(type mString)
    int *playerNums = new int[numPlayers1];
    mString *playerNames = new mString[numPlayers1];

    //read in all player information to 2 arrays
    int counter = 0;
    while (fIn.is_open()) {
        fIn >> playerNums[counter];
        fIn >> buffer;
        playerNames[counter] = buffer;
        counter++;
        if (counter == *team1amt) {
            break;
        }
    }
    fIn.close(); //closing file, all data is now in arrays

    cout << "Team name: " << teamName << endl << "Num players: " << numPlayers1 << endl;
    for (int i = 0; i < numPlayers1; i++) {
        mString temp = playerNames[i];
        cout << "Player number: " << playerNums[i] << endl;
        cout << "Player name: " << playerNames[i] << endl;
    }
    cout << endl;
    return playerNums;
  }

int* readInTeam2(int* team2amt, char* fileName2, char* team2Name) {
    //opening file from command line arg
    fstream fIn(fileName2);
    if (!fIn.is_open()) cout << fileName2 << " not opening" << endl;
    char buffer[40], teamName[40];
    team2Name = teamName;

    //getting team name and number of players
    fIn.getline(teamName, 40);
    fIn >> *team2amt;

    //declare playerNums and names arrays(type mString)
    int *playerNums = new int[*team2amt];
    mString *playerNames = new mString[*team2amt]; // = new mString[amtPlayers];

    //read in all player information to 2 arrays
    int counter = 0;
    while (fIn.is_open()) {
        fIn >> playerNums[counter];
        fIn >> buffer;
        playerNames[counter] = buffer;
        counter++;
        if (counter == *team2amt) {
            break;
        }
    }
    fIn.close(); //close file all data is in the arrays

    cout << "Team name: " << teamName << endl << "Num players: " << *team2amt << endl;
    for (int i = 0; i < *team2amt; i++) {
        mString temp = playerNames[i];
        cout << "Player number: " << playerNums[i] << endl;
        cout << "Player name: " << temp << endl;  //once friend << operator works this should work
    }
    cout << endl;
    return playerNums;
}

int** readInMatches(int *rowsPtr, char* matchFile) {
    //open file thru command line arg start to read in data
    fstream fIn(matchFile);
    int rowsAmt;
    fIn >> rowsAmt;
    *rowsPtr = rowsAmt; //change reference variable in main

    //make the taggingInfo array 2d [rowsAmt][colCount]
    int **taggingInfo = new int* [*rowsPtr];
    for (int i = 0; i < *rowsPtr; i++) taggingInfo[i] = new int[COLCOUNT];

    //read in info to 2d array
    int row = 0;
    int counter = 0;
    while(!fIn.eof()) {
        fIn >> taggingInfo[row][counter];
        counter++;
        if (counter == COLCOUNT) {
            counter = 0;
            row++;
        }
    }
    fIn.close();

    for (int x = 0; x < *rowsPtr; x++) {
        for (int y = 0; y < COLCOUNT; y++) {
            cout << taggingInfo[x][y] << " ";
            if (y == COLCOUNT -1) cout << endl;
        }
    }
    cout << endl;
    return taggingInfo;
}

void lowVerbosityOutput(int ** taggingInfo, int *team1Nums, int *team2Nums, int rowsOfInfo, char *team1Name, char *team2Name) {
    //points system: Back(1) = 5, Chest(2) = 8, Shoulder(3) = 7, Laser Gun (4) = 4
    int back = 5, chest = 8, shoulder = 7, laserGun = 4;

    int team1Score = 0, team2Score = 0;

    for (int a = 0; a < rowsOfInfo; a++) {
        for (int q = 0; q < 3; q++) {
            if (taggingInfo[a][0] == team1Nums[q]) {
                if (taggingInfo[a][3] == 1) team1Score += back;
                else if (taggingInfo[a][3] == 2) team1Score += chest;
                else if (taggingInfo[a][3] == 3) team1Score += shoulder;
                else if (taggingInfo[a][3] == 4) team1Score += laserGun;
            }
        }
    }

    cout << endl << "Team 1 scored: " << team1Score << endl;

    for (int b = 0; b < rowsOfInfo; b++) {
        for (int p = 0; p < 3; p++) {
            if (taggingInfo[b][0] == team2Nums[p]) {
                if (taggingInfo[b][3] == 1) team2Score += back;
                else if (taggingInfo[b][3] == 2) team2Score += chest;
                else if (taggingInfo[b][3] == 3) team2Score += shoulder;
                else if (taggingInfo[b][3] == 4) team2Score += laserGun;
            }
        }
    }

    cout << endl << "Team 2 scored: " << team2Score << endl;

    //cout << "Team 1: " << *team1Name << "Team 2: " << *team2Name;

}
