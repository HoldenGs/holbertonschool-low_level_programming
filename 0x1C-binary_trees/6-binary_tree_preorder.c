#include "binary_trees.h"

/**
 * binary_tree_preorder - traverse a binary tree from root to left and then
 * to right and call a function on each node
 *
 * @tree: tree to traverse
 * @func: function to call
 *
 * Return: void
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
