#include "ladder.h"
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

void error(string word1, string word2, string msg)
{
    cerr <<"Error: " << word1 << " and " << word2 << "[" << msg << "]\n";
}

void load_words(set<string> &word_list, const string &file_name)
{
    ifstream inFile(file_name);
    if(!inFile)
    {
        error("File", "File", "File isnt opening");
        return;
    }

    string word;
    while (inFile >> word)
    {
        word_list.insert(word);
    }

    inFile.close();
}

bool is_adjacent(const string &word1, const string &word2)
{
    int len1 = word1.size();
    int len2 = word2.size();

    if(len1 == len2)
    {
        int count = 0;
        for(int i = 0; i < len1; ++i)
        {
            if(word1.at(i) != word2.at(i))
                ++count;
        }
        if (count <= 1)
            return true;
        return  false;
    }

    if( abs(len1-len2) == 1) // This checks if the lengths are longer than 1
    {
        int i = 0, j = 0;
        bool changeMade = false;

        while ( i < len1 && j < len2)
        {
            if(word1[i] != word2[j])
            {
                if(len1 > len2) i++;
                else j++;
                if(changeMade) return false;
                changeMade = true;
            }
            else i++,j++;
        }
        return true;
    }
    return false;
}

vector<string> generate_word_ladder(const string &begin_word, const string &end_word, const set<string> &word_list)
{
    if(begin_word == end_word )
    {
        error(begin_word,end_word,"Can't start and end with the same word (INFINITE LOOP)!");
        return {};
    }

    queue<vector<string>> ladderQueue;
    ladderQueue.push({begin_word});

    set<string> visited;
    visited.insert(begin_word);

    while(!ladderQueue.empty())
    {
        vector<string> ladder = ladderQueue.front();
        ladderQueue.pop();

        string lastWord = ladder.back();

        for(const string & word: word_list)
        {
            if(is_adjacent(lastWord,word) && visited.find(word) == visited.end())
            {
                vector<string> newLadder = ladder;
                newLadder.push_back(word);
                if(word == end_word)
                    return newLadder;
                ladderQueue.push(newLadder);
                visited.insert(word);
            }
        }
    }
    return {};
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d)   //apparently this should of been a helper function for is adjacent?
{
    int len1 = str1.size();
    int len2 = str2.size();

    if(len1 == len2)
    {
        int count = 0;
        for(int i = 0; i < len1; ++i)
        {
            if(str1.at(i) != str2.at(i))
                ++count;
        }
        if (count <= d)
            return true;
        return  false;
    }

    if( abs(len1-len2) == 1) // This checks if the lengths are longer than 1
    {
        int i = 0, j = 0;
        bool changeMade = false;

        while ( i < len1 && j < len2)
        {
            if(str1[i] != str2[j])
            {
                if(len1 > len2) i++;
                else j++;
                if(changeMade) return false;
                changeMade = true;
            }
            else i++,j++;
        }
        return true;
    }
    return false;
};

void print_word_ladder(const vector<string>& ladder)
{
    if(!ladder.empty())
    {
        cout << "Word ladder found: ";
        for(const string & word: ladder) cout << word << " ";
    }
    else cout << "No word ladder found.";
    cout << endl;
}