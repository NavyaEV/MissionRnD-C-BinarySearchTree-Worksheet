/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
void inorderarray(struct node *, int *, int *);
void preorderarray(struct node *, int *, int *);
void postorderarray(struct node *, int *, int *);
void inorder(struct node *root, int *arr){
	int i = -1;
	inorderarray(root, arr, &i);
}
void inorderarray(struct node *root, int *arr,int *i){
	if (arr == NULL)
		return;
	if (root != NULL) {
		inorderarray(root->left, arr,i);
		arr[++*i] = root->data;
		inorderarray(root->right, arr,i);
	}
}
void preorder(struct node *root, int *arr){
	int j = -1;
	preorderarray(root, arr, &j);
}
void preorderarray(struct node *root, int *arr, int *j)
{
	if (arr == NULL)
		return;
	if (root != NULL) {
		arr[++*j] = root->data;
		preorderarray(root->left, arr,j);
		preorderarray(root->right, arr,j);
	}
}
void postorder(struct node *root, int *arr){
	int k = -1;
	postorderarray(root, arr, &k);
}
void postorderarray(struct node *root, int *arr, int *k)
{
	if (arr == NULL)
		return;
	if (root != NULL) {
		postorderarray(root->left, arr,k);
		postorderarray(root->right, arr,k);
		arr[++*k] = root->data;
	}
}