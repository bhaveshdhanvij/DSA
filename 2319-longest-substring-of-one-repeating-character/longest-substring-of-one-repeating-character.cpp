class Solution {
    struct Node {
        int len = 0;
        int pref = 0;
        int suff = 0;
        int best = 0;
        char lc = 0, rc = 0;
    };

    vector<Node> seg;
    string s;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;
        res.len = a.len + b.len;
        res.lc = a.lc;
        res.rc = b.rc;

        res.pref = a.pref;
        if (a.pref == a.len && a.rc == b.lc)
            res.pref = a.len + b.pref;

        res.suff = b.suff;
        if (b.suff == b.len && a.rc == b.lc)
            res.suff = b.len + a.suff;

        res.best = max(a.best, b.best);

        if (a.rc == b.lc)
            res.best = max(res.best, a.suff + b.pref);

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            seg[node] = {1, 1, 1, 1, s[l], s[l]};
            return;
        }

        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx) {
        if (l == r) {
            seg[node] = {1, 1, 1, 1, s[l], s[l]};
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx);
        else
            update(node * 2 + 1, mid + 1, r, idx);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

public:
    vector<int> longestRepeating(string queryString,
                                 string queryCharacters,
                                 vector<int>& queryIndices) {
        s = queryString;
        int n = s.size();

        seg.resize(4 * n);
        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int idx = queryIndices[i];

            s[idx] = queryCharacters[i];

            update(1, 0, n - 1, idx);

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};