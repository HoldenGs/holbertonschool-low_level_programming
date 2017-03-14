#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 *
 * @tree: root node of binary tree
 *
 * Return: void
 */
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *current;

	current = tree;
	if (current == NULL)
		return;
	binary_tree_delete(current->right);
	binary_tree_delete(current->left);
	free(current);
}
