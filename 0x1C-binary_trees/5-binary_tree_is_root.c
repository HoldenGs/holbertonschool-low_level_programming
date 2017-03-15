#include "binary_trees.h"

/**
 * binary_tree_is_root - check if @node is a root node
 *
 * @node: node to check
 *
 * Return: 1 if @node is root, 0 if @node is not root
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node != NULL)
		if (node->parent == NULL)
			return (1);
	return (0);
}
