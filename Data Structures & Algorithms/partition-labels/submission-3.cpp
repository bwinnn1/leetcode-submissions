class Solution {
public:
    vector<int> partitionLabels(string s) {
        //hashmap
        //two pointers to find the first and last time that character appears
        //{x : 3, y : 4, z : 7, b : 9, i : 10, s : 11, l : 12}
        //
        // a starts at 0 but ends at 3
        // b starts at 1 but end at 4
        // c starts at 3 but end at 5 

        //hashmap to store last index
        unordered_map<char, int> lastIndex;
        for (int i = 0; i < s.length(); i++) {
            lastIndex[s[i]] = i; //continuously update the location of each character
            //{abcabc} -> {a:3, b:4, c:5}
        }

        vector<int> result;
        int size = 0; //too compute the size of the subarray
        int maxEnd = 0;
        for (int i = 0; i < s.length(); i++){
            size++;
            maxEnd = max(maxEnd, lastIndex[s[i]]); //end between the current and the end of the character
            if (i == maxEnd){
                result.push_back(size); //add the size of the subarray that has the last index of a character possible
                size = 0; //set the size = 0 to create a new subarray
            }
        }
        return result;
    }
};
