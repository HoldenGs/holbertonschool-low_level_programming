#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert a node on the left side of the parent
 *
 * @parent: parent of the node
 * @value: value of the node
 *
 * Return: pointer to the new node; NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node, *oldnode;

	if (parent == NULL)
		return (NULL);
	node = binary_tree_node(parent, value);
	node->n = value;
	node->parent = parent;
	oldnode = NULL;
	if (parent->left != NULL)
	{
		oldnode = parent->left;
		oldnode->parent = node;
	}
	parent->left = node;
	node->left = oldnode;
	node->right = NULL;
	return (node);
}
