#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Define the TreeNode structure
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    // Function to perform preorder traversal
    // of a binary tree iteratively
    vector<int> preorderTraversal(TreeNode *root)
    {
        // Initialize vector to store
        // the preorder traversal result
        vector<int> preorder;

        // If the root is null, return
        // an empty traversal result
        if (root == nullptr)
        {
            return preorder;
        }

        // Create a stack to store
        // nodes during traversal
        stack<TreeNode *> st;
        // Push the root node
        // onto the stack
        st.push(root);

        // Perform iterative preorder traversal
        while (!st.empty())
        {
            // Get the current node
            // from the top of the stack
            root = st.top();
            // Remove the node
            // from the stack
            st.pop();

            // Add the node's value to
            // the preorder traversal result
            preorder.push_back(root->val);

            // Push the right child
            // onto the stack if exists
            if (root->right != nullptr)
            {
                st.push(root->right);
            }

            // Push the left child onto
            // the stack if exists
            if (root->left != nullptr)
            {
                st.push(root->left);
            }
        }

        // Return the preorder
        // traversal result
        return preorder;
    }
    // Function to perform preorder traversal of a binary tree
    vector<int> ppreorderTraversal(TreeNode *root)
    {
        // Vector to store the values of nodes in preorder
        vector<int> preorder;

        // If the root is NULL, return an empty vector
        if (root == NULL)
            return preorder;

        // Stack to hold nodes for traversal
        stack<TreeNode *> st;

        // Start with the root node
        TreeNode *node = root;

        // Push the root node onto the stack
        st.push(node);

        // Continue until there are no more nodes in the stack
        while (!st.empty())
        {
            // Get the top node from the stack
            node = st.top();

            // Add the value of the current node to the preorder vector
            preorder.push_back(node->val);

            // Remove the top node from the stack
            st.pop();

            // If the right child exists, push it onto the stack
            if (node->right != nullptr)
                st.push(node->right);

            // If the left child exists, push it onto the stack
            if (node->left != nullptr)
                st.push(node->left);
        }

        // Return the vector containing the preorder traversal
        return preorder;
    }
};

int main()
{
    // Creating a binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Initializing the Solution class
    Solution sol;

    // Getting the preorder traversal  using the recursive approach
    vector<int> result = sol.preorderTraversal(root);
    // Getting the preorder treversal using the iterative method
    vector<int> result1 = sol.ppreorderTraversal(root);

    // Displaying the preorder traversal result
    cout << "Preorder Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;
    cout << "Recursive Approach" << endl;
    for (int val : result1)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
