// Deleting a node in BST
// When we delete a node, three possibilities arise ::
// 1) Node to be deleted is leaf: Simply remove from the tree
// 2) Node to be deleted has only one child: Copy the child to the node and delete the child
// 3) Node to be deleted has two children: Find inorder successor of the node.
//    Copy contents of the inorder successor to the node and delete the inorder successor.
//    Inorder successor is needed only when right child is not empty. 
//    In this particular case, inorder successor can be obtained by
//    finding the node with minimum key on the right subtree of the node.

#include <iostream> 
using namespace std; 

struct Node { 
	int key; 
	struct Node *left, *right; 
}; 

// A utility function to create a new BST node 
Node* newNode(int item) 
{ 
	Node* temp = new Node; 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// A utility function to do inorder traversal of BST 
void inorder(Node* root) 
{ 
	if (root != NULL) { 
		inorder(root->left); 
		cout << root->key << " "; 
		inorder(root->right); 
	} 
} 

/* A utility function to insert a new node with given key in BST */
Node* insert(Node* node, int key) 
{ 
	/* If the tree is empty, return a new node */
	if (node == NULL) 
		return newNode(key); 

	/* Otherwise, recur down the tree */
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else
		node->right = insert(node->right, key); 

	/* return the (unchanged) node pointer */
	return node; 
} 

/* Given a binary search tree and a key, this function deletes the key 
and returns the new root */
Node* deleteNode(Node* root, int key) 
{ 
	// Base case 
	if (root == NULL) 
		return root; 

	// Recursive calls in order to find the node to be deleted 
	if (key < root->key) { 
		root->left = deleteNode(root->left, key); 
		return root; 
	} 
	else if (key > root->key) { 
		root->right = deleteNode(root->right, key); 
		return root; 
	} 

	// We reach here when root is the node to be deleted

	// If one of the children is empty 
	if (root->left == NULL) { 
		Node* temp = root->right; 
		delete root; 
		return temp; 
	} 
	else if (root->right == NULL) { 
		Node* temp = root->left; 
		delete root; 
		return temp; 
	} 

	// If both children exist 
	else { 

		Node* succParent = root->right; 
		
		// Find inorder successor 
		Node *succ = root->right; 
		while (succ->left != NULL) { 
			succParent = succ; 
			succ = succ->left; 
		} 

		// Delete successor. Since successor is always left child of its parent 
		// we can safely make successor's right child as the left child of its parent.
		succParent->left = succ->right; 

		// Copy Successor Data to root 
		root->key = succ->key; 

		// Delete Successor and return root 
		delete succ;		 
		return root; // only the key has changed
	} 
} 

// Driver Program to test above functions 
int main() 
{ 
	/* Let us create the following BST 
			 50 
		   /   \ 
		 30    70 
		/ \   / \ 
	   20 40 60 80 
	*/
	Node* root = NULL; 
	root = insert(root, 50); 
	insert(root, 30); 
	insert(root, 20); 
	insert(root, 40); 
	insert(root, 70); 
	insert(root, 60); 
	insert(root, 80); 

	cout << "Inorder traversal of the given tree \n"; 
	inorder(root); 

	cout << "\nDelete 20\n"; 
	root = deleteNode(root, 20); 
	cout << "Inorder traversal of the modified tree \n"; 
	inorder(root); 

	cout << "\nDelete 30\n"; 
	root = deleteNode(root, 30); 
	cout << "Inorder traversal of the modified tree \n"; 
	inorder(root); 

	cout << "\nDelete 50\n"; 
	root = deleteNode(root, 50); 
	cout << "Inorder traversal of the modified tree \n"; 
	inorder(root);
 
	cout << "\n";
	return 0; 
} 

