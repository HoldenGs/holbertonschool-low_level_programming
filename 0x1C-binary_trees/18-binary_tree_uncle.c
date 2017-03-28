#include "binary_trees.h"

/**
 * binary_tree_uncle - find the uncle of a @node
 *
 * @node: node to find the uncle for
 *
 * Return: pointer to @node's uncle, or NULL if there is no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node && node->parent && node->parent->parent)
	{
		if (node->parent->parent->left == node->parent)
		{
			if (node->parent->parent->right != NULL)
				return (node->parent->parent->right);
		}
		else if (node->parent->parent->left != NULL)
			return (node->parent->parent->left);

	}
	return (NULL);
}
