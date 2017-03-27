#include "binary_trees.h"

/**
 * binary_tree_height - find the height of a binary tree
 *
 * @tree: tree whose height will be measured
 *
 * Return: integer height of tree; 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height1, height2, height;

	height = 0;
	if (tree != NULL)
	{
		height1 = binary_tree_height(tree->left);
		height2 = binary_tree_height(tree->right);
		if (height1 > height2)
			height += height1;
		else
			height += height2;
		if (tree->left != NULL || tree->right != NULL)
			height++;
	}
	return (height);
}
