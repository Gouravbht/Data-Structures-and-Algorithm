#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  int pairSum(ListNode* head) {
    int ans = 0, len = 0;
    std::vector<int> vals;

    // Traverse the linked list and store elements in a vector
    while (head) {
      len++;
      vals.push_back(head->val);
      head = head->next;
    }

    // Find the maximum pair sum by comparing elements from both halves
    for (int i = 0; i < len / 2; ++i) {
      ans = std::max(ans, vals[i] + vals[len - i - 1]);
    }

    return ans;
  }
};
