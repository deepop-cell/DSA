class Solution {
public:
    int n;
    vector<vector<pair<int,int>>> dp;
    int MOD = 1e9 + 7;

    bool isvalid(int i, int j, int n, vector<string>& board){
        if(i >= 0 && j >= 0 && i < n && j < n && board[i][j] != 'X'){
            return true;
        }
        else{
            return false;
        }
    }

    pair<int,int> solve(int i, int j, vector<string>& board){
        // base case.
        if(board[i][j] == 'E'){
            return {0, 1};
        }

        // agar x aa gya to
        if(board[i][j] == 'X'){
            return {0, 0};
        }

        // checking if already pata hai kya hume
        if(dp[i][j] != make_pair(-1, -1)){
            return dp[i][j];
        }

      
        int upscore = -1, uppath = 0;
        int leftscore = -1, leftpath = 0;
        int diagscore = -1, diagpath = 0;

        char ch = board[i][j];

        /// for up.
        if(isvalid(i - 1, j, n, board)){
            auto [score, path] = solve(i - 1, j, board);
            if(path > 0){ // matlab atleast ek path hai E tak
                upscore = score;
                uppath = path;
                if(ch != 'S' && ch != 'E'){
                    upscore += ch - '0';
                }
            }
        }

        // left
        if(isvalid(i, j - 1, n, board)){
            auto [score, path] = solve(i, j - 1, board);
            if(path > 0){ // matlab atleast ek path to hai waha tk jane ka .
                leftscore = score;
                leftpath = path;
                if(ch != 'S' && ch != 'E'){
                    leftscore += ch - '0';
                }
            }
        }

        if(isvalid(i - 1, j - 1, n, board)){
            auto [score, path] = solve(i - 1, j - 1, board);
            if(path > 0){ // atleast ek path to hai jane ka
                diagscore = score;
                diagpath = path;
                if(ch != 'S' && ch != 'E'){
                    diagscore += ch - '0';
                }
            }
        }

        int bestscore = 0;
        int bestpath = 0;

        // now find the best from all of them using your if-else logic
        if(upscore == leftscore && leftscore == diagscore){
            bestscore = upscore;
            bestpath = (uppath + leftpath + diagpath) % MOD;
        }
        else if(upscore == leftscore){
            bestscore = upscore;
            bestpath = (uppath + leftpath) % MOD;
            if(diagscore > bestscore){
                bestscore = diagscore;
                bestpath = diagpath;
            }
        }
        else if(leftscore == diagscore){
            bestscore = leftscore;
            bestpath = (leftpath + diagpath) % MOD;
            if(upscore > bestscore){
                bestscore = upscore;
                bestpath = uppath;
            }
        } 
        else {
            // all different.
            bestscore = upscore;
            bestpath = uppath;
            if(leftscore > bestscore){
                bestscore = leftscore;
                bestpath = leftpath;
            }
            if(diagscore > bestscore){
                bestscore = diagscore;
                bestpath = diagpath;
            }
        }

        // If no paths are available at all from this cell
        if(bestscore == -1) {
            return dp[i][j] = {0, 0};
        }

        return dp[i][j] = {bestscore, bestpath};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
         n = board.size();
         dp.assign(n, vector<pair<int,int>>(n, {-1, -1}));
         pair<int,int> result = solve(n - 1, n - 1, board);
         return {result.first, result.second};
    }
};