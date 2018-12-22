// Print level order traversal of a binary tree using STL
// Level order traversal of a tree is breadth first traversal for the tree
// It is implemented here using queue
// For each node, first the node is visited and then it’s child nodes are put in a FIFO queue
// Time Complexity: O(n) where n is number of nodes in the binary tree

#include <iostream> 
#include <queue> 
using namespace std; 

// A Binary Tree Node 
struct Node 
{ 
	int data; 
	struct Node *left, *right; 
}; 

// Using queue to do level order traversal 
void printLevelOrder(Node *root) 
{ 
	// Base Case 
	if (root == NULL) return; 

	// Create an empty queue for level order traversal 
	queue<Node *> q; 

	// Enqueue Root
	q.push(root); 

	while (!q.empty()) // while queue is not empty 
	{ 
		// Print front of queue and remove it from queue 
		Node *node = q.front(); 
		cout << node->data << " "; 
		q.pop(); 

		/* Enqueue left child */
		if (node->left != NULL) 
			q.push(node->left); 

		/*Enqueue right child */
		if (node->right != NULL) 
			q.push(node->right); 
	} 
} 

// Utility function to create a new tree node 
Node* newNode(int data) 
{ 
	Node *temp = new Node; 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// Driver program to test above functions 
int main() 
{ 
	/* Let us create the following binary tree 
			  1 
		    /   \ 
		   2    3 
		  / \  / \
	     4  5 6  7
	*/
	Node *root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->left = newNode(6); 
	root->right->right = newNode(7); 

	cout << "Level Order traversal of binary tree is \n"; 
	printLevelOrder(root);
	cout << "\n";
	return 0; 
} 

