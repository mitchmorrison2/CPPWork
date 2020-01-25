#include "parser.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

parser::parser()
{

}

void parser::go() {
    string name = getFilePath();
    vector<string> allWords = extractKeyWords(name);
    writeToFile(allWords);
}

string parser::getFilePath() {
//    cout << "Enter the file name: " ; // "../HTMLText"
    string fileName;
    fileName = "../HTMLText";
//    getline(cin, fileName);
    return fileName;
}

vector<string> parser::extractKeyWords(string file) {
    ifstream openFile(file);
    vector<string> areas;
    if (openFile.is_open()) {
        string buffer;
        getline(openFile, buffer);
//        cout << buffer;
        int count = 0;
        for (size_t a = 0; a < buffer.size(); a++) {
            if (buffer[a] == 0x3e) {
                count++;
                continue;
            }
            string word;
            if (count != 0 && count % 2 == 0) { //pattern present where inbetween 4 and 5 of these characters is the important content
                while (buffer[a] != 0x3c) {
                   word += buffer[a];
                   a++;
                }

                if (buffer[a] == '<') {
                    areas.push_back(word);
                    count = 0;
                    word = "";
                }
            }
        }
        return areas;
    }
    else {
        cout << "File not opening" << endl;
    }
}

void parser::writeToFile(vector<string> wordsVector) {
    ofstream output("../QualcommSections");
    for (size_t a = 0; a < wordsVector.size(); a++) {
        output << wordsVector.at(a) << endl;
    }
}
