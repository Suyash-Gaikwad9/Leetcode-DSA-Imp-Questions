class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int low_index = 0;
        int total_gas = 0, total_cost = 0;
        int n = gas.size();
        int curr_gas = 0;
        for(int i = 0; i<n; i++){
            total_gas += gas[i];
            total_cost += cost[i];
            curr_gas = curr_gas + gas[i] - cost[i];
            if(curr_gas < 0){
                low_index = i + 1;
                curr_gas = 0;
            }
        }
        if(total_gas >= total_cost){
            return low_index;
        }
        return -1;
    }
};