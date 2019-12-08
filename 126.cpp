https://leetcode.com/problems/word-ladder-ii/
class Solution {
public:
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		unordered_map<string, vector<string>> access;
		queue<string> que;
		que.push(beginWord);

		unordered_set<string> lookup(wordList.begin(), wordList.end());
		if (!lookup.count(endWord)) return {};


		bool isEnd = false;

		while (!que.empty()) {

			unordered_set<string> words;
			for (int i = que.size(); i > 0; --i) {
				string word = que.front();
				que.pop();
				words.insert(word);
				lookup.erase(word);

				if (word == endWord) isEnd = true;
			}
			if (isEnd) break;
			for (auto word:words) {
				for (int j = 0; j < word.size(); ++j) {
					string newWord(word);
					for (char ch = 'a'; ch < 'z'; ++ch) {
						newWord[j] = ch;
						if (lookup.count(newWord) && newWord != word) {
							que.push(newWord);
							access[word].push_back(newWord);
						}
					}
				}
			}
		}

		vector<vector<string>> ans;
		vector<string> path;
		dfs(ans, access, path, beginWord, endWord);

		return ans;
	}

	void dfs(vector<vector<string>> &ans, unordered_map<string, vector<string>> &access, vector<string> path, string word, string &endWord) {
		path.push_back(word);

		if (word == endWord) {
			ans.push_back(path);
			return ;
		}

		vector<string> words = access[word];
		for (int i = 0; i < words.size(); ++i) {
			string newWord(words[i]);
			dfs(ans, access, path, newWord, endWord);
		}
	}
};
