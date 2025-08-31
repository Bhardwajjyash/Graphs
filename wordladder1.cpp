#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        queue < pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (word == endWord)
                return steps;
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    if (st.find(word) != st.end()) {
                        st.erase(word);// mark visited
                        q.push({word, steps + 1});
                    }
                }
                //so that otiginal word is restored You’ll now be changing the second char of "zit" instead of "hit".
                word[i] = original;
            }
        }
        return 0;
    }
};