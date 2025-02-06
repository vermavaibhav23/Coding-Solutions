//https://www.interviewbit.com/problems/capacity-to-ship-packages-within-b-days/
//compiler : C++
//Capacity To Ship Packages Within B Days
int Solution::solve(vector<int> &A, int B) {
        int total_weight = 0; 
        int highest_weight = 0; 
        int i=0;
        for (int a=0; a< A.size(); a++) {
            total_weight = total_weight + A[a];
            if (A[a] >= highest_weight) {
                highest_weight = A[a];
            }
        }
    
        int start = highest_weight; 
        int end = total_weight;     
        int mid, ans = 0; 

        while (start <= end) {
            mid = (start + end) / 2;
            //cout << "mid = " << mid << endl;

            int sum = 0, days = 1;
            for (int i = 0; i < A.size(); i++) {
                if (sum + A[i] > mid) {
                    days++;
                    sum = 0;
                }
                sum = sum + A[i];
            }

            if (days > B) {
                start = mid + 1;
            } else {
                ans = mid;
                end = mid - 1;
            }
        }

        return ans;
}
