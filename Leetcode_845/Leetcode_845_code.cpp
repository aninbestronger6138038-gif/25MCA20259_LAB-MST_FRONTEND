class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;
        
        vector<int> left(n, 1);  //   ending at i
        vector<int> right(n, 1); //  starting at i
        
        // working on left side array part
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i-1]) {
                left[i] = left[i-1] + 1;
            }
        }
        
        int ans = 0;
        
        // working on right side array part
        for (int i = n-2; i >= 0; i--) {
            if (arr[i] > arr[i+1]) {
                right[i] = right[i+1] + 1;
            }
            //final count 
            if (left[i] > 1 && right[i] > 1) {
                ans = max(ans, left[i] + right[i] - 1);
            }
        }
        
        return ans;
    }
};
