Deduplication on a Linked List (25)

Given a singly linked list L with integer keys, 
you are supposed to remove the nodes with duplicated absolute values of the keys. 
That is, for each value K, 
only the first node of which the value or absolute value of its key equals K will be kept. 
At the mean time, all the removed nodes must be kept in a separate list. 
For example, given L being 21→-15→-15→-7→15, you must output 21→-15→-7, and the removed list -15→15.

Input Specification:
Each input file contains one test case. 
For each case, the first line contains the address of the first node, 
and a positive N (<= 105) which is the total number of nodes. 
The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.
Then N lines follow, each describes a node in the format:
Address Key Next
where Address is the position of the node, 
Key is an integer of which absolute value is no more than 104, 
and Next is the position of the next node.

Output Specification:
For each case, output the resulting linked list first, 
then the removed list. Each node occupies a line, 
and is printed in the same format as in the input.

Sample Input:
00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854
Sample Output:
00100 21 23854
23854 -15 99999
99999 -7 -1
00000 -15 87654
87654 15 -1