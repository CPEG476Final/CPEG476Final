#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;
 
struct AdjList
{
    string head;
    int headFreq;
    vector <string> children;
    vector <int> freq;
};
 
struct Graph
{
    vector<struct AdjList> lists; 
};
 
void addElement(struct Graph* graph, string word, string nextWord)
{
    vector<struct AdjList>::iterator it;  // declare an iterator to a vector of strings
    vector<string>::iterator stringIt;
    int foundOuter = 0;  // counter.
    int foundInner = 0;
    int count = 0;
    
    for(it=graph->lists.begin() ; it < graph->lists.end(); it++) {
        if (word.compare((*it).head) == 0) {
            foundOuter = 1;
            count = 0;
            (*it).headFreq++;
            for(stringIt=(*it).children.begin(); stringIt<(*it).children.end(); stringIt++){
                if (nextWord.compare(*stringIt) == 0) {
                    (*it).freq.at(count)++;
                    foundInner = 1;
                }
                count++;
            }
            if (foundInner == 0){
                (*it).children.push_back(nextWord);
                (*it).freq.push_back(1);
            }
        }
    }
    if (foundOuter == 0) {
        struct AdjList* newList = (AdjList*)malloc(sizeof(struct AdjList));
        newList->head = word;
        newList->headFreq = 1;
        newList->children.push_back(nextWord);
        newList->freq.push_back(1);
        graph->lists.push_back(*newList);
    }
}

// Parses word to see if there's punctuation
string hasPunctuation(string word){
    if(word.find(".") != string::npos){
        return ".";
    }
    if(word.find(",") != string::npos){
        return ",";
    }
    if(word.find("!") != string::npos){
        return "!";
    }
    if(word.find("?") != string::npos){
        return "?";
    }
    return "";
}

// Reads input text file and creates graph out of words
int readFile(string fileName){
    struct Graph* theGraph = (Graph*) malloc(sizeof(struct Graph));
    string word;
    string prevWord = "";
    ifstream myfile(fileName.c_str());
    if(myfile.is_open()){
        while(myfile >> word){
            string punctuation = hasPunctuation(word);
            if(punctuation != ""){
                cout << word.substr(0, word.find(punctuation)) << '\n';
                cout << punctuation << '\n';
                if(prevWord != ""){
                     // send prevWord, word
                     addElement(theGraph, prevWord, word);
                }
                // send word, punctuation
                addElement(theGraph, word.substr(0, word.find(punctuation)), punctuation);
                prevWord = punctuation;
            }
            else{
                cout << word << '\n';
                if(prevWord != ""){
                    //send prevWord and word
                    addElement(theGraph, prevWord, word);
                }
                prevWord = word;
            }
        }
        myfile.close();
    }
    else{
        cout << "Cannot open and read file :(" << '\n';
    }
    return 0;
}

int main () {
  readFile("input1.txt");
}
