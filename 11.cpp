/* Sceret Cipher

Geek wants to send an encrypted message in the form of string S to his friend Keeg along with instructions on how to decipher the message. To decipher the message, his friend needs to iterate over the message string from left to right, if he finds a '*', he must remove it and add all the letters read so far to the string. He must keep on doing this till he gets rid of all the '*'.
Can you help Geek encrypt his message string S? 

Note: If the string can be encrypted in multiple ways, find the smallest encrypted string. 

Example 1:

Input: S = "ababcababcd"
Output: ab*c*d
Explanation: We can encrypt the string 
in following way : "ababcababcd" -> 
"ababc*d" -> "ab*c*d"
Example 2:

Input: S = "zzzzzzz"
Output: z*z*z
Explanation: The string can be encrypted 
in 2 ways: "z*z*z" and "z**zzz". Out of 
the two "z*z*z" is smaller in length.
Your Task: 
You don't need to read input or print anything. Complete the function secretCipher() which takes the message string S as input parameter and returns the shortest possible encrypted string.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints: 1 ≤ |S| ≤ 105 

*/

string compress(string s)
    {
        // Your code goes here
        int n = s.size();
        vector<int> v(n);
        for(int i = 1; i<n;i++){
            int j = v[i-1];
            while(j>0 && s[i]!=s[j]){
                j = v[j-1];
                
            }
            if(s[i]==s[j]) j++;
            v[i] = j;
        }
        
        string ans;
        for(int i=n-1;i>=0;i--){
            if(i%2){
                if(v[i]>=(i+1)/2 && (i+1)%(2 * (i+1-v[i])) == 0){
                    ans.push_back('*');
                    i/=2;i++;
                }
                else {ans.push_back(s[i]);}
                
            }
            else {ans.push_back(s[i]);}
        }
        reverse(ans.begin(), ans.end());
       
        return ans;
    }
