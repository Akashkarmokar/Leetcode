class Solution {
public:
    struct node{
        node* next[26];
        bool eow;
        node(){
            eow = false;
            for(int i=0;i<26;i++){
                next[i] = NULL;
            }
        }
        
    };
    struct node *root = new node();
    void insert(string str){
        node* cur = root;
        for(int i=0;i<str.size();i++){
            int id = str[i] - 'a';
            if(cur->next[id]==NULL){
                cur->next[id] = new node();
            }
            cur = cur->next[id];
        }
        cur->eow = true;
    }
    
    void search(node* cur,string &s,string &ans){
        for(int i=0;i<26;i++){
            if(cur->next[i]!=NULL && cur->next[i]->eow){
                s+=char(i+'a');
                if(s.size()>ans.size()){
                    ans = s;
                }
                search(cur->next[i],s,ans);
                s.pop_back();
            }
        }
    }
    
    string longestWord(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            insert(words[i]);
        }
        string ans = "";
        string tmp;
        search(root,tmp,ans);
        return ans;
    }
};