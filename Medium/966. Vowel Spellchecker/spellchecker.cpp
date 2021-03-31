class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> ans;
        unordered_set<string> st;
        unordered_map<string, string> m1;
        unordered_map<string, string> m2;
        for(int i = 0; i < wordlist.size(); i++){
            string word = wordlist[i];
            st.insert(word);
            transform(word.begin(), word.end(), word.begin(),::tolower);
            if(!m1.count(word)){
                m1[word] = wordlist[i];
            }
            for(char &c : word){
                if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c== 'u'){
                    c = '_';
                }
            }
            if(!m2.count(word)){
                m2[word] = wordlist[i];
            }
        }
        for(string q : queries){
            if(st.count(q)){
                ans.push_back(q);
                continue;
            }
            transform(q.begin(), q.end(), q.begin(), ::tolower);
            if(m1.count(q)){
                ans.push_back(m1[q]);
                continue;
            }
            for(char &c : q){
                if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c== 'u'){
                    c = '_';
                }
            }
            if(m2.count(q)){
                ans.push_back(m2[q]);
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }   
};