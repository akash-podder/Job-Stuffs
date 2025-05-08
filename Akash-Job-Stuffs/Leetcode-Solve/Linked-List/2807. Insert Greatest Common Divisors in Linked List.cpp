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

// JAVA Solution
class Solution {
    public int calculateGCD(int num1, int num2){
        // "x" is always Bigger Number & "y" is always Smaller Number
        int x = Math.max(num1, num2);
        int y = Math.min(num1, num2);

        while(x%y!=0){
            int remaineder = x%y;
            x = y;
            y = remaineder;
        }

        // GCD is the smaller value when the loop ends
        return y;
    }

    public ListNode insertGreatestCommonDivisors(ListNode head) {
        ListNode current = head;

        while(current!=null){
            if(current.next!=null){
                ListNode nextNode = current.next;

                ListNode newNODE = new ListNode(calculateGCD(current.val, nextNode.val));
                
                newNODE.next = nextNode;
                current.next = newNODE;

                // this is for Traversing to the Next Node byPassing the "New" Created Node
                current = nextNode;
            }
            else{
                current = current.next;
            }
        }


        return head;
    }
}