#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* right , * left;
    int balanceFactor;
    Node(int value) {
        data = value;
        right = left = nullptr;
        balanceFactor = 0;
    }
    Node() {
        data = 0;
        right = left = nullptr;
        balanceFactor = 0;
    }
};

class AVL {
private:
    Node* root;
public:
    AVL() {
        root = nullptr;
    }
    void destroy(Node* node) {
        if (node) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }
    ~AVL() {
        destroy(root);
    }

    int height(Node* node) {
        if (!node)
            return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    int getBalance(Node* node) {
        if (!node)
            return 0;
        return height(node->left) - height(node->right);
    }
    
    void inorder(Node* node){
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    Node* search(Node* node, int value) {                //recursive search function
        if (!node || node->data == value)
            return node;
        if (value < node->data)
            return search(node->left, value);
        else
            return search(node->right, value);
    }

    Node* searchnode(int value) {                                  //public search function
        return search(root, value);
    }

    Node* rotateRight(Node* y) {                         //LL case
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update balance factors
        y->balanceFactor = getBalance(y);
        x->balanceFactor = getBalance(x);

        // Return new root
        return x;
    }

    Node* rotateLeft(Node* x) {                        //RR case
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update balance factors
        x->balanceFactor = getBalance(x);
        y->balanceFactor = getBalance(y);

        // Return new root
        return y;
    }

    Node* rotateLeftRight(Node* z) {                    //LR case
        z->left = rotateLeft(z->left);
        return rotateRight(z);
    }

    Node* rotateRightLeft(Node* z) {                    //RL case
        z->right = rotateRight(z->right);
        return rotateLeft(z);
    }

    Node* insert(Node* node , int value){

        // Perform the normal BST insertion
        if (node == nullptr) return new Node(value);           
        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        else
            return node; // Duplicate keys not allowed

        // Update balance factor of this ancestor node
        node->balanceFactor = getBalance(node);

        // If this node becomes unbalanced, then there are 4 cases

        // LL Case
        if (node->balanceFactor > 1 && value < node->left->data)
            return rotateRight(node);

        // RR Case
        if (node->balanceFactor < -1 && value > node->right->data)
            return rotateLeft(node);

        // LR Case
        if (node->balanceFactor > 1 && value > node->left->data)
            return rotateLeftRight(node);

        // RL Case
        if (node->balanceFactor < -1 && value < node->right->data)
            return rotateRightLeft(node);

        return node;
    }

    Node* insertnode(int value) {                                  //public insert function
        root = insert(root, value);
        return root;   
    }

    Node* deletenode(Node* node , int value){
        // Perform the normal BST deletion

        if (node == nullptr) return new Node(value);           
        if (value < node->data)
            node->left = deletenode(node->left, value);
        else if (value > node->data)
            node->right = deletenode(node->right, value);

        else {
            // Node with only one child or no child
            if(node->left == NULL || node->right == NULL){
                Node* temp;

                if (node->left != nullptr) temp = node->left;
                else temp = node->right;
                

                // No child case
                if (temp == NULL) {
                    temp = node;
                    node = NULL;
                }
                else // One child case
                    *node = *temp; // Copy the contents of the non-empty child
                delete temp;
            }
            else {
                // Node with two children: Get the inorder successor (smallest in the right subtree)
                Node* temp = node->right;

                while (temp->left != NULL)
                    temp = temp->left;

                // Copy the inorder successor's content to this node
                node->data = temp->data;    

                // Delete the inorder successor
                node->right = deletenode(node->right, temp->data);
            }

        }

        // Update balance factor of this ancestor node
        node->balanceFactor = getBalance(node);

        // If this node becomes unbalanced, then there are 4 cases

        // LL Case
        if (node->balanceFactor > 1 && getBalance(node->left) >= 0)
            return rotateRight(node);
        // RR Case
        if (node->balanceFactor < -1 && getBalance(node->right) <= 0)
            return rotateLeft(node);

        // LR Case
        if (node->balanceFactor > 1 && getBalance(node->left) < 0)
            return rotateLeftRight(node);
        
        // RL Case
        if (node->balanceFactor < -1 && getBalance(node->right) > 0)
            return rotateRightLeft(node);

        return node;
    }






};

