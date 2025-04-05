#include<bits/stdc++.h>
#include <vector>

using namespace std;

// Node structure for the binary tree
struct Node
{
    int data;
    Node *left;
    Node *right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to perform inorder traversal
// of the tree and store values in 'arr'
void inorder(Node *root, vector<int> &arr)
{
    // If the current node is NULL
    // (base case for recursion), return
    if (root == nullptr)
    {
        return;
    }
    // Recursively traverse the left subtree
    inorder(root->left, arr);
    // Push the current node's
    // value into the vector
    arr.push_back(root->data);
    // Recursively traverse
    // the right subtree
    inorder(root->right, arr);
}

// Function to initiate inorder traversal
// and return the resulting vector
vector<int> inOrder(Node *root)
{
    // Create an empty vector to
    // store inorder traversal values
    vector<int> arr;
    // Call the inorder traversal function
    inorder(root, arr);
    // Return the resulting vector
    // containing inorder traversal values
    return arr;
}
// #below is the iterative approach for tree
// Function to perform inorder traversal of a binary tree
vector<int> inorderTraversal(Node* root) {
    // Vector to store the values of nodes in inorder
    vector<int> inorderr;

    // If the root is nullptr, return an empty vector
    if (root == nullptr)
        return inorderr;

    // Stack to hold nodes for traversal
    stack<Node*> st;

    // Start with the root node
    Node* node = root;

    // Infinite loop to traverse the tree
    while (true) {
        // Traverse to the leftmost node
        if (node != nullptr) {
            // Push the current node onto the stack
            st.push(node);
            // Move to the left child
            node = node->left;
        } else {
            // If the stack is empty, we are done
            if (st.empty())
                break;

            // Get the top node from the stack
            node = st.top();
            // Remove the top node from the stack
            st.pop();

            // Add the value of the current node to the inorder vector
            inorderr.push_back(node->data);

            // Move to the right child of the current node
            node = node->right;
        }
    }

    // Return the vector containing the inorder traversal
    return inorderr;
}

// Main function
int main()
{
    // Creating a sample binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting inorder traversal
    vector<int> result = inOrder(root);
    //getting inordertraverssal through interative approach
    vector<int>result1= inorderTraversal(root);
    // Displaying the inorder traversal result
    cout << "Inorder Traversal: ";
    // Output each value in the
    // inorder traversal result
    cout<<"Recursive approach"<<endl;
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;
cout<<"Iterative approach"<<endl;
    for (int val : result1)
    {
        cout << val << " ";
    }
    return 0;
}
