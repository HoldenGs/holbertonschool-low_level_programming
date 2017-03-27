#include "binary_trees.h"

/**
 * binary_tree_depth - measure the depth of a node in a binary tree
 *
 * @node: node to measure
 *
 * Return: number of nodes deep into the tree the @node is, 0 if @node is NULL
 */
size_t binary_tree_depth(const binary_tree_t *node)
{
	size_t depth;

	depth = 0;
	if (node == NULL)
		return (depth);
	while (node != NULL && node->parent != NULL)
	{
		depth++;
		node = node->parent;
	}
	return (depth);
}
