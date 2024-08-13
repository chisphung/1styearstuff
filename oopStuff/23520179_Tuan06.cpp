#include <iostream>
#include <string>
using namespace std;

class Students {
protected:
    int ID;
    string Name;
    double Ovr;
public:
    Students(int ID = 0, string Name = "", double Ovr = 0.0) {
        this->ID = ID;
        this->Name = Name;
        this->Ovr = Ovr;
    }
    void Input() {
        cout << "Nhap MSSV: \n";
        cin >> ID;
        cout << "Nhap ten SV: \n";
        cin.ignore();
        getline(cin, Name);
        cout << "Nhap DTB :\n";
        cin >> Ovr;
    }
    void Output() const {
        cout << "MSSV: " << ID << '\n';
        cout << "Ten: " << Name << '\n';
        cout << "DTB: " << Ovr << '\n';
    }
    int getID() const {
        return ID;
    }
    string getName() const {
        return Name;
    }
    double getOvr() const {
        return Ovr;
    }
};

struct Tree {
    Students data;
    Tree* left = nullptr;
    Tree* right = nullptr;
};

Tree* CreateTree(const Students& x) {
    Tree* temp = new Tree;
    temp->data = x;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

Tree* Add(Tree* a, const Students& x) {
    if (a == nullptr) {
        return CreateTree(x);
    }
    if (x.getID() < a->data.getID()) {
        a->left = Add(a->left, x);
    }
    else if (x.getID() > a->data.getID()) {
        a->right = Add(a->right, x);
    }
    return a;
}

Tree* Search(Tree* a, int x) {
    if (a == nullptr || a->data.getID() == x) {
        return a;
    }
    if (x < a->data.getID()) {
        return Search(a->left, x);
    }
    return Search(a->right, x);
}

void OutputLNR(Tree* a) {
    if (a != nullptr) {
        OutputLNR(a->left);
        a->data.Output();
        OutputLNR(a->right);
    }
}

void FindFrom5(Tree* a) {
    if (a != nullptr) {
        FindFrom5(a->left);
        if (a->data.getOvr() >= 5.0) {
            a->data.Output();
        }
        FindFrom5(a->right);
    }
}

Tree* DeleteNode(Tree* root, int id) {
    if (root == nullptr) return root;
    if (id < root->data.getID()) {
        root->left = DeleteNode(root->left, id);
    }
    else if (id > root->data.getID()) {
        root->right = DeleteNode(root->right, id);
    }
    else {
        if (root->left == nullptr) {
            Tree* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Tree* temp = root->left;
            delete root;
            return temp;
        }
        Tree* temp = root->right;
        while (temp && temp->left != nullptr) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = DeleteNode(root->right, temp->data.getID());
    }
    return root;
}

Tree* DeleteUnder5(Tree* root) {
    if (root == nullptr) return root;
    root->left = DeleteUnder5(root->left);
    root->right = DeleteUnder5(root->right);
    if (root->data.getOvr() < 5.0) {
        root = DeleteNode(root, root->data.getID());
    }
    return root;
}

class Managing {
private:
    int n;
    Tree* root;
public:
    Managing() : n(0), root(nullptr) {}

    void Input() {
        cout << "Nhap so luong sinh vien: \n";
        cin >> n;
        for (int i = 0; i < n; i++) {
            Students temp;
            temp.Input();
            root = Add(root, temp);
        }
    }

    void COutputLNR() const {
        OutputLNR(root);
        cout << '\n';
    }

    void SearchStd() const {
        int tempID;
        cout << "Nhap MSSV can tim: \n";
        cin >> tempID;
        Tree* result = Search(root, tempID);
        if (result != nullptr) {
            result->data.Output();
        }
        else {
            cout << "Sinh vien khong ton tai\n";
        }
    }

    void UpperFive() const {
        FindFrom5(root);
    }

    void DeleteUnderfive() {
        root = DeleteUnder5(root);
    }
};

int main() {
    Managing a;
    a.Input();
    a.COutputLNR();
    a.SearchStd();
    cout << "Sinh vien co DTB tren 5.0 la : \n";
    a.UpperFive();
    cout << "Danh sach sau khi xoa sinh vien co DTB duoi 5.0: \n";
    a.DeleteUnderfive();
    a.COutputLNR();
    return 0;
}
