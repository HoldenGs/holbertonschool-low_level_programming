#include "binary_trees.h"

/**
 * binary_tree_insert_right - insert a node on the right side of the parent
 *
 * @parent: parent of the node
 * @value: value of the node
 *
 * Return: pointer to the node; NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node, *oldnode;

	node = binary_tree_node(parent, value);
	node->n = value;
	node->parent = parent;
	oldnode = NULL;
	if (parent->right != NULL)
	{
		oldnode = parent->right;
		oldnode->parent = node;
	}
	parent->right = node;
	node->right = oldnode;
	node->left = NULL;
	return (node);
}
