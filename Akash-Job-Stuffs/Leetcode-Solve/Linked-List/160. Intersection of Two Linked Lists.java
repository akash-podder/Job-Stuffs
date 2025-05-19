/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        Set<ListNode> mySet = new HashSet();

        // iterating List "A"
        ListNode current = headA;
        while(current!=null){
            mySet.add(current);
            current = current.next;
        }

        // iterating List "B"
        current = headB;
        while(current!=null){
            // Intersection Point Found
            if(mySet.contains(current)){
                return current;
            }
            current = current.next;
        }

        // No Intersection
        return null;
    }
}