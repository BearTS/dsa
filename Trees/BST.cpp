#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *left;
    Node *right;
};


// Function to display the tree
void display(Node *root)
{
    if (root == NULL)
        return;
    display(root->left);
    cout << root->data << " ";
    display(root->right);
}

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the BST
Node *insertNode(Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to delete a node from the BST
Node *deleteNode(Node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        // Case 2: One child
        else if (root->left == NULL)
        {
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

// Function to search a node in the BST
bool searchNode(Node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }
    else if (data <= root->data)
    {
        return searchNode(root->left, data);
    }
    else
    {
        return searchNode(root->right, data);
    }
}

// Function to find the minimum value in the BST
int findMin(Node *root)
{
    if (root == NULL)
    {
        cout << "Error: Tree is empty" << endl;
        return -1;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}


// Function to find the maximum value in the BST
int findMax(Node *root)
{
    if (root == NULL)
    {
        cout << "Error: Tree is empty" << endl;
        return -1;
    }
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

// Function to find kth smallest element in the BST
int findKthSmallest(Node *root, int k)
{
    static int count = 0;
    if (root == NULL)
    {
        return -1;
    }
    int left = findKthSmallest(root->left, k);
    if (left != -1)
    {
        return left;
    }
    count++;
    if (count == k)
    {
        return root->data;
    }
    return findKthSmallest(root->right, k);
}

// Function to find kth largest element in the BST
int findKthLargest(Node *root, int k)
{
    static int count = 0;
    if (root == NULL)
    {
        return -1;
    }
    int right = findKthLargest(root->right, k);
    if (right != -1)
    {
        return right;
    }
    count++;
    if (count == k)
    {
        return root->data;
    }
    return findKthLargest(root->left, k);
}


// Main function
int main()
{
    Node *root = NULL;
    int opt = 0;
    cout<<"Binary Search Tree"<<endl;

    while(opt != 9){
        cout<<"Choose an option:"<<endl;
        cout<<"1. Insert a node"<<endl;
        cout<<"2. View the tree"<<endl;
        cout<<"3. Delete a node"<<endl;
        cout<<"4. Search a node"<<endl;
        cout<<"5. Find the minimum value"<<endl;
        cout<<"6. Find the maximum value"<<endl;
        cout<<"7. Find the kth smallest value"<<endl;
        cout<<"8. Find the kth largest value"<<endl;
        cout<<"9. Exit"<<endl;
        cout<<"Enter your option: ";
        cin>>opt;
        cout<<endl;

        switch(opt){
            case 1:
                int data;
                cout<<"Enter the data to be inserted: ";
                cin>>data;
                root = insertNode(root, data);
                cout<<data<<" inserted successfully"<<endl;
                break;
            case 2:
                cout<<"The tree is: ";
                display(root);
                cout<<endl;
                break;
            case 3:
                cout<<"Enter the data to be deleted: ";
                cin>>data;
                root = deleteNode(root, data);
                cout<<data<<" deleted successfully"<<endl;
                break;
            case 4:
                cout<<"Enter the data to be searched: ";
                cin>>data;
                if (searchNode(root, data))
                {
                    cout << data << " found in the tree" << endl;
                }
                else
                {
                    cout << data << " not found in the tree" << endl;
                }
                break;
            case 5:
                cout<<"The minimum value in the tree is: "<<findMin(root)<<endl;
                break;
            case 6:
                cout<<"The maximum value in the tree is: "<<findMax(root)<<endl;
                break;
            case 7:
                int k;
                cout<<"Enter the value of k: ";
                cin>>k;
                cout<<"The "<<k<<"th smallest value in the tree is: "<<findKthSmallest(root, k)<<endl;
                break;
            case 8:
                cout<<"Enter the value of k: ";
                cin>>k;
                cout<<"The "<<k<<"th largest value in the tree is: "<<findKthLargest(root, k)<<endl;
                break;
            case 9:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid option"<<endl;
        }
        cout<<endl;

    }
}