/* Count Triplets

Given a sorted linked list of distinct nodes (no two nodes have the same data) and an integer X. Count distinct triplets in the list that sum up to given integer X.

Example 1:

Input: LinkedList: 1->2->4->5->6->8->9, X = 17
Output: 2
Explanation: Distinct triplets are (2, 6, 9) 
and (4, 5, 8) which have sum equal to X i.e 17.


Example 2:

Input: LinkedList: 1->2->4->5->6->8->9, X = 15
Output: 5
Explanation: (1, 5, 9), (1, 6, 8), (2, 4, 9), 
(2, 5, 8), (4, 5, 6) are the distinct triplets
Your Task:  
You don't need to read input or print anything. Complete the function countTriplets() which takes a head reference and X as input parameters and returns the triplet count

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ Number of Nodes ≤ 103 
1 ≤ Node value ≤ 104


Refrence Solution: https://www.geeksforgeeks.org/count-triplets-sorted-doubly-linked-list-whose-sum-equal-given-value-x/ 
*/

int countTriplets(struct Node* head, int x) 
{ 
    // code here.
    struct Node* ptr, *ptr1, *ptr2;
    int count = 0;
 
    // unordered_map 'um' implemented as hash table
    unordered_map<int, Node*> um;
 
    // insert the <node data, node pointer> tuple in 'um'
    for (ptr = head; ptr != NULL; ptr = ptr->next)
        um[ptr->data] = ptr;
 
    // generate all possible pairs
    for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next)
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next) {
 
            // p_sum - sum of elements in the current pair
            int p_sum = ptr1->data + ptr2->data;
            // if 'x-p_sum' is present in 'um' and either of the two nodes
            // are not equal to the 'um[x-p_sum]' node
            if (um.find(x - p_sum) != um.end() && um[x - p_sum] != ptr1
                && um[x - p_sum] != ptr2)
 
                // increment count
                count++;
        }
 
    // required count of triplets
    // division by 3 as each triplet is counted 3 times
    return (count / 3);
} 
