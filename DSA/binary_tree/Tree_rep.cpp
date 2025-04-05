#include <iostream>

// Structure definition for
// a node in a binary tree
struct Node
{
    // Defining the value of
    // the node (integer data)
    int data;
    // Reference pointer to
    // the left child node
    Node *left;
    // Reference pointer to
    // the right child node
    Node *right;

    // Method to initialize
    // the node with a value
    Node(int val)
    {
        // Set the value of the
        // node to the passed integer
        data = val;
        // Initialize left and
        // r ight pointers as NULL
        left = right = NULL;
    }
};
//Differnet way of wrting the same picee of code
//     struct TreeNode
//     {
//         int val;
//         TreeNode *left;
//         TreeNode *right;
//  Constructor for the TreeNode class
// TreeNode(int x) 
// // Member initializer list
// : val(x),          // Initialize the 'val' member with the value of 'x'
//   left(nullptr),   // Initialize the 'left' child pointer to nullptr (no left child)
//   right(nullptr)   // Initialize the 'right' child pointer to nullptr (no right child)
//  {
//  } // also can be written like this
//     };

    int main()
    {
        // Creating a new node for the root of the
        // binary tree using dynamic allocation
        Node *root = new Node(1);
        // Creating left and right child
        // nodes for the root node
        root->left = new Node(2);
        root->right = new Node(3);
        // Creating a right child node for
        // the left child node of the root
        root->left->right = new Node(5);
    }
