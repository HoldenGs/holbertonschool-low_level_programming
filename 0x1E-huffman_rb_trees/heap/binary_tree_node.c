#include "heap.h"

/**
 * binary_tree_node - add a node to a binary tree
 *
 * @parent: Parent node to attach to
 * @data: Data to put into node
 *
 * Return: new node
 */
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
	binary_tree_node_t *node;

	node = malloc(sizeof(binary_tree_node_t));
	if (!node)
		return (NULL);
	node->data = data;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
