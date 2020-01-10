#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>


using namespace std;

class parser
{
public:
    parser();
    void go();
    string getFilePath();
    vector<string> extractKeyWords(string);
    void writeToFile(vector<string>);
};

#endif // PARSER_H
