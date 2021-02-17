class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for(string e : emails){
            string mail;
            for(char c : e){
                if(c == '.'){
                    continue;
                }
                if(c == '+' || c == '@'){
                    break;
                }
                mail.push_back(c);
            }
            mail += e.substr(e.find('@'));
            s.insert(mail);
        }
        return s.size();
    }
};