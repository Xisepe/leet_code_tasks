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
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length < 1)
            return null;
        if (lists.length == 1)
            return lists[0];
        ListNode head = null;
        ListNode result = null;
        ListNode left = mergeKLists(Arrays.copyOfRange(lists,0, lists.length/2));
        ListNode right = mergeKLists(Arrays.copyOfRange(lists,lists.length/2, lists.length));

        while (left != null || right != null) {
            if (result == null) {
                result = new ListNode();
                head = result;
            } else {
                result.next = new ListNode();
                result = result.next;
            }
            int l = Integer.MAX_VALUE;
            int r = Integer.MAX_VALUE;
            if (left != null) {
                l = left.val;
            }
            if (right != null) {
                r = right.val;
            }
            if (l < r) {
                result.val = l;
                left = left.next;
            } else {
                result.val = r;
                right = right.next;
            }
            result.next = null;
        }
        return head;
    }
}
