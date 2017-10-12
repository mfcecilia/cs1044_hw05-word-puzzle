#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

string user;
int numWords;
std::vector< int > contents;
ifstream textFile;
int word;
std::vector< char > phrase;
int results;
char c;
string message = "";
vector<string>all;

void loopPhrase()
{
    if (phrase.size() > 0)
    {
        for (int i = 0; i < phrase.size(); i++)
        {
            cout << phrase[i];
        }
    }
}

void loopContents()
{
    if(contents.size() > 0)
    {
        for (int j = 0; j < contents.size(); j++)
        {
            cout << "contents = " << contents[j];
        }
    }
}


/**
do math here and cast things to char.
append each word to a vector.
*/
void convert()
{
    //add two at a time and cast to a char
    for (int x = 0; x < word; x++)
    {
        contents.push_back(x);
        contents.push_back(x);
        results = contents[0] + contents[1];
        loopContents();
        char c = results;
        cout << char (65 + results) << endl;
        cout << "new letter = " << c << endl;
        cout << "results = " << results << endl;
        message += char(65 + results);
        //cast to char via function call
        contents.clear();
        phrase.push_back(c);
        loopPhrase();
        loopContents();
    }
}

void retrieve()
{
    //loop through phrase
    for (int a = 0; a < numWords; a++)
    {
        textFile >> word >> ws; //place holder for compilation
        //technically this is where i'd get the whole line
        //cin.getline(textFile, word);
    }
    cout << "word = " << word << endl;
}


/**
main method
*/
int main()
{
    cout << "Enter Filename: " << endl;
    cin >> user;
    textFile.open(user.c_str());
    if (!textFile.is_open())
    {
        cout << " Cannot open file!" << endl;
    }

    while(textFile)
    {
        textFile >> numWords;
        cout << "numWords = " << numWords << endl;
        if (numWords > 0)
        {
            retrieve();
            convert();
        }
        else
        {
            textFile.close();
        }
        all.push_back(message);

    }

}
