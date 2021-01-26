// Ques: https://practice.geeksforgeeks.org/problems/47e5aa3f32aee9e0405f04960f37c8a562d96a2f/1/?track=30-DOC-day-1&batchId=320
// Refer: https://www.geeksforgeeks.org/rearrange-given-array-place/

class Solution {
  public:
    void prank(long long a[], int n){
        // code here
        
        for (int i=0; i < n; i++)
        a[i] += (a[a[i]]%n)*n;
 
    // Second Step: Divide all values by n
    for (int i=0; i<n; i++)
        a[i] /= n;
        
    }
};
