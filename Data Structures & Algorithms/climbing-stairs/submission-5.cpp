class Solution {
public:
    // make a cache or dp to store all of the already computed steps
    vector<int> cache;
    int climbStairs(int n) {
        // intilize the cache with all -1
        cache.resize(n, -1);
        
        // call recursion to explore all of the path 
        return dfs(n, 0);
    }

    int dfs(int n, int i) {
        if (i == n) {
            // found a way to get there
            return 1;
        } else if (i >n) {
            // overshot the path
            return 0;
        }

        // check if the number at i has already been computed
        if (cache[i] != -1) return cache[i];

        int result = dfs(n, i + 1) + dfs(n, i + 2);

        // store the result into cache
        cache[i] = result;

        return result;
    }
};
