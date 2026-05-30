struct SuffixAutomaton
{
    int tot, tail;
    struct Node {
        Node() {
            fa = len = 0;
            trans.clear();
        }
        unordered_map<int, int> trans;
        int fa, len;
    };
    vector<bool> leaf;
    vector<Node> a;

    SuffixAutomaton(int n) {
        leaf.resize(n << 1, true);
        a.resize(n << 1);
        tot = tail = 0;
    }

    void ins(int c) {
        int p, np, q, nq;
        a[np = ++tot].len = a[tail].len + 1;
        for (p = tail; p && !a[p].trans[c]; p = a[p].fa)
            a[p].trans[c] = np;
        if (!a[p].trans[c]) a[p].trans[c] = np;
        else {
            q = a[p].trans[c];
            if (a[q].len == a[p].len + 1) a[np].fa = q;
            else {
                a[nq = ++tot] = a[q];
                a[q].fa = a[np].fa = nq;
                a[nq].len = a[p].len + 1;
                while (a[p].trans[c] == q)
                    a[p].trans[c] = nq, p = a[p].fa;
            }
        }
        tail = np;
    }
    
    int solve() {
        int ans = tot;
        for (int i = 1; i <= tot; i++) leaf[a[i].fa] = false;
        for (int i = 1; i <= tot; i++) {
            if (leaf[i]) ans = min(ans, a[a[i].fa].len + 1);
        }
        return ans;
    }
};

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        SuffixAutomaton sam(n);
        for (int i = 0; i < n; i++) {
            sam.ins(nums[i]);
        }
        return sam.solve();
    }
};