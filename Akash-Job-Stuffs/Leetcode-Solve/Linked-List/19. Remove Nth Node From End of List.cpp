//JAVA Solution
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // We use Two pointers. And the Gap between Slow & Fast Pointer will be = "n"
        // fast - slow = n
        // Now, when "Fast" pointer Moves to End, So, our "Slow" Pointer will be on the "n'th" LAST Node
        // Now, to Remove we have to be on (n-1)th Node from last... As such we have to put the Gap between "fast-slow = n+1", so we put "Slow" Pointer to a Dummy Node

        ListNode dummy = new ListNode(0, head);

        ListNode slow = dummy;
        ListNode fast = head;
        
        for(int i=0; i<n; i++) {
            fast = fast.next;
        }

        while(fast!=null){
            fast = fast.next;
            slow = slow.next;
        }

        if(slow.next!=null){
            // Skipping the "n" Element
            slow.next = slow.next.next;
        }
        else{
            slow.next = null;
        }

        return dummy.next;
    }
}