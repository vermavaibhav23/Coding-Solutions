//838. Push Dominoes
//Compiler - C++
//https://leetcode.com/problems/push-dominoes/

class Solution {
public:
    string pushDominoes(string dominoes) {
        int left = -1;
        int right = 0;
        while(right < dominoes.size() && dominoes[right] == '.') {
            right++;
        }
        
        while(right < dominoes.size()) {
            while(right < dominoes.size() && dominoes[right] == '.') right++;
            if(right >= dominoes.size()) break;
            if(left == -1) {
                if(dominoes[right] == 'L') for(int i = 0; i < right; i++) dominoes[i] = 'L';
            }
            else if(dominoes[left] == 'R' && dominoes[right] == 'R') {
                for(int i = left + 1; i < right; i++) {
                    dominoes[i] = 'R';
                }
            }
            else if(dominoes[left] == 'L' && dominoes[right] == 'L') {
                for(int i = left + 1; i < right; i++) {
                    dominoes[i] = 'L';
                }
            }
            else if(dominoes[left] == 'R' && dominoes[right] == 'L') {
                int temp_l = left + 1;
                int temp_r = right - 1;
                while(temp_l < temp_r) {
                    dominoes[temp_l] = 'R';
                    dominoes[temp_r] = 'L';
                    temp_l++;
                    temp_r--;
                }
            }
            left = right;
            right++;
        }

        if(left != -1 && dominoes[left] == 'R') {
            for(int i = left + 1; i < dominoes.size(); i++) {
                dominoes[i] = dominoes[left];
            }
        }
        return dominoes;
    }
};