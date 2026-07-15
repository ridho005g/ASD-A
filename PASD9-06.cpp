#include <iostream>
using namespace std;

struct Node {
    string data;
    Node *left;
    Node *right;
};

Node* createNode(string data) {
    Node *baru = new Node;
    baru->data = data;
    baru->left = NULL;
    baru->right = NULL;
    return baru;
}

Node* insert(Node *root, string data) {
    if(root == NULL)
        return createNode(data);

    if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

void preorder(Node *root) {
    if(root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node *root) {
    if(root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void postorder(Node *root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node *root = NULL;
    int n;
    string data;

    cout << "Jumlah Node : ";
    cin >> n;

    for(int i=1; i<=n; i++) {
        cout << "Data ke-" << i << " : ";
        cin >> data;
        root = insert(root, data);
    }

    cout << "\nPreOrder  : ";
    preorder(root);

    cout << "\nInOrder   : ";
    inorder(root);

    cout << "\nPostOrder : ";
    postorder(root);

    cout << endl;

    return 0;
}