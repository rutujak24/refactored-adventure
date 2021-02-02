/* Transfiguration

Ref: https://www.geeksforgeeks.org/transform-one-string-to-another-using-minimum-number-of-given-operation/

Professor McGonagall teaches transfiguration at Hogwarts. She has given Harry the task of changing himself into a cat. She explains that the trick is to analyze your own DNA and change it into the DNA of a cat. The transfigure spell can be used to pick any one character from the DNA string, remove it and insert it in the beginning. 
Help Harry calculates minimum number of times he needs to use the spell to change himself into a cat.

Example 1:

Input: 
A = "GEEKSFORGEEKS" 
B = "FORGEEKSGEEKS"
Output: 3
Explanation:The conversion can take place 
in 3 operations:
1. Pick 'R' and place it at the front, 
   A="RGEEKSFOGEEKS"
2. Pick 'O' and place it at the front, 
   A="ORGEEKSFGEEKS"
3. Pick 'F' and place it at the front, 
   A="FORGEEKSGEEKS"
Example 2:

Input: 
A = "ABC" 
B = "BCA"
Output: 2
Explanation: The conversion can take place 
in 2 operations:
1. Pick 'C' and place it at the front, 
   A = "CAB"
2. Pick 'B' and place it at the front, 
   A = "BCA"
Your Task:  
You don't need to read input or print anything. Complete the function transfigure() which takes strings A and B as input parameters and returns the minimum number of spells needed. If it is not possible to convert A to B then return -1.

Expected Time Complexity: O(max(|A|, |B|))
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ |A|, |B| ≤ 105
A and B consists of lowercase and uppercase letters of english alphabet only. */

class Solution{
    
    public:
    int transfigure (string A, string B)
    {
        int m = A.length(), n = B.length(); 
  
     // This parts checks whether conversion is 
     // possible or not 
    if (n != m) 
       return -1; 
    int count[256]; 
    memset(count, 0, sizeof(count)); 
    for (int i=0; i<n; i++)   // count characters in A 
       count[B[i]]++; 
    for (int i=0; i<n; i++)   // subtract count for 
       count[A[i]]--;         // every character in B 
    for (int i=0; i<256; i++)   // Check if all counts become 0 
      if (count[i]) 
         return -1; 
    	int res = 0; 
    	int i, j;
        for (int i=n-1, j=n-1; i>=0; ) 
        { 
            // If there is a mismatch, then keep incrementing 
            // result 'res' until B[j] is not found in A[0..i] 
            while (i>=0 && A[i] != B[j]) 
            { 
                i--; 
                res++; 
            } 
      
            // If A[i] and B[j] match 
            if (i >= 0) 
            { 
                i--; 
                j--; 
            } 
        } 
        return res; 
        }
};
