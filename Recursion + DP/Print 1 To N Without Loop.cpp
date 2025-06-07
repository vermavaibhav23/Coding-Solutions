//Print 1 To N Without Loop
//Compiler - C++
//https://www.geeksforgeeks.org/problems/print-1-to-n-without-using-loops-1587115620/1

class Solution {
  public:
    void printNos(int n) {
        if(n == 1){
            cout<<"1"<<" ";
            return;
        }
        printNos(n-1);
        cout<<n<<" ";
    }
};