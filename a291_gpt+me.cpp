// gpt let cooect  to be wrong, fut success to speed up code i think.

#include <iostream>
#include <set>
using namespace std;

int main() {
    int a[4], t;
    int i, r, c;
    while (true) {
        if (scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]) != 4) {
            break;
        }
        scanf("%d", &t);
        int b[4], p = 0, q = 0;
        set<int> visited_indices;

        for (i = 0; i < t; i++) {
            scanf("%d %d %d %d", &b[0], &b[1], &b[2], &b[3]);
            p = 0;
            q = 0;
            visited_indices.clear();

            for (c = 0; c < 4; c++) {
                if (a[c] == b[c]) {
                    p++;
                    visited_indices.insert(c);
                }
            }

            for (r = 0; r < 4; r++) {
                for (c = 0; c < 4; c++) {
                    if (r != c && a[r] == b[c] && !visited_indices.count(r) && !visited_indices.count(c)) {
                        q++;
                        visited_indices.insert(r);
                        visited_indices.insert(c);
                        break;
                    }
                }
            }

            printf("%dA%dB\n", p, q);
        }
    }
}