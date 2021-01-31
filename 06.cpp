/* Coins of Geekland

In Geekland there is a grid of coins of size N x N. You have to find the maximum sum of coins in any sub-grid of size K x K.
Note: Coins of the negative denomination are also possible at Geekland.

Example 1:

Input: N = 5, K = 3 
mat[[]] = {1, 1, 1, 1, 1} 
          {2, 2, 2, 2, 2} 
          {3, 8, 6, 7, 3} 
          {4, 4, 4, 4, 4} 
          {5, 5, 5, 5, 5}
Output: 48
Explanation: {8, 6, 7}
             {4, 4, 4}
             {5, 5, 5}
has the maximum sum

Example 2:

Input: N = 1, K = 1
mat[[]] = {{4}} 
Output: 4
Your Task:  
You don't need to read input or print anything. Complete the function Maximum_Sum() which takes the matrix mat[], size of Matrix N, and value K as input parameters and returns the maximum sum.

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N2)

Constraints:
1 ≤ K ≤ N ≤ 103
-5*105 ≤ mat[i][j] ≤ 5*105

*/

class Solution{
    
    public:
    int Maximum_Sum(vector<vector<int>> &mat,int N,int k){
        // Your code goes here
        //if (k > N) return; 
  
    // 1: PREPROCESSING 
    // To store sums of all strips of size k x 1 
    int stripSum[N][N]; 
  
    // Go column by column 
    for (int j=0; j<N; j++) 
    { 
        // Calculate sum of first k x 1 rectangle 
        // in this column 
        int sum = 0; 
        for (int i=0; i<k; i++) 
            sum += mat[i][j]; 
        stripSum[0][j] = sum; 
  
        // Calculate sum of remaining rectangles 
        for (int i=1; i<N-k+1; i++) 
        { 
            sum += (mat[i+k-1][j] - mat[i-1][j]); 
            stripSum[i][j] = sum; 
        } 
    } 
  
    // max_sum stores maximum sum and its 
    // position in matrix 
    int max_sum = INT_MIN, *pos = NULL; 
  
    // 2: CALCULATE SUM of Sub-Squares using stripSum[][] 
    for (int i=0; i<N-k+1; i++) 
    { 
        // Calculate and print sum of first subsquare 
        // in this row 
        int sum = 0; 
        for (int j = 0; j<k; j++) 
            sum += stripSum[i][j]; 
  
        // Update max_sum and position of result 
        if (sum > max_sum) 
        { 
            max_sum = sum; 
            pos = &(mat[i][0]); 
        } 
  
        // Calculate sum of remaining squares in 
        // current row by removing the leftmost 
        // strip of previous sub-square and adding 
        // a new strip 
        for (int j=1; j<N-k+1; j++) 
        { 
            sum += (stripSum[i][j+k-1] - stripSum[i][j-1]); 
  
            // Update max_sum and position of result 
            if (sum > max_sum) 
            { 
                max_sum = sum; 
                pos = &(mat[i][j]); 
            } 
        } 
    } 
    
    
    return max_sum;
    }  
};
