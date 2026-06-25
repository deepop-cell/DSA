
class DisjointSet {
public:
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i; 
        }
    }

    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]); // Path compression
    }

    void Union(int x, int y) {
        int p1 = find(x);
        int p2 = find(y);
        if (p1 == p2) return;
        // Union by Rank
        if (rank[p1] > rank[p2]) {
            parent[p2] = p1;
        } else if (rank[p2] > rank[p1]) {
            parent[p1] = p2;
        } else {
            parent[p2] = p1;
            rank[p1]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);

        // MAP 1: The Matchmaker (email -> account index)
        unordered_map<string, int> emailToAcc;
        for (int i = 0; i < n; i++) {
            // Start from index 1 because index 0 is the account name
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];      
                // If this email was seen before, merge current account with that account
                if (emailToAcc.find(email) != emailToAcc.end()) {
                    ds.Union(i, emailToAcc[email]);
                } else {
                    emailToAcc[email] = i;
                }
            }
        }

        // MAP 2: The Gatherer (Ultimate Parent Root -> list of unique emails)
        unordered_map<int, vector<string>> mergedAccounts;
        for (auto& it : emailToAcc) {
            string email = it.first;
            int accNode = it.second;
            int root = ds.find(accNode); // Find the ultimate boss of this account
            mergedAccounts[root].push_back(email);
        }
        vector<vector<string>> result;
        for (auto& it : mergedAccounts) {
            int rootIndex = it.first;
            vector<string> emails = it.second;

            sort(emails.begin(), emails.end());
            vector<string> accountDetails;
            accountDetails.push_back(accounts[rootIndex][0]); // Get name from original root
            accountDetails.insert(accountDetails.end(), emails.begin(), emails.end());
            
            result.push_back(accountDetails);
        }

        return result;
    }
};