class Solution {
public:

    string encode(vector<string>& strs) {
        //use an array to store all the strings together
        //for every string in strs, get the size, then
        string result;
        for (const auto& each : strs) {
            result.append(to_string(each.size()));
            result.push_back('*'); //append wants a sequence not a char so use push_back here
            result.append(each);
        }
        return result;
    }

    vector<string> decode(string s) {
        //decode would add or do whatever in between at size of string + 1
        // array = {'ilovenewyork'}
        // find way to seperate them 
        // use space or a character

        vector<string> result;
        int i = 0;
        while (i < s.size()){
            int j = i;
            while (s[j] != '*'){
                j++;
            }
            int length = stoi(s.substr(i, j - i)); //substr takes start and how many        so it has to be start at i and j - i
            i = j + 1;
            j = i + length; //
            string res = s.substr(i, length);
            result.push_back(res);
            i = j;
        }

        return result;
    }
};
