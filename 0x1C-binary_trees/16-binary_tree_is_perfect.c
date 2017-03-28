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
	else if (check_if_perfect(tree) != -1)
		return (1);
	return (0);
}

/**
 * check_if_perfect - recurse through @tree to check for equal height
 */
int check_if_perfect(const binary_tree_t *tree)
{
	int lheight;

	if (tree == NULL)
		return (0);
	else
	{
		lheight = check_if_perfect(tree->left);
		if (lheight != -1 && check_if_perfect(tree->right) == lheight)
			return (lheight + 1);
		else
			return (-1);
	}
}
