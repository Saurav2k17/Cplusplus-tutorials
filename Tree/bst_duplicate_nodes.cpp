// BST that handles duplicates by storing count with every node
// Insert and Delete functions have been implemented 
#include <stdio.h> 
#include <stdlib.h> 

struct node 
{ 
	int key; 
	int count; 
	struct node *left, *right; 
}; 

// Utility function to create a new BST node 
struct node *newNode(int item) 
{ 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->key = item; 
	temp->count = 1; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// Utility function to do inorder traversal of BST 
void inorder(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		inorder(root->left); 
		printf("%d(%d) ", root->key, root->count); 
		inorder(root->right); 
	} 
} 

/* Utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key) 
{ 
	/* If the tree is empty, return a new node */
	if (node == NULL) 
		return newNode(key); 

	/* Otherwise, recur down the tree */
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key);
	else // If key already exists in BST, increment count rather than creating a new node
		node->count++; 

	/* return the (unchanged) node pointer */
	return node; 
} 


/* Given a binary search tree and a key, this function 
deletes the given key and returns the root of modified tree */
struct node* deleteNode(struct node* root, int key) 
{ 
	// Base case 
	if (root == NULL) 
		return root; 

    // If the key to be deleted is smaller than the 
    // root's key, then it lies in left subtree 
	if (key < root->key)
		root->left = deleteNode(root->left, key); 
    // If the key to be deleted is greater than the 
    // root's key, then it lies in right subtree 
	else if (key > root->key)
		root->right = deleteNode(root->right, key); 

	// We reach here when root is the node to be deleted
	else 
	{
		// If key is present more than once, simply decrement count and return 
		if (root->count > 1) 
		{ 
		   (root->count)--; 
		   return root; 
		} 

        // ElSE, delete the unique node 
		// If one of the children is empty 
		if (root->left == NULL) { 
			node* temp = root->right; 
			delete root; 
			return temp; 
		} 
		else if (root->right == NULL) { 
			node* temp = root->left; 
			delete root; 
			return temp; 
		} 

		// If both children exist 
		else { 

			node* succParent = root->right; 
		
			// Find inorder successor (need to find the smallest node in the right subtree of the root)
			node *succ = root->right; // succ is the node which will replace root's key
			while (succ->left != NULL) { 
				succParent = succ; 
				succ = succ->left; 
			} 

			if (succ == succParent) // when root->right subtree has no child on the left
				root->right = succ->right;
			 
			else 
			// when successor is left child of its parent, 
			// we can safely make successor's right child as the left child of its parent
				succParent->left = succ->right; 

			// Copy Successor Data to root 
			root->key = succ->key; 
			root->count = succ->count;
			// Delete Successor and return root 
			delete succ;		 
			return root; // we only substituted root's key with succ's key (root still points to the same location)
		}
	} 
} 

// Driver Program to test above functions 
int main() 
{ 
	/* Let us create following BST 
			12(3) 
		  /	     \ 
	   10(2)    20(1) 
	   /  \ 
	9(1) 11(2)
	*/
	struct node *root = NULL; 
	root = insert(root, 12); 
	insert(root, 10); 
	insert(root, 20); 
	insert(root, 9); 
	insert(root, 11); 
	insert(root, 10); 
//	insert(root, 12); 
//	insert(root, 12); 
	insert(root, 11); 

	printf("Inorder traversal of the given tree \n"); 
	inorder(root); 

	printf("\n---------"); 
	printf("\nDelete 20\n");
	printf("---------\n"); 
	root = deleteNode(root, 20); 
	printf("Inorder traversal of the modified tree \n"); 
	inorder(root); 

	printf("\n---------"); 
	printf("\nDelete 10\n"); 
	printf("---------\n"); 
	root = deleteNode(root, 10); 
	printf("Inorder traversal of the modified tree \n"); 
	inorder(root); 

	printf("\n---------"); 
	printf("\nDelete 12\n"); 
	printf("---------\n"); 
	root = deleteNode(root, 12); 
	printf("Inorder traversal of the modified tree \n"); 
	inorder(root); 
	
	printf("\n---------"); 
	printf("\nDelete 10\n"); 
	printf("---------\n"); 
	root = deleteNode(root, 10); 
	printf("Inorder traversal of the modified tree \n"); 
	inorder(root); 

	printf("\n");
	return 0; 
}

