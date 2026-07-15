#include <iostream>
using namespace std;

typedef struct node *alamatnode;
typedef struct node {
    char INFO;
    alamatnode RIGHT;
    alamatnode LEFT;
} NODE;

typedef struct {
    NODE* root;
} TREE;

void BuatTree(char C, TREE *T) {
    NODE *Baru;
    Baru = new NODE;
    Baru->INFO = C;
    Baru->RIGHT = NULL;
    Baru->LEFT = NULL;
    (*T).root = Baru;
}

void TambahKanan(char C, NODE *root) {
    if(root->RIGHT == NULL) {
        NODE *Baru;
        Baru = new NODE;
        Baru->INFO = C;
        Baru->RIGHT = NULL;
        Baru->LEFT = NULL;
        root->RIGHT = Baru;
    }
    else
        cout << "Sub Tree Kanan telah diisi" << endl;
}

void TambahKiri(char C, NODE *root) {
    if(root->LEFT == NULL) {
        NODE *Baru;
        Baru = new NODE;
        Baru->INFO = C;
        Baru->RIGHT = NULL;
        Baru->LEFT = NULL;
        root->LEFT = Baru;
    }
    else
        cout << "Sub Tree Kiri telah diisi" << endl;
}

void HapusAll(NODE *root) {
    if(root != NULL) {
        HapusAll(root->LEFT);
        HapusAll(root->RIGHT);
        delete root;
    }
}

void HapusKanan(NODE *root) {
    if(root != NULL) {
        if(root->RIGHT != NULL) {
            HapusAll(root->RIGHT);
            root->RIGHT = NULL;
        }
    }
}

void HapusKiri(NODE *root) {
    if(root != NULL) {
        if(root->LEFT != NULL) {
            HapusAll(root->LEFT);
            root->LEFT = NULL;
        }
    }
}

void CetakTreePreOrder(NODE *root) {
    if(root != NULL) {
        cout << root->INFO << " " << endl;
        CetakTreePreOrder(root->LEFT);
        CetakTreePreOrder(root->RIGHT);
    }
}

void CetakTreeInOrder(NODE *root) {
    if(root != NULL) {
        CetakTreeInOrder(root->LEFT);
        cout << root->INFO << " " << endl;
        CetakTreeInOrder(root->RIGHT);
    }
}

void CetakTreePostOrder(NODE *root) {
    if(root != NULL) {
        CetakTreePostOrder(root->LEFT);
        CetakTreePostOrder(root->RIGHT);
        cout << root->INFO << " " << endl;
    }
}

void CopyTree(NODE *root1, NODE **root2) {
    if(root1 != NULL) {
        (*root2) = new NODE;
        (*root2)->INFO = root1->INFO;
        if(root1->LEFT != NULL) {
            CopyTree(root1->LEFT, &(*root2)->LEFT);
        }
        if(root1->RIGHT != NULL) {
            CopyTree(root1->RIGHT, &(*root2)->RIGHT);
        }
    }
}

bool isEqual(NODE *root1, NODE *root2) {
    bool Hasil = true;
    if((root1 == NULL) && (root2 != NULL)) {
        if(root1->INFO != root2->INFO) {
            Hasil = false;
        }
        else {
            isEqual(root1->LEFT, root2->LEFT);
            isEqual(root1->RIGHT, root2->RIGHT);
        }
    }
    else {
        if((root1 != NULL) || (root2 != NULL)) {
            Hasil = false;
        }
    }
    return Hasil;
}

int main() {
    TREE T;

    BuatTree('R', &T);
    TambahKiri('S', T.root);
    TambahKanan('U', T.root);
    TambahKiri('V', T.root->LEFT);
    TambahKanan('W', T.root->LEFT);
    TambahKiri('Y', T.root->RIGHT);
    TambahKanan('Z', T.root->RIGHT);

    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << " ~~~~~~  PREORDER  ~~~~~~~ " << endl;
    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << endl;
    CetakTreePreOrder(T.root);
    cout << endl;

    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << " ~~~~~~  INORDER  ~~~~~~~ " << endl;
    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << endl;
    CetakTreeInOrder(T.root);
    cout << endl;

    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << " ~~~~~  POSTORDER  ~~~~~~~ " << endl;
    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << endl;
    CetakTreePostOrder(T.root);
    cout << endl;

    TREE T2;
    T2.root = NULL;

    CopyTree(T.root, &T2.root);
    if(isEqual(T.root, T2.root) == 1) {
        cout << " TREE yang sama" << endl;
    }
    else {
        cout << " TREE yang tidak sama" << endl;
    }

    HapusKanan(T.root->LEFT);
    HapusKiri(T.root->LEFT);
    cout << endl;

    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << " PREORDER Setelah Dihapus " << endl;
    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << endl;
    CetakTreePreOrder(T.root);
    cout << endl;

    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;

    return 0;
}