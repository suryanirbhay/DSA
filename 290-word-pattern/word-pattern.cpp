class Solution {
public:
    bool wordPattern(string pattern, string s) {
          vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }

       
        if (words.size() != pattern.size()) return false;

       
        unordered_map<char, string> mapCharToWord;
        unordered_map<string, char> mapWordToChar;

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];

            if (mapCharToWord.count(c)) {
                if (mapCharToWord[c] != w) return false;
            } else {
                mapCharToWord[c] = w;
            }

        
            if (mapWordToChar.count(w)) {
                if (mapWordToChar[w] != c) return false;
            } else {
                mapWordToChar[w] = c;
            }
        }

        return true;
    }
};