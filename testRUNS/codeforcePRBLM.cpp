#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void Answer(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> visKingdom(n + 1, 0);
        vector<int> visPrincess(n, 0);
        vector<int> princeCount(n + 1, 0); // Count of daughters for each prince

        for (int i = 0; i < n; i++) {
            int j = 0;
            int m = adj[i].size();

            if (adj[i].empty()) {
                int vacancy = VacantPrince(visKingdom, princeCount);
                if (vacancy != -1) {
                    cout << "IMPROVE" << endl;
                    cout << i + 1 << " " << vacancy << endl;
                    return;
                } else {
                    cout << "OPTIMAL" << endl;
                    return;
                }
            }

            int choice = adj[i][j];
            while (j < m && visKingdom[choice]) {
                j++;
                if (j == m) {
                    int vacancy = VacantPrince(visKingdom, princeCount);
                    if (vacancy != -1) {
                        cout << "IMPROVE" << endl;
                        cout << i + 1 << " " << vacancy << endl;
                        return;
                    } else {
                        cout << "OPTIMAL" << endl;
                        return;
                    }
                }
                choice = adj[i][j];
            }

            if (!visKingdom[choice]) {
                visKingdom[choice] = 1;
                visPrincess[i] = 1;
                princeCount[choice]++;
            }
        }

        cout << "OPTIMAL" << endl;
    }

    int VacantPrince(vector<int>& visKingdom, vector<int>& princeCount) {
        for (int i = 1; i < visKingdom.size(); i++) {
            if (!visKingdom[i]) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution sol;
        vector<vector<int>> adj;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            vector<int> temp;

            for (int j = 0; j < x; j++) {
                int y;
                cin >> y;
                temp.push_back(y);
            }

            adj.push_back(temp);
        }

        sol.Answer(adj);
    }
    return 0;
}
//consider adding diff prince lead to more marriages
