// Tree Traversals (Inorder, Preorder and Postorder)
// Time Complexity is O(n)

#include <iostream> 
using namespace std;

/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct Node 
{ 
	int data; 
	struct Node* left, *right; 
	Node(int data) 
	{ 
		this->data = data; 
		left = right = NULL; 
	} 
}; 

/* Given a binary tree, print its nodes according to the 
"bottom-up" postorder (left, right, root) traversal. */
void printPostorder(struct Node* node) 
{ 
	if (node == NULL) 
		return; 

	// first recur on left subtree 
	printPostorder(node->left); 

	// then recur on right subtree 
	printPostorder(node->right); 

	// now deal with the node 
	cout << node->data << " "; 
} 

/* Given a binary tree, print its nodes in inorder (left, root, right) */
void printInorder(struct Node* node) 
{ 
	if (node == NULL) 
		return; 

	/* first recur on left child */
	printInorder(node->left); 

	/* then print the data of node */
	cout << node->data << " "; 

	/* now recur on right child */
	printInorder(node->right); 
} 

/* Given a binary tree, print its nodes in preorder (root, left, right) */
void printPreorder(struct Node* node) 
{ 
	if (node == NULL) 
		return; 

	/* first print data of node */
	cout << node->data << " "; 

	/* then recur on left sutree */
	printPreorder(node->left); 

	/* now recur on right subtree */
	printPreorder(node->right); 
} 

/* Driver program to test above functions */
int main() 
{

	/* Let us create the following binary tree 
			 1 
		    / \ 
		   2  3 
		  / \
	     4  5 
	*/
 
	struct Node *root = new Node(1); 
	root->left		  = new Node(2); 
	root->right		  = new Node(3); 
	root->left->left  = new Node(4); 
	root->left->right = new Node(5); 

	cout << "\nPreorder traversal of binary tree is \n"; 
	printPreorder(root); 

	cout << "\nInorder traversal of binary tree is \n"; 
	printInorder(root); 

	cout << "\nPostorder traversal of binary tree is \n"; 
	printPostorder(root); 

	cout << "\n";
	return 0; 
} 

