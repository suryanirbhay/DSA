class Solution {
public:
    string makeFancyString(string s) {
        
        int n=s.size();
        string res="";
        res.push_back(s[0]);
        int freq=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==res.back()){
                freq++;
                if(freq<3){
                    res.push_back(s[i]);
                }
            }
                else{
                    res.push_back(s[i]);
                    freq=1;
                }
            
        }
        return res;
    }
};