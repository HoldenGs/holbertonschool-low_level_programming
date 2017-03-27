#include "binary_trees.h"

/**
 * binary_tree_size - measure the total size of a binary @tree
 *
 * @tree: tree to measure
 *
 * Return: integer size of the total binary @tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t height1, height2, height;

	height = 0;
	if (tree != NULL)
	{
		height1 = binary_tree_size(tree->left);
		height2 = binary_tree_size(tree->right);
		height += height1;
		height += height2;
		height++;
	}
	return (height);

}
