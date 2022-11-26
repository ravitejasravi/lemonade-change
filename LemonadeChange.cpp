class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        unordered_map<int, int> change;

        for(int i = 0; i < bills.size(); i++) {

            if(bills[i] == 5)
                change[5] += 1;

            else if(bills[i] == 10) {
                change[5] -= 1;

                if(change[5] < 0) 
                    return false;
                
                change[10] += 1;
            }

            else {
                if(change[10] >=1 && change[5] >= 1) {
                    change[5] -= 1;
                    change[10] -= 1;
                }
                
                else if(change[5] >= 3){
                    change[5] -= 3;
                    continue;
                }
                else return false;
                
            }     
        }

        return true;
    }
};