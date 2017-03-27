#include "binary_trees.h"

/**
 * binary_tree_leaves - count the leaves of a binary @tree
 *
 * @tree: binary tree to count leaves on
 *
 * Return: number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves;

	leaves = 0;
	if (tree != NULL)
	{
		leaves += binary_tree_leaves(tree->right);
		leaves += binary_tree_leaves(tree->left);
		if (tree->left == NULL && tree->right == NULL)
			leaves++;
	}
	return (leaves);
}
