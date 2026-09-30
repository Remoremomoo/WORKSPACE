#include <iostream>
#include <stdlib.h>
#define MAX 100
using namespace std;

struct Leaf{
    int num;
    Leaf *left, *right;
    Leaf(int x){
        num = x;
        left = nullptr;
        right = nullptr;
    }
};

class Queue{
    private:
    Leaf* s1[MAX];
    int f = -1, r = -1, ctr = 0;
    bool isfull();

    public:
    bool isempty();
    void enQueue(Leaf* x);
    Leaf* deQueue();
};

class Tree{
    private:
    Leaf* root = nullptr;
    void inOrder(Leaf* x);
    void preOrder(Leaf* x);
    void postOrder(Leaf* x);
    void levelOrder(Leaf* x);
    
    public:
    void inOrder();
    void preOrder();
    void postOrder();
    void insertLeaf(int x);
    void levelOrder();
};

void Tree :: inOrder(){
    if(root == nullptr){
        cout<<"Tree is Empty!"<<endl<<endl;
        system("pause");
        return;
    }
    inOrder(root);
    cout<<endl<<endl;
    system("pause");
    return;
}

void Tree :: preOrder(){
    if(root == nullptr){
        cout<<"Tree is Empty!"<<endl<<endl;
        system("pause");
        return;
    }
    preOrder(root);
    cout<<endl<<endl;
    system("pause");
    return;
}

void Tree :: postOrder(){
    if(root == nullptr){
        cout<<"Tree is Empty!"<<endl<<endl;
        system("pause");
        return;
    }
    postOrder(root);
    cout<<endl<<endl;
    system("pause");
    return;
}

void Tree :: levelOrder(){
    system("cls");
    if(root == nullptr){
        cout<<"Tree is Empty!"<<endl<<endl;
        system("pause");
        return;
    }
    levelOrder(root);
    cout<<endl<<endl;
    system("pause");
    return;
}

void Tree :: insertLeaf(int x){
    Leaf* node = new Leaf(x);

    if(root == nullptr){
        root = node;
        return;
    }
    Queue q;
    q.enQueue(root);
    while(q.isempty() == 0){
        Leaf* current = q.deQueue();

        if(current->left == nullptr){
            current->left = node;
            return;
        }
        if(current->right == nullptr){
            current->right = node;
            return;
        }
        q.enQueue(current->left);
        q.enQueue(current->right);
    }
}

void Tree :: levelOrder(Leaf* x){
    if(x == nullptr){
        cout<<"Tree is Empty!"<<endl<<endl;
        system("pause");
        return;
    }
    Queue q;
    q.enQueue(x);
    while(q.isempty() == 0){
        Leaf* current = q.deQueue();
        
        cout<<current->num<<" ";
        if(current->left != nullptr){
            q.enQueue(current->left);
        }
        if(current->right != nullptr){
            q.enQueue(current->right);
        }
    }
}

void Tree :: inOrder(Leaf* x){
    if(x == nullptr){
        return;
    }
    inOrder(x->left);
    cout<<x->num<<" ";
    inOrder(x->right);
}
void Tree :: preOrder(Leaf* x){
    if(x == nullptr){
        return;
    }
    cout<<x->num<<" ";
    preOrder(x->left);
    preOrder(x->right);
}
void Tree :: postOrder(Leaf* x){
    if(x == nullptr){
        return;
    }
    postOrder(x->left);
    postOrder(x->right);
    cout<<x->num<<" ";
}

bool Queue :: isfull(){
    return ctr == MAX;
}
bool Queue :: isempty(){
    return ctr == 0;
}
void Queue :: enQueue(Leaf* x){
    if(isfull()){
        return;
    }
    if(f == -1){
        f++;
        r++;
        s1[f] = x;
        ctr++;
        return;
    }
    r = (r + 1) % MAX;
    s1[r] = x;
    ctr++;
    return;
}
Leaf* Queue :: deQueue(){
    if(isempty()){
        return nullptr;
    }
    Leaf* current = s1[f];
    if(current == nullptr){
        return nullptr;
    }

    f = (f + 1) % MAX;
    ctr--;
    return current;
    
}

int main(){
    Tree t;
    bool running = true;

    while(running){
        system("cls");
        int choice;
        cout<<"BINARY TREE"<<endl<<endl;
        cout<<"1. Inorder"<<endl;
        cout<<"2. Preorder"<<endl;
        cout<<"3. Postorder"<<endl;
        cout<<"4. Level Order"<<endl;
        cout<<"5. Build a Binary Tree"<<endl;
        cout<<"6. Exit"<<endl<<endl;
        cout<<"Choose [1-6]: ";
        cin>>choice;
        cin.ignore();

        switch(choice){
            case 1:
            system("cls");
            t.inOrder();
            break;

            case 2:
            system("cls");
            t.preOrder();
            break;

            case 3:
            system("cls");
            t.postOrder();
            break;

            case 4:
            system("cls");
            t.levelOrder();
            break;

            case 5:{
                system("cls");
                int n, value;
                cout<<"How many nodes? ";
                cin>>n;
                cin.ignore();
                for(int i = 1; i <= n; i++){
                    cout<<"Enter number "<<i<<": ";
                    cin>>value;
                    cin.ignore();
                    t.insertLeaf(value);
                }
                cout<<endl<<"Tree built!"<<endl<<endl;
                system("pause");
                break;
            }

            case 6:
            running = false;
            cout<<endl<<"Exiting..."<<endl;
            break;

            default:
            cout<<endl<<"INVALID INPUT!"<<endl<<endl;
            system("pause");
            break;
        }
    }
    return 0;
}