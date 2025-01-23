class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        // Usar vector<vector<bool>> para la tabla de DP
        vector<vector<bool>> matching(m + 1, vector<bool>(n + 1, false));
        matching[0][0] = true; // Caso base: cadenas vacías coinciden.
        char charS, charP, charP1;
        // Inicializar cuando `s` está vacío y `p` contiene patrones como "a*b*c*"
        for (int j = 2; j <= n; ++j) {
            if (p[j - 1] == '*') {
                matching[0][j] = matching[0][j - 2];
            }
        }
        for(int i = 1; i < s.size() + 1; i++){
            charS = s[i-1];
            for(int j = 1; j < p.size() + 1; j++){
                charP = p[j-1];
                if(charS == charP || charP == '.') matching[i][j] = matching[i-1][j-1];
                else if(charP == '*'){
                    charP1 = p[j-2]; 
                    matching[i][j] = matching[i][j-2];
                    if(charS == charP1 || charP1 == '.') matching[i][j] = matching[i][j] || matching[i-1][j];
                }
            }
        }
        return matching[s.size()][p.size()];
    }
};
