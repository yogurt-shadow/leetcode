package other;
public class Solution2 {
    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int[] sum1 = new int[100];
        int[] sum2 = new int[100];
        int i1 = 0;
        int i2 = 0;
        ListNode l1_copy = l1;
        ListNode l2_copy = l2;
        while(l1 != null){
            sum1[i1] = l1.val;
            i1 += 1;
            l1 = l1.next;
        }
        while(l2 != null){
            sum2[i2] = l2.val;
            i2 += 1;
            l2 = l2.next;
        }
        int over = 0;
        i1 -= 1;
        i2 -= 1;
        int j1 = 0;
        int j2 = 0;
        int sum = sum1[j1] + sum2[j2];
        ListNode result = new ListNode(sum % 10);
        ListNode copy = result;
        if(sum >= 10){
            over = 1;
        }
        j1 += 1;
        j2 += 1;
        while(j1 <= i1 || j2 <= i2){
            if(j1 > i1){
                copy.next = new ListNode((sum2[j2] + over) % 10);
                copy = copy.next;
                if(sum2[j2] + over >= 10){over = 1;}
                else{over = 0;}
                j2 += 1;
                continue;
            }
            else if(j2 > i2){
                 copy.next = new ListNode((sum1[j1] + over) % 10);
                copy = copy.next;
                if(sum1[j1] + over >= 10){over = 1;}
                else{over = 0;}
                j1 += 1;
                continue;
            }
            else{
                copy.next = new ListNode((sum1[j1] + sum2[j2] + over) % 10);
                copy = copy.next;
                if(sum1[j1] + sum2[j2] + over >= 10){over = 1;}
                else{over = 0;}
                j1 += 1;
                j2 += 1;
            }
        }
        if(over == 1){
            copy.next = new ListNode(1);
        }
        return result;
    }

    public static void main(String[] args){
        ListNode x1 = new ListNode(9);
        ListNode x2 = new ListNode(9);
        for(int i = 0; i <= 8; i++){
            x2 = new ListNode(9, x2);
        }
        x2 = new ListNode(1, x2);
        ListNode result = Solution2.addTwoNumbers(x1, x2);
        while(result != null){
            System.out.println(result.val);
            result = result.next;
        }
    }
}