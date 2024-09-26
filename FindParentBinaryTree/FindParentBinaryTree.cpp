#include <iostream>

using namespace std;

struct Tree {
    int key;
    Tree* left;
    Tree* right;
};

static Tree* createNewNode(int value) {
    Tree* newNode = new Tree();
    newNode->key = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

static Tree* insertNode(Tree* root, int value) {
    if (root == nullptr) {
        root = createNewNode(value);
    }
    else if (value <= root->key) {
        root->left = insertNode(root->left, value);
    }
    else {
        root->right = insertNode(root->right, value);
    }
    return root;
}

static void searchParent(Tree* root, int value, int parent) {
    if (root == nullptr) {
        return;
    }
    if (root->key == value) {
        cout << parent;
    }
    else {
        searchParent(root->left, value, root->key);
        searchParent(root->right, value, root->key);
    }
}

int main() {
    Tree* root = nullptr;
    int nodeCount, nodeValue, searchValue;

    cout << "How many nodes to add to the tree: ";
    cin >> nodeCount;

    for (int i = 0; i < nodeCount; i++) {
        cout << "Key for node " << i + 1 << ": ";
        cin >> nodeValue;
        root = insertNode(root, nodeValue);
    }

    cout << "Find parent of: ";
    cin >> searchValue;
    searchParent(root, searchValue, -1);

    return 0;
}
