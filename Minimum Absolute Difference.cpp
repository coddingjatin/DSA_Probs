class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        if(n == 0)
            return vector<vector<int>> ();
        vector<vector<int>> result;
        sort(arr.begin(),arr.end());
        int min_diff = arr[1]-arr[0];
        vector <int> v;v.push_back(arr[0]);v.push_back(arr[1]);
        result.push_back(v);
        for(int i = 1; i < n-1; i++){
            if((arr[i+1]-arr[i]) < min_diff){
                min_diff = arr[i+1]-arr[i];                
                result.clear();
                vector <int> v;v.push_back(arr[i]);v.push_back(arr[i+1]);
                result.push_back(v);
            }
            else if ((arr[i+1]-arr[i]) == min_diff){
                vector <int> v;v.push_back(arr[i]);v.push_back(arr[i+1]);
                result.push_back(v);
            }
        }
        return result;
    }
};
