#include<iostream>
using namespace std;


struct Node
{
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
    Node() : val(NULL), left(nullptr), right(nullptr) {}
};

class BST
{
public:
    Node* root = nullptr;
    BST(Node* n): root(n) {}
    BST(): root(nullptr) {}

    void insert(int newval)
    {
        if (!this->root)
        {
            this->root = new Node(newval);
            return;
        }

        Node* current_node = this->root;
        Node* prev_node = nullptr;

        while (current_node)
        {
            prev_node = current_node;
            if (newval < current_node->val)
                current_node = current_node->left;
            else
                current_node = current_node->right;
        }

        Node* new_node = new Node(newval);

        if (prev_node->val > newval)
            prev_node->left = new_node;
        else
            prev_node->right = new_node;
    }

    string get_prefix_sort()
    {
        string result = "";

        if (!this->root) return "";
        result += to_string(this->root->val) + " ";

        if (this->root->left)
            result += BST(this->root->left).get_prefix_sort();
        if (this->root->right)
            result += BST(this->root->right).get_prefix_sort();

        return result;
    }
};

int main()
{
    int n,m;
    while (cin >> n)
    {
        BST main_tree;

        for (int i = 0; i < n; i++)
        {
            cin >> m;
            main_tree.insert(m);
        }

        cout << main_tree.get_prefix_sort().substr(0, main_tree.get_prefix_sort().length() - 1) << endl;
    }
}