#include "binary_trees.h"

/**
 * binary_tree_is_perfect - check if a binary tree is perfect or not
 *
 * @tree: tree to check
 *
 * Return: 1 if perfect, 0 if not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (abs(binary_tree_balance(tree)) == 0 &&
	    binary_tree_is_full(tree))
		return (1);
	else
		return (0);
}

/**
 * binary_tree_is_full - check if a binary @tree is full or not
 *
 * @tree: tree to check
 *
 * Return: 1 if full, 0 if not
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->right && tree->left)
	{
		if (binary_tree_is_full(tree->left) &&
		    binary_tree_is_full(tree->right))
			return (1);
	}
	else if (tree->right == NULL && tree->left == NULL)
		return (1);
	return (0);
}

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

	if (tree == NULL)
		return (0);
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
