class Solution {
public:
    struct Pair {
        int idx;
        long long val, sum;
        Pair *left, *right;
        Pair(int i, long long v) : idx(i), val(v), sum(0), left(nullptr), right(nullptr) {}
    };

    struct Cmp {
        bool operator()(Pair* a, Pair* b) const {
            if (a->right == nullptr || b->right == nullptr)
                return a->right != nullptr;
            if (a->sum != b->sum) return a->sum < b->sum;
            return a->idx < b->idx;
        }
    };

    int minimumPairRemoval(vector<int>& nums) {
        set<Pair*, Cmp> st;
        int mismatches = 0;

        Pair* prev = nullptr;
        vector<Pair*> nodes;

        for (int i = 0; i < nums.size(); i++) {
            Pair* curr = new Pair(i, nums[i]);
            nodes.push_back(curr);
            if (prev) {
                if (curr->val < prev->val) mismatches++;
                prev->right = curr;
                curr->left = prev;
                prev->sum = prev->val + curr->val;
                st.insert(prev);
            }
            prev = curr;
        }
        st.insert(prev);

        int cnt = 0;

        while (mismatches > 0) {
            Pair* best = *st.begin();
            st.erase(st.begin());

            if (best->right->val < best->val) mismatches--;

            best->val += best->right->val;
            best->sum = best->val + (best->right->right ? best->right->right->val : 0);

            Pair* del = best->right;
            best->right = del->right;

            if (del->right) {
                if (del->right->val < del->val) mismatches--;
                del->right->left = best;
                if (best->val > del->right->val) mismatches++;
            }

            Pair* left = best->left;
            if (left) {
                st.erase(left);
                if (left->val > left->sum - left->val) mismatches--;
                if (left->val > best->val) mismatches++;
                left->sum = left->val + best->val;
                left->right = best;
                st.insert(left);
            }

            st.insert(best);
            cnt++;
        }
        return cnt;
    }
};