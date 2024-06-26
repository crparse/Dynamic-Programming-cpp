class Solution {
public:
    bool isPalindrome(string S){
        string P = S;
        reverse(P.begin(), P.end());
        if(S == P) return true;
        else return false;
    }
    void SolvePalindrome(vector<vector<string>>& ans, vector<string>&temp, string s){
        if(s.size()==0){
            ans.push_back(temp);
            return;
        }
        for(int j=0; j<s.size(); j++){
            string str= s.substr(0, j+1);
            if(isPalindrome(str)){
                temp.push_back(str);
                SolvePalindrome(ans, temp, s.substr(j+1));
                temp.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        SolvePalindrome(ans, temp , s);
        return ans;
    }
};