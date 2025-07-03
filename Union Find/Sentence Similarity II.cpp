//Sentence Similarity II
//Compiler - C++
//https://leetcode.com/problems/sentence-similarity-ii/?envType=problem-list-v2&envId=union-find

class Solution {
public:
    string findParent(string x, map<string, string>&parent) {
        if(x == parent[x]) return x;
        return parent[x] = findParent(parent[x], parent);
    }
    void unionn(string x, string y, map<string, string>&parent) {
        string x_parent = findParent(x, parent);
        string y_parent = findParent(y, parent);
        if(x_parent != y_parent) {
            parent[y_parent] = x_parent;
        }
    }
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if(sentence1.size() != sentence2.size()) return false;
        map<string, string>parent;
        for(auto it : sentence1) {
            parent[it] = it;
        }
        for(auto it : sentence2) {
            parent[it] = it;
        }
        for(auto it : similarPairs) {
            parent[it[0]] = it[0];
            parent[it[1]] = it[1];
        }
        for(int i=0; i<similarPairs.size(); i++) {
            vector<string>temp = similarPairs[i];
            unionn(temp[0], temp[1], parent);
        }

        for(int i = 0; i < sentence1.size(); i++) {
            string parent_one = findParent(sentence1[i], parent);
            string parent_two = findParent(sentence2[i], parent);
            if(parent_one != parent_two) return false;
        }
        return true;
    }
};