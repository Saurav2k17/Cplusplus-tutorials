// Normal BST to Balanced BST
// Example:
/* Input:
          4
        /   \
       3     5
      /       \
     2         6 
    /           \
   1             7
Output:
       4
    /    \
   2      6
 /  \    /  \
1    3  5    7 
*/

// An Efficient Solution can construct Balanced BST in O(n) time with minimum possible height.
// Do inorder traversal of the given BST and store result in an array. This step takes O(n) time.
// Note that this array would be sorted as inorder traversal of BST always produces sorted sequence.
// Build a balanced BST from the above created sorted array using the recursive approach. 
// This step also takes O(n) time as we traverse every element exactly once and processing an element takes O(1) time.

#include <stdio.h>
#include <iostream> 
#include <vector> 
using namespace std;

/* A Binary Tree node */
struct Node 
{ 
	int data; 
	Node* left; 
	Node* right; 
}; 

/* Helper function that allocates a new node with the 
given data and NULL left and right pointers */
Node* newNode(int data) 
{ 
	Node* node = new Node;
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 

	return node; 
}

/* A function that constructs Balanced Binary Search Tree */
Node* buildTreeUtil(vector<Node*> nodes, int start, int end) 
{ 
	/* Base Case */
	if (start > end) 
	return NULL; 

	/* Get the middle element and make it root */
	int mid = (start + end)/2; 
	Node* root = nodes[mid]; 

	/* Recursively construct the left subtree and make it 
	left child of root */
	root->left = buildTreeUtil(nodes, start, mid-1); 

	/* Recursively construct the right subtree and make it 
	right child of root */
	root->right = buildTreeUtil(nodes, mid+1, end); 

	return root; 
} 


// This function traverses the skewed BST and
// stores its nodes pointers in vector nodes[]
void storeBSTNodes(Node* root, vector<Node*> *nodes)
{
	// Base case
	if (root == NULL)
	return;

	// Stores nodes pointers in Inorder (which is sorted order for BST)
	storeBSTNodes(root->left, nodes);
	nodes->push_back(root);
	storeBSTNodes(root->right, nodes);
}


// This function converts an unbalanced BST to a balanced BST
Node* buildTree(Node* root)
{
	// Stores nodes pointers of given BST in sorted order
	vector<Node*> nodes;
	storeBSTNodes(root, &nodes);

	// Constucts BST from nodes[]
	int n = nodes.size();
	return buildTreeUtil(nodes, 0, n-1);
}

/* A utility function to print preorder traversal of BST */
void preOrder(Node* node) 
{ 
	if (node != NULL) 
	{ 
		printf("%d ", node->data); 
		preOrder(node->left); 
		preOrder(node->right); 
	}
} 

/* Driver program to test above functions */
int main() 
{ 
	/* Constructing skewed BST */
	Node* root = newNode(4);
	root->left = newNode(3);
	root->left->left = newNode(2);
	root->left->left->left = newNode(1);
	root->right = newNode(5);
	root->right->right = newNode(6);
	root->right->right->right = newNode(7);
	//root->right->right->right->right = newNode(8);
	//root->right->right->right->right->right = newNode(9);

	printf("PreOrder Traversal of constructed skewed BST\n"); 
	preOrder(root); 
	printf("\n");

	/* Convert skewed BST to balanced BST */
	root = buildTree(root);
	printf("PreOrder Traversal of resulting balanced BST\n"); 
	preOrder(root); 
	printf("\n");
	return 0; 
} 

