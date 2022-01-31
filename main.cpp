/*******************************************************************************
 * program name: cis65 programming assignment 1
 * created date: 1/30/22
 * created by: josh m dye
 * purpose:
 * acknowledgements:
 * copyright 2022 josh m dye licensed under the
 * educational community license, version 2.0 (the "license"); you may
 * not use this file except in compliance with the license. you may
 * obtain a copy of the license at
 * http://www.osedu.org/licenses/ecl-2.0
 * unless required by applicable law or agreed to in writing,
 * software distributed under the license is distributed on an "as is"
 * basis, without warranties or conditions of any kind, either express
 * or implied. see the license for the specific language governing
 * permissions and limitations under the license.
 *******************************************************************************/
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;
void print(vector<string> const &a);
void print(vector<int> const &a);

int main()
{
    vector<string> uniqueWords;    //hold unique word list
    vector<int> wordOccurrences;    //hold numbers for compressed file
    string currentWord;
    bool found;
    int index;

    ifstream toCompress;
    toCompress.open("input.txt");                 //try to open file
    if (!toCompress) {
        cout << "file could not be opened.";
        return 1;
    }
    while (toCompress >> currentWord) { //put next word into currentWord
        found = false;
        for (int i = 0; i < (uniqueWords.size()); i++) {
            if (uniqueWords.at(i) == currentWord) {
                found = true; // set to true if currentWord found in list
                index = i;               //set index to position found at
                break;                          //if found, exit for loop
            }
        }
        if (!found) {
            uniqueWords.push_back(currentWord);      //if not found, add to list
            index = int(uniqueWords.size() - 1); //set index to position on list
        }
        wordOccurrences.push_back(index);
    }
    print(wordOccurrences);
    cout << endl;
    print(uniqueWords);

    return 0;
}
void print(vector<string> const &input)
{
    for (int i = 0; i < input.size(); i++) {
        cout << i << "-" << input.at(i) << ' ';
    }
}
void print(vector<int> const &input)
{
    for (int i: input) {
        cout << i << ' ';
    }
}