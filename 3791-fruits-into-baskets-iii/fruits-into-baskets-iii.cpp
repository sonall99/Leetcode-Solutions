class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        int size = 1;
        while (size < n) size <<= 1;

        vector<int> tree(size * 2);
        for (int i = 0; i < n; ++i) {
            tree[size + i] = baskets[i];
        }
        for (int i = size - 1; i > 0; --i) {
            tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
        }

        int unplaced = 0;
        for (int fruit : fruits) {
            int node = 1;
            if (tree[node] < fruit) {
                ++unplaced;
                continue;
            }
            while (node < size) {
                if (tree[node << 1] >= fruit) {
                    node <<= 1;
                } else {
                    node = node << 1 | 1;
                }
            }
            tree[node] = -1;
            while (node > 1) {
                node >>= 1;
                tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
            }
        }
        return unplaced;
    }
};