#include<iostream>
#include<vector>
#include<map>

struct Node{

    int val;
    Node* left;
    Node* right;

    Node():val{0},left{nullptr},right{nullptr}{}

    Node(int value):val{value},left{nullptr},right{nullptr}{}

};


class Tree{


public:
    Node* root;
    std::map<Node*, int> visited;

    std::vector<std::vector<int>> pathSum(Node* root, int targetSum) {

        std::vector<int> vecOfPath;
        int current = 0;
        std::vector<std::vector<int>> vecOfVecOfPath;
        dfs(root, 0, vecOfPath, vecOfVecOfPath, targetSum);
        return vecOfVecOfPath;
    }

    void dfs(Node* root, int curr, std::vector<int> vecOfPath, std::vector<std::vector<int>>& vecOfVecOfPath, int targetSum){

       if (root != nullptr) {
            curr += root->val;
            vecOfPath.push_back(root->val);

            if (root->left == nullptr && root->right == nullptr) {
                if (curr == targetSum) {
                    vecOfVecOfPath.push_back(vecOfPath);
                }
            }

            dfs(root->left, curr, vecOfPath, vecOfVecOfPath, targetSum);
            dfs(root->right, curr, vecOfPath, vecOfVecOfPath, targetSum);
            vecOfPath.pop_back();
        }
    }

// [[5,4,11,2],[5,8,4,5]]
    std::vector<Node*> nodes;

    Tree():root{nullptr}{}

    Node* init(int rootNode ){

        Node* root = new Node(rootNode);

        nodes.push_back(root);

        return root;

    }
    Node* appendNodes(Node* parent, int val, std::string branch){

        if(branch == "left") {
            
            parent->left = new Node(val);
            nodes.push_back(parent->left);
            return parent->left;
        }
        else if(branch == "right") {
            
            parent->right = new Node(val);
            nodes.push_back(parent->right);
            return parent->right;
        }

       return nullptr;

    }

    //print nodes using pre-order DFS
    void printTree(Node* tree){

        if(tree == NULL) return;

        printTree(tree->left);

        printTree(tree->right);

          std::cout<<"["<<tree->val<<"]"<<std::endl;

    }

    Node* search(Node* tree, int value){

        if(tree == NULL) return nullptr;
        if(tree->val == value) return tree;
        return search(tree->left, value);
        return search(tree->right, value);


    }



};


int main(){

    /**
     * 
     * 
     *                   5
                        / \
		                4  8
			           /  /\
                      11 13 4
                     / \    /\
		            7  2   3  1
     * 
     * 
     * 
     * 
     * 
    */

   Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(11);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(2);
    root->right->left = new Node(13);
    root->right->right = new Node(4);
    root->right->right->left = new Node(5);
    root->right->right->right = new Node(1);

    // root.printTree(root);

    Tree tree;
    std::vector<std::vector<int>> path;
    path = tree.pathSum(root, 22);

    for (const std::vector<int>& row : path) {
        for (int element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}




// #include <iostream>
// #include <vector>

// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;

//     TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
// };

// class Solution {
// public:
//     std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
//         std::vector<int> path;
//         std::vector<std::vector<int>> result;
//         dfs(root, targetSum, path, result);
//         return result;
//     }

// private:
//     void dfs(TreeNode* node, int targetSum, std::vector<int>& path, std::vector<std::vector<int>>& result) {
//         if (node == nullptr) {
//             return;
//         }

//         path.push_back(node->val);

//         if (node->left == nullptr && node->right == nullptr && targetSum == node->val) {
//             result.push_back(path);
//         }

//         dfs(node->left, targetSum - node->val, path, result);
//         dfs(node->right, targetSum - node->val, path, result);

//         path.pop_back();
//     }
// };

// int main() {
//     // Create the binary tree
//     TreeNode* root = new TreeNode(5);
//     root->left = new TreeNode(4);
//     root->right = new TreeNode(8);
//     root->left->left = new TreeNode(11);
//     root->left->left->left = new TreeNode(7);
//     root->left->left->right = new TreeNode(2);
//     root->right->left = new TreeNode(13);
//     root->right->right = new TreeNode(4);
//     root->right->right->left = new TreeNode(5);
//     root->right->right->right = new TreeNode(1);

//     int targetSum = 22;

//     Solution solution;
//     std::vector<std::vector<int>> paths = solution.pathSum(root, targetSum);

//     // Print the paths
//     std::cout << "Root-to-leaf paths with sum " << targetSum << ":\n";
//     for (const auto& path : paths) {
//         for (const auto& val : path) {
//             std::cout << val << " ";
//         }
//         std::cout << "\n";
//     }

//     // Clean up memory
//     // ...

//     return 0;
// }
