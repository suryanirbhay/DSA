class Solution {
  public:
    int countConsec(int n) {
        // code here
        if(n==2) return 1;
        int firstsum=0;
        int secondsum=1;
        int thirdsum;
        int result=1;
        
        
        for(int i=3;i<=n;i++){
            
            thirdsum=firstsum+secondsum;
            result=result*2+thirdsum;
            
            firstsum=secondsum;
            secondsum=thirdsum;
            
            
    
    }
    return result;
    }
    
};