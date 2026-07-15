#include <iostream>
using namespace std;

struct Node {
    string info;
    Node *left;
    Node *right;
};

void PreOrder(Node *root) {
    if(root != NULL) {
        cout << root->info << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void InOrder(Node *root) {
    if(root != NULL) {
        InOrder(root->left);
        cout << root->info << " ";
        InOrder(root->right);
    }
}

void PostOrder(Node *root) {
    if(root != NULL) {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->info << " ";
    }
}

int main() {
    Node *root, *kiri, *kanan;

    string dataRoot, dataKiri, dataKanan;
	
    cout << "Input Root        : ";
    cin >> dataRoot;

    cout << "Input Leaf Kiri   : ";
    cin >> dataKiri;

    cout << "Input Leaf Kanan  : ";
    cin >> dataKanan;

    root = new Node;
    root->info = dataRoot;
    root->left = NULL;
    root->right = NULL;

    kiri = new Node;
    kiri->info = dataKiri;
    kiri->left = NULL;
    kiri->right = NULL;

    kanan = new Node;
    kanan->info = dataKanan;
    kanan->left = NULL;
    kanan->right = NULL;

    root->left = kiri;
    root->right = kanan;
	cout<<endl;
    cout << "|-----------------------------|" << endl;
    cout << "| Algoritma dan Struktur Data |" << endl;
    cout << "| Ridho Sachlan - 4525210066  |" << endl;
    cout << "|-----------------------------|" << endl;
    cout << "|         Binary Tree         |" << endl;
    cout << "|-----------------------------|" << endl;
	cout <<endl;

    cout << "\nPreOrder  : ";
    PreOrder(root);

    cout << "\nInOrder   : ";
    InOrder(root);

    cout << "\nPostOrder : ";
    PostOrder(root);

    cout << endl;

    return 0;
}