/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is
6                        <-- Copy this first
/ \
4  10                      <-- Copy this row next from 10 and next 4 ..
/ \   \
1   5   15                   <-- Order her is 15 ,5 ,1
\
17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void treeLevelRec(struct node *, int, int *,int *);
int max(int, int);
int height(struct node *root){
	if (root == NULL)
		return 0;
	else
	{
		return max(height(root->left), height(root->right)) + 1;
	}
}
int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

void treeLevelRec(struct node * node, int key, int *a,int *k)
{
	if (node == NULL)
		return;
	if (key == 1)
	{
		a[++*k] = node->data;
	}
	treeLevelRec(node->right, key - 1, a,k);
	treeLevelRec(node->left, key - 1, a,k);
}
int* BSTRighttoLeftRows(struct node* root)
{
	int *a, i,k=-1;
	int h = height(root);
	if (root == NULL)
		return NULL;
	a = (int *)malloc(((2 ^ h) - 1)*sizeof(int));
	for (i = 1; i <= h; i++){
		treeLevelRec(root, i, a,&k);
	}
	return a;
}
