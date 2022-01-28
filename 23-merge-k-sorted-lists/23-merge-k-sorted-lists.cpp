/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);
        ListNode* point = head;
        auto comp = [](pair<int,ListNode*>& a,pair<int,ListNode*>& b){
            return a.first > b.first;
        };
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,decltype(comp)> pq(comp);
        for(int i=0;i<lists.size();i++){
            if(lists[i] != NULL){
                pq.push({lists[i]->val,lists[i]->next});
            }
        }
        while(!pq.empty()){
            pair<int,ListNode*> cur = pq.top();
            pq.pop();
            point->next = new ListNode(cur.first);
            point = point->next;
            ListNode* node = cur.second;
            if(node != NULL){
                pq.push({node->val,node->next});
            }
        }
        
        return head->next;
    }
};