#include "binary_trees.h"

/**
 * binary_tree_is_leaf - check if the node is a leaf
 *
 * @node: the node being checked
 *
 * Return: 1 if @node is a leaf, 0 if @node is not a leaf
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node->left == NULL && node->right == NULL)
		return (1);
	else
		return (0);
}
