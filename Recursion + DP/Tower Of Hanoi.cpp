//Tower Of Hanoi
//Compiler - C++
//https://www.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1

class Solution {
  public:
    // You need to complete this function
    long long count = 0;
    void toh(int n, int from, int to, int aux) {
        if(n>0) {
            toh(n-1, from, aux, to);
            //cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
            count++;
            toh(n-1, aux, to, from);
        }
    }
    int towerOfHanoi(int n, int from, int to, int aux) {
        count = 0;
        toh(n,from,to,aux);
        return count;
    }
};