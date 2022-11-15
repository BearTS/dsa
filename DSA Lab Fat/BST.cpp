#include <iostream>
using namespace std;

class Node {
    public:
        Node *left;
        Node *right;
        int data;
        Node(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

class BST {
    private:
        Node *_root;
    public:
        BST() {
            _root = NULL;
        }
        void insert(int data) {
            insert(_root, data);
        }
        void insert(Node *treeNode, int data){
            if (!treeNode){
                treeNode = new Node(data);
                _root = treeNode;
                return; 
            } 
            if (data < treeNode->data){
                if (!treeNode->left){
                    Node *treeTemp = new Node(data);
                    treeNode->left = treeTemp;
                } else {
                    insert(treeNode->left, data);
                }
            } else if (data > treeNode->data){
                if (!treeNode->right){
                    Node *treeTemp = new Node(data);
                    treeNode->right = treeTemp;
                } else {
                    insert(treeNode->right, data);
                }
            }
        }
        void inOrder() { inOrder(_root); }
        void inOrder(Node *treeNode){
            if (!treeNode) return;
            inOrder(treeNode->left);
            cout << treeNode->data << " ";
            inOrder(treeNode->right);
        }

        void preOrder() { preOrder(_root); }
        void preOrder(Node *treeNode){
            if (!treeNode) return;
            cout << treeNode->data << " ";
            preOrder(treeNode->left);
            preOrder(treeNode->right);

        }
        
        void postOrder() { postOrder(_root); }
        void postOrder(Node *treeNode) {
            if (!treeNode) return;
            postOrder(treeNode->left);
            postOrder(treeNode->right);
            cout << treeNode->data << " ";
        }

        // 
        // 
        int minValue() { return minValue(_root);}
        int minValue(Node *treeNode){
            if (treeNode->left == NULL) return treeNode->data;
            return minValue(treeNode->left);
        }

        int maxValue() { return maxValue(_root);}
        int maxValue(Node *treeNode){
            if(treeNode->right == NULL) return treeNode->data;
            return maxValue(treeNode->right);
        }
        
        int getHeight() { return getHeight(_root);}
        int getHeight(Node *treeNode) {
            if (!treeNode)
                return 0;
            return 1 + max(getHeight(treeNode->left) , getHeight(treeNode->right));
        }

        bool isBalanced() { return isBalanced(_root); }
        bool isBalanced(Node *treeNode) {
            if (!treeNode)
                return false;
            int leftHeight = getHeight(treeNode->left);
            int rightHeight = getHeight(treeNode->right);

            if (abs(leftHeight - rightHeight) > 1)
                return false;
            return true;
        }

        //
        Node *deleteNode(int data) { 
            deleteNode(_root, data);
        }
        Node *deleteNode(Node *root, int key){
            if (root == NULL) return root;
            if (key < root->data) {
                root->left = deleteNode(root->left,key);
            } else if (key > root->data) {
                root->right = deleteNode(root->right, key);
            } else {
                //  case 1 : No Child
                if (root->left == NULL && root->right == NULL){
                    delete root;
                    root = NULL;
                }
                // case 2: One child
                else if (root->left == NULL) {
                    Node *temp = root;
                    root = root->right;
                    delete temp;
                }
                else if (root->right == NULL)
                {
                    Node *temp = root;
                    root = root->left;
                    delete temp;
                }
                // Case 3: Two children
                else
                {
                    Node *temp = root->right;
                    while (temp->left != NULL)
                    {
                        temp = temp->left;
                    }
                    root->data = temp->data;
                    root->right = deleteNode(root->right, temp->data);
                }
            }
            return root;
        }
        


};

int main() {
        BST myBST;
        myBST.insert(5);
        myBST.insert(10);
        myBST.insert(3);

        myBST.insert(51);
        myBST.insert(110);
        myBST.insert(13);
        cout << " in-order traverse is : " << endl;
        myBST.inOrder();
        cout << endl;
        myBST.preOrder();
        cout << endl;
        myBST.postOrder();
        cout << endl;
        cout << myBST.minValue();
        cout << endl;
        cout << myBST.maxValue();
        cout << endl;
        cout << myBST.isBalanced();
        cout << endl;
        myBST.deleteNode(3);
        myBST.inOrder();
}