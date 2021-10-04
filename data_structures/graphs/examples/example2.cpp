#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

/*
given the string list - dictionary of words and the list representation
of grapgh full of char characters, check which words can be build
using these characters. We can traverse from character [x][y] in any direction
*/


/* soultion 1: 
traverse graph using dfs with starting node in every index, and
check weather currently selected characters form a word in a dictionary
*/

bool isWord(string word, vector<string> dict) {
    for (string i : dict)
        if (word.compare(i) == 0)
            return 1;
    return 0;
}

void wordBoggleUtil(int i, int j, int N, int M, 
    vector<vector<char> >& board, string current, vector<string>& dict, 
    vector<vector<bool>> &visited, vector<string> &result) {

    visited[i][j] = 1;
    current += board[i][j];
    
    if (isWord(current, dict))
        result.push_back(current);
        
    // traverse all 8 neighbours
    for (int i_ = i - 1; i_ < N && i_ <= i + 1; i_++)
        for (int j_ = j - 1; j_ < M && j_ <= j + 1; j_++)
            if (i_ >= 0 && j_ >= 0 && !visited[i_][j_])
                wordBoggleUtil(i_, j_, N, M, board, current, dict, visited, result);
    
    visited[i][j] = 0;
    current.erase(current.length() - 1);
}

vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dict) {
    int N = board.size();
    int M = board[0].size();
    
    vector<vector<bool>> visited(N, vector<bool>(M, 0));
    vector<string> result;
    string current = "";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            wordBoggleUtil(i, j, N, M, board, current, dict, visited, result);
    
    return result;           
}

int main() {
    vector<vector<char>> board = { 
        { 'G', 'I', 'Z' },
        { 'U', 'E', 'K' },
        { 'Q', 'S', 'E' }
    };

    vector<string> dict = { "GEEKS", "FOR", "QUIZ", "GO" };
    vector<string> result = wordBoggle(board, dict);

    for (string a : result) 
        cout << result << endl;

    return 0;
}

/* solution 2 - OPTIMALIZED 
iterate for every word from dictionary. Find every node in graph
that is equal to word's first node and run a dfs here as long as
we reach the poin where characters don't match the word or the word is found
(or there are no more characters in graph to ue)
*/

class Solution {
private:
    bool dfs(int x, int y, int idx, string word, 
            vector<vector<char>> board, vector<vector<bool>> &visited) {
            if (idx == word.size())
                return 1;
                
            if (x >= 0 && x < board.size() 
                && y >= 0 && y < board[0].size()
                && !visited[x][y] && word[idx] == board[x][y]) {
                
                visited[x][y] = 1;
                
                if (
                    dfs(x - 1, y - 1, idx + 1, word, board, visited) ||
                    dfs(x, y - 1, idx + 1, word, board, visited) ||
                    dfs(x + 1, y - 1, idx + 1, word, board, visited) ||
                    dfs(x - 1, y, idx + 1, word, board, visited) ||
                    dfs(x + 1, y, idx + 1, word, board, visited) ||
                    dfs(x - 1, y + 1, idx + 1, word, board, visited) ||
                    dfs(x + 1, y + 1, idx + 1, word, board, visited) ||
                    dfs(x, y + 1, idx + 1, word, board, visited)
                    )
                    return 1;
                
                visited[x][y] = 0;
            }
            
            return 0;
        }
    bool isWord(string word, vector<vector<char>> &board) {
        int N = board.size();
        int M = board[0].size();
    
        int idx = 0;
        vector<vector<bool>> visited(N, vector<bool>(M, 0));
        for (int x = 0; x < N; x++)
            for (int y = 0; y < M; y++)
                if (board[x][y] == word[idx] && dfs(x, y, idx, word, board, visited))
                    return 1;
        
        return 0;            
    }
public:
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dict) {
	    vector<string> res;
	    
	    for (auto a: dict)
	        if (isWord(a, board))
	            res.push_back(a);
	    
	    return res;
	}
};