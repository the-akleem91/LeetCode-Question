//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        
        vector<int> adj[K];
        vector<int> indegree(K , 0);
        
        string s1;
        string s2;
        string str;
        
      
        for(int i = 0 ; i < N-1 ; i++)
        {
            s1 = dict[i];
            s2 = dict[i+1];
            int s = 0;
            int e = 0;
            

            while( s < s1.length()  && (e < s2.length()) && s1[s]==s2[e])
            {
            
                s++;
                e++;
            }
           
              if(s < s1.length() && e < s2.length()) { 
              adj[s1[s]-'a'].push_back(s2[e]-'a');
          }
          
        }
        
      
        for(int i = 0 ; i < K ;  i++)
        {
            for(auto node : adj[i]) indegree[node]++;
        }
        
        queue<int>q;
        
        for(int i = 0 ; i < K ; i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        
      
        while(!q.empty())
        {
            int top = q.front();
            q.pop();
            str.push_back(char(top + 'a'));
            
            for(auto i : adj[top])
            {
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        
        return str;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends