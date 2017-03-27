#include "binary_trees.h"

/**
 * binary_tree_nodes - count all the nodes with a child in a binary @tree
 *
 * @tree: tree to count nodes on
 *
 * Return: number of nodes with a child
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t height1, height2, height;

	height = 0;
	if (tree != NULL)
	{
		height1 = binary_tree_nodes(tree->left);
		height2 = binary_tree_nodes(tree->right);
		height += height1;
		height += height2;
		if (tree->right != NULL || tree->left != NULL)
			height++;
	}
	return (height);
}
