#include "binary_trees.h"

/**
 * binary_tree_balance - measure the balance of the binary @tree
 *
 * @tree: tree to measure
 *
 * Return: balance of tree; negative value is heavier on the right,
 * positive value is heavier on the left.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int balance_factor, left, right;

	left = balance_height(tree->left);
	right = balance_height(tree->right);
	balance_factor = left - right;
	return (balance_factor);
}

/**
 * balance_height - find the height of a binary tree
 *
 * @tree: tree whose height will be measured
 *
 * Return: integer height of tree; 0 if tree is NULL
 */
int balance_height(const binary_tree_t *tree)
{
	int height1, height2, height;

	height = -1;
	if (tree != NULL)
	{
		height1 = balance_height(tree->left);
		height2 = balance_height(tree->right);
		if (height1 > height2)
			height = height1 + 1;
		else
			height = height2 + 1;
	}
	return (height);
}
