#include "binary_trees.h"

/**
 * binary_tree_sibling - find the sibling of a @node
 *
 * @node: node to find a sibling for
 *
 * Return: sibling node, or NULL if no sibling found
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node && node->parent)
	{
		if (node->parent->left == node)
		{
			if (node->parent->right != NULL)
				return (node->parent->right);
		}
		else if (node->parent->left != NULL)
			return (node->parent->left);

	}
	return (NULL);
}
