class Solution {
public:
    // Helper function to calculate the frequency of the least frequent character in a string
    inline int add(string &s) {
        map<char,int>mp; 
        // Create a map to store the frequency of each character in the string

        for(auto &x: s) 
            mp[x]++; // Increment the frequency of each character in the map

        return mp.begin()->second; 
        // Return the frequency of the first (and hence least frequent) character in the map
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n=queries.size(), words_len=words.size(); 
        // Get the size of the queries and words vectors

        vector<int>ar_q,ar_w,ans; 
        // Create vectors to store the frequencies of characters in queries and words

        for(auto &x: queries)
            ar_q.push_back(add(x)); 
        // Calculate and store the frequencies of characters in the queries vector

        for(auto &x: words)
            ar_w.push_back(add(x)); 
        // Calculate and store the frequencies of characters in the words vector

        sort(ar_w.begin(),ar_w.end()); 
        // Sort the frequencies of characters in the words vector in ascending order

        for(int i=0;i<n;i++){
            int val=ar_q[i]; // Get the frequency of the character in the current query
            auto p=lower_bound(ar_w.begin(),ar_w.end(),val+1); 
            // Find the first element in the 'ar_w' vector that is greater than or equal to 'val+1' 
            // using lower_bound()

            ans.push_back(words_len-(p-ar_w.begin())); 
            // Calculate the number of words in 'ar_w' with frequencies greater than 'val' 
            // by subtracting the index of the found element from the total number of words
        }
        return ans;
    }
};