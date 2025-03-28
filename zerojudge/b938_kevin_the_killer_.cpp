#include<iostream>
#include <cstdio>
using namespace std;

struct node{

    node() {
        next = nullptr;
    }

    node(node* n) {
        next = n;
    }

    node(int num) {
        next = nullptr;
        code = num;
    }

    node(int num, node* n) {
        next = n;
        code = num;
    }

    node* next;
    int code;
};

struct linked_queue {
    linked_queue(){
        head = new node();
        length = 1;
    }

    linked_queue(int len) {
        head = new node[len];
        for (int i = 0; i < len-1; i++) {
            head[i].next = &head[i+1];
            head[i].code = i+1;
        }
        head[len-1].code = len;

        length = len;
    }

    linked_queue(int len, int* value) {
        head = new node[len];
        try {
            for (int i = 0; i < len; i++) {
                head[i].next = &head[i+1];
                head[i].code = value[i];
            }
        } catch (...) {
            errc(address_not_available);
        }

        length = len;
    }

    int pop_node(int code) {

        node* target = head;
        while (target->code != code) {

            if (target->code > code) {
                return -1;
            }
            if (target->next == nullptr) {
                return -1;
            }
            target = target->next;
        }
        if (target->next == nullptr) {
            return -1;
        }

        int result = target->next->code;

        target->next = target->next->next;
        length--;

        return result;
    }

    node* head;
    int length;
};


int main() {
    int total, count;

    /*while (cin >> total) {
        string printed = "1"+to_string(3)+"\n";
        printf("%s",(to_string(total) + "\n").c_str());
    }*/

    while (cin >> total) {
        int index;
        linked_queue queue = linked_queue(total);
        scanf("%d", &count);
        if (count <= 10000) {
            for (int i = 0; i < count; i++) {
                scanf("%d", &index);

                int popping_code = queue.pop_node(index);
                if (popping_code == -1) {
                    printf("0u0 ...... ?\n");
                    continue;
                }

                printf("%d\n", popping_code);
            }
        } else {
            string result = "";
            int counter = 0;
            cout << total << endl;
            for (int i = 0; i < count; i++) {
                scanf("%d", &index);

                int popping_code = queue.pop_node(index);
                if (popping_code == -1) {
                    result += "0u0 ...... ?\n";
                    continue;
                }
                else result += to_string(popping_code) + "\n";

                counter++;
                if(counter == 100000) {
                    printf("%s",result.c_str());
                    counter = 0;
                    result = "";
                }
            }
            printf("%s",result.c_str());
        }
    }

    return 0;
}
