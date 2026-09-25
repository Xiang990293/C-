#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// 1. 將你的四組方向陣列宣告為全域常數，C++ 會將其優化到暫存器中
const vector<pair<int, int>> dirs_n = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {0, 1}, {-1, 0}};
const vector<pair<int, int>> dirs_f = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {0, -1}, {1, 0}};
const vector<pair<int, int>> dirs_o = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
const vector<pair<int, int>> dirs_d = {{1, 2}, {-1, 2}, {-2, 1}, {-2, -1}};

int main() {
    // 高效 I/O 優化：切斷與 C 標準流的同步，讓 cin/cout 快如 lightning
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // 2. 二維向量初始化棋盤，-1 代表未造訪
    vector<vector<int>> board(n, vector<int>(n, -1));
    board[0][0] = 0;

    // 3. 標準 C++ 佇列儲存 pair<int, int> 座標
    queue<pair<int, int>> waitq;
    waitq.push({0, 0});

    while (!waitq.empty()) {
        auto [rr, cr] = waitq.front();
        waitq.pop();
        
        int level = board[rr][cr] + 1;

        if (cr < rr) continue;

        // 4. 完全保留你的 opt 列表查找邏輯
        int opt = cr - rr;
        if (opt > 2) opt = 3;

        // 根據 opt 選擇正確的方向參考
        const auto& current_dirs = (opt == 0) ? dirs_d : 
                                   (opt == 1) ? dirs_n : 
                                   (opt == 2) ? dirs_f : dirs_o;

        for (const auto& dir : current_dirs) {
            int r = rr + dir.first;
            int c = cr + dir.second;

            // 5. 邊界與你的對角線剪枝 (只搜上半部)
            if (r > c || c >= n || r < 0 || c < 0) continue;
            if (board[r][c] != -1) continue;

            // 更新並推入佇列
            board[r][c] = level;
            board[c][r] = level; // 同步鏡像更新下半部
            waitq.push({r, c});
        }
    }

    // 6. 高效輸出最終棋盤答案
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << board[i][j] << (j == n - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
