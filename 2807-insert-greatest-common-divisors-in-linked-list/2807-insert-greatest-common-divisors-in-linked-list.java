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

    int gcd(int a , int b){
        int mini = Math.min(a,b);
        int ans = 0;
        for(int i = mini; i>=1; i--){
            if(a%i == 0 && b%i == 0){
                return i;
            }
        }
        return ans;
    }
    public ListNode insertGreatestCommonDivisors(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        ListNode prev = null;
        ListNode curr = head;

        while(curr != null){
            prev = curr;
            curr = curr.next;
            if(curr == null){
                break;
            }
            int num = gcd(prev.val, curr.val);
            ListNode node = new ListNode(num);
            prev.next = node;
            node.next = curr;
            prev = node;
        }
        return head;
    }
}