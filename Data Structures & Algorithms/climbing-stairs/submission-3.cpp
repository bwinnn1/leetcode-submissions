class Solution {
public:
    // class member so it can be passed into dfs
    vector<int> cache;
    int climbStairs(int n) {
        // dynamic programming using dfs as a function to recursive compute and store numbers

        // resize the vector based on the destination number n
        // initialize all of them with -1
        cache.resize(n, -1);

        // call recursion
        return dfs(n, 0);
    }

    int dfs(int n, int i) {
        // recusively adding step once i == n
        if (i == n) {
            // found a way
            return 1;
        } else if (i > n) {
            // overshot the destination
            return 0;
        }
        if (cache[i] != -1) return cache[i];
        
        // find the total path to destination starting from step i
        int result = dfs(n, i + 1) + dfs(n, i + 2);

        cache[i] = result;

        return result;
    }
};
