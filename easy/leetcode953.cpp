#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

bool isAlienSorted(vector<string> &words, string order)
{
    map<char, int> dic;
    for (int i = 0; i < order.length(); i++)
    {
        dic[order[i]] = i;
    }

    for (int i = 0; i < words.size() - 1; i++)
    {
        string word1 = words[i];
        string word2 = words[i + 1];
        bool flag = true;
        for (int j = 0; j < min(word1.length(), word2.length()); j++)
        {
            if (word1[j] != word2[j])
            {
                flag = false;
                if (dic[word1[j]] > dic[word2[j]])
                {
                    return false;
                }
                else
                {
                    break;
                }
            }
        }
        if(flag == true && word1.length()>word2.length()){
            return false;
        }
    }
    return true;
}

int main()
{
    vector<string> words = {"word", "world", "row"};
    string order = "worldabcefghijkmnpqstuvxyz";
    isAlienSorted(words, order);
    return 0;
}