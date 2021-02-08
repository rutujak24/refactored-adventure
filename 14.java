/* Ruling Pair

Geek Land has a population of N people and each person's ability to rule the town is measured by a numeric value arr[i]. The two people that can together rule Geek Land must be compatible with each other i.e., the sum of digits of their ability arr[i] must be equal. Their combined ability should be maximum amongst all the possible pairs of people. Find the combined ability of the Ruling Pair.

Example 1:

Input:
N = 5
arr[] = {55, 23, 32, 46, 88}
Output:
101
Explanation:
All possible pairs that are 
compatible with each other are- (23, 32) 
with digit sum 5 and (55, 46) with digit 
sum 10. Out of these the maximum combined 
ability pair is (55, 46) i.e. 55 + 46 = 101
Example 2:

Input:
N = 4
arr[] = {18, 19, 23, 15}
Output:
-1
Explanation:
No two people are compatible with each other. 
Your Task:  
You don't need to read input or print anything. Complete the function RulingPairâ€‹() which takes the array arr[] and size of array N as input parameters and returns the answer. If No two people are compatible with
each other then return -1.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 105 
1 ≤ arr[i] ≤ 109

*/

class Solution { 
	static int RulingPair(int arr[], int no) { 
        HashMap<integer,integer> h=new HashMap<>();
        int sum=-1;
        for(int n : arr)
        {
            int dig=0;
            int num=n;
            while(n!=0)
            {
                dig+=(n%10);
                n=n/10;
            }
            if(h.containsKey(dig))
            {
                int curr=h.get(dig);
                sum=Math.max(sum,curr+num);
                if(num>curr)
                  h.put(dig,num);
            }
            else
                h.put(dig,num);
        }
        return sum;
	}    
} 
