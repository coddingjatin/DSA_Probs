class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {

        const int INF = 1e9;

        // costTable[a][b] = minimum cost to change a -> b
        vector<vector<int>> costTable(26, vector<int>(26, INF));

        // Cost to change a character to itself is 0
        for (int i = 0; i < 26; i++) {
            costTable[i][i] = 0;
        }

        // Fill direct conversion costs
        for (int i = 0; i < original.size(); i++) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            costTable[from][to] = min(costTable[from][to], cost[i]);
        }

        // Floyd–Warshall: find cheapest path between all characters
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    costTable[i][j] =
                        min(costTable[i][j],
                            costTable[i][k] + costTable[k][j]);
                }
            }
        }

        long long answer = 0;

        // Calculate total cost to convert source -> target
        for (int i = 0; i < source.size(); i++) {
            int from = source[i] - 'a';
            int to = target[i] - 'a';

            if (from != to) {
                if (costTable[from][to] == INF) {
                    return -1; // impossible conversion
                }
                answer += costTable[from][to];
            }
        }

        return answer;
    }
};
