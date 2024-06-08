class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> roots(dictionary.begin(), dictionary.end());
        stringstream ss;
        ss<<sentence;//powerful stringstream https://blog.csdn.net/aipiannian6725/article/details/101157697?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7EPaidSort-1-101157697-blog-79922660.235%5Ev43%5Epc_blog_bottom_relevance_base3&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7EPaidSort-1-101157697-blog-79922660.235%5Ev43%5Epc_blog_bottom_relevance_base3&utm_relevant_index=1
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