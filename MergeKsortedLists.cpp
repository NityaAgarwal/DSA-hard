//https://leetcode.com/problems/merge-k-sorted-lists/

//I SOLVED THIS MYSELF - but this solution doesnt perform well time wise
class Solution {
public:
    ListNode* mergeTwoSortedLists(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2) return NULL;
        if (!list1) return list2;
        if (!list2) return list1;

        if (list1 -> val < list2 -> val) {
            list1->next = mergeTwoSortedLists(list1->next, list2);
            return list1;
        }
        list2 -> next = mergeTwoSortedLists(list1, list2->next);
        return list2;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return NULL;
        if (n == 1) return lists[0];
        //if i have 2 lists - then i have to sort 1 time
        //if i have 3 lists - then i have to sort 2 times
        //so n lists - total n-1 times of sorting required
        ListNode* new_list = mergeTwoSortedLists(lists[0], lists[1]);
        for (int i = 1; i<n-1; i++) {
            new_list = mergeTwoSortedLists(new_list, lists[i+1]);
        }
        return new_list;
        /*
        Eg for reference - 
        1, 2, 3, 4 - these are the lists
        nl = 1,2 - outside of loop
        nl = 1,2,3 - inside loop (here i = 1)
        nl = 1,2,3,4 - inside loop (here i = 2)
        */
    }
};
