/*
Spiral Matrix

Given a matrix of size N x M. You have to find the Kth element which will obtain while traversing the matrix spirally starting from the top-left corner of the matrix.

Example 1:

Input: 
N = 3, M = 3, K = 4
A[] = {{1, 2, 3}, 
       {4, 5, 6}, 
       {7, 8, 9}}
Output: 
6
Explanation: Spiral traversal of matrix: 
{1, 2, 3, 6, 9, 8, 7, 4, 5}. Fourth element
is 6.
Example 2:

Input: 
N = 2, M = 2, K = 2 
A[] = {{1, 2},
       {3, 4}} 
Output: 
2
Explanation: Spiral traversal of matrix: 
{1, 2, 4, 3}. Second element is 2.
Your Task:  
You don't need to read input or print anything. Complete the function findK() which takes the matrix A[ ][ ], number of rows N, number of columns M, and integer K as input parameters and returns the Kth element in the spiral traversal of the matrix.

Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ K ≤ N*M ≤ 106
*/

class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        int i=0, j=0;
        vector <int> v;
    /* k - starting row index
        m - ending row index
        l - starting column index
        n - ending column index
        i - iterator
    */
 
    while (i<n && j<m ) {
        /* Print the first row from
               the remaining rows */
        for (int k = j; k < m; k++) {
            v.push_back(a[i][k]);
            
        }
        i++;
 
        
        for (int k = i; k < n; k++) {
            v.push_back(a[k][m-1]);
            
        }
        m--;
        
        //if(i<n){
        for (int k = m-1; k >= j; k--) {
            v.push_back(a[n-1][k]);
            
        }
        n--;
        //}
        
        //if(j<m){
        for (int k = n-1; k >= i; k--) {
            v.push_back(a[k][j]);
            
        }
        j++;
        
        //}
        
    }
     return v[k-1];
        
    }

};
