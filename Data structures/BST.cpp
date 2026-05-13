#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* right , * left;
    Node(int value) {
        data = value;
        right = left = nullptr;
    }
    Node() {
        data = 0;
        right = left = nullptr;
    }
};

class BST {
private:
    Node* root;
public:
    BST() {
        root = nullptr;
    }
    void destroy(Node* node) {
        if (node) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }
    ~BST() {
        destroy(root);
    }

    Node* search(Node* node, int value) {                //recursive search function
        if (!node || node->data == value)
            return node;
        if (value < node->data)
            return search(node->left, value);
        else
            return search(node->right, value); 

        return node; 
    }

    Node* searchnode(int value) {                                  //public search function
        return search(root, value);
    }

    Node* insert(Node* node , int value){
        if (node == nullptr) return new Node(value);           
        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        return node;
    }

    Node* insertnode(int value) {                                  //public insert function
        root = insert(root, value);
        return root;   
    }

    Node* deletenode(Node* node , int value){

        if (node == nullptr) return nullptr;           
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
                    delete node;
                    return nullptr;
                }
                else // One child case
                    *node = *temp; // Copy the contents of the non-empty child
                delete temp;
            }
            else {
                // Node with two children: Get the inorder successor

                Node* temp = node->right;

                while (temp->left != NULL)
                    temp = temp->left;

                // Copy the inorder successor's content to this node
                node->data = temp->data;    

                // Delete the inorder successor
                node->right = deletenode(node->right, temp->data);
            }

        }
        return node;
    }

    void inorder(Node* node){
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void inorder() {                                  //public inorder function
        inorder(root);
    }
    
    void preorder(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void preorder() {                                 //public preorder function
        preorder(root);
    }

    void postorder(Node* node) {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    void postorder() {                                //public postorder function
        postorder(root);
    }

    // BFS
    void bfs(Node* node) {
        if (node == nullptr) return;

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
    }
    void bfs() {                                    //public bfs function
        bfs(root);
    }



};
