#include <cstdio>
using namespace std;


// 超高速整數輸入（支援負數）
inline bool readInt(int &x) {
    static char buf[1 << 20]; // 1MB 的內部快取區
    static char *p1 = buf, *p2 = buf;
    
    // 內部 lambda 函式：利用 fread_unlocked 每次讀取一大塊資料到 buf 中
    auto getChar = [&]() -> char {
        if (p1 == p2) {
            p2 = (p1 = buf) + fread_unlocked(buf, 1, 1 << 20, stdin);
            if (p1 == p2) return EOF; // 讀到檔案結尾
        }
        return *p1++;
    };

    char c = getChar();
    if (c == EOF) return false; // 讀取失敗（到 EOF）

    while (c < '0' || c > '9') {
        if (c == EOF) return false;
        c = getChar();
    }

    x = 0;
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + (c - '0'); // 等同於 x = x * 10 + (c - '0')
        c = getChar();
    }
    return true;
}

// 超高速整數輸出
inline void writeInt(int x) {
    if (x < 0) {
        putchar_unlocked('-');
        x = -x;
    }
    if (x == 0) {
        putchar_unlocked('0');
        return;
    }
    char buf[20];
    int idx = 0;
    while (x > 0) {
        buf[idx++] = (x % 10) + '0';
        x /= 10;
    }
    while (idx--) {
        putchar_unlocked(buf[idx]);
    }
}

inline void writeStr(const std::string& s) {
    for (char c : s) {
        putchar_unlocked(c);
    }
}