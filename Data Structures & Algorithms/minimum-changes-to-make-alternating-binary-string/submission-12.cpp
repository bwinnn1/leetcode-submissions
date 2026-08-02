class Solution {
   public:
    int minOperations(string s) {
        int counter = 0;  // counter to check how many operations
        for (int i = 0; i < s.length(); i++) {
            if (i % 2 == 0) { //this is for pattern with 1, if the first index and is 0, then increase by 1
                if (s[i] == '0') { 
                    counter++;
                }
            } else { //if odd, and is 1 then increase by 1. 1010101
                if (s[i] == '1'){
                    counter++;
                }
            }
        }

        //the mismatch for patter start with 0 is because 
        //match.A + mismatch.A = length
        //matches_with_A = mismatches_with_B
        //substinute 1 into 2:
        //mismatches_with_B + mismatches_A = length
        //mismatch_with_B = length - mismatches_with_A
        //mismatch_with_B = length - counter
        return min(counter, (int)s.size() - counter);
    }        
};