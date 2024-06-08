class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> roots(dictionary.begin(), dictionary.end());
        stringstream ss;
        ss<<sentence;//powerful stringstream
        string word, result;
        while (ss >> word) {
            string root;
            for (int i = 1; i <= word.size(); ++i) {
                string sub = word.substr(0, i);
                if (roots.count(sub)) {
                    root = sub;
                    break;
                }
            }
            result += (root.empty() ? word : root) + " ";
        }
        result.pop_back();  // remove the trailing space
        return result;
    }
};