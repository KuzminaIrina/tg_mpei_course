https://leetcode.com/problems/top-k-frequent-elements/
class Solution {
public:
   vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int, int> intMap;
	for (int num : nums) {
		auto it = intMap.find(num);
		if (it == intMap.end()) intMap[num] = 1;
		else it -> second ++;
	}

	vector<pair<int, int>> frequencies(intMap.begin(), intMap.end());
	sort(frequencies.begin(), frequencies.end(), [](pair<int, int>& p1, pair<int, int>& p2) {return p1.second > p2.second;});

	vector<int> resu;
	for (int i = 0; i < k && i < frequencies.size(); i++)
		resu.push_back(frequencies[i].first);

	return resu;
}

};
