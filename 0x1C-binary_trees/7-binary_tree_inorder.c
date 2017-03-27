#include "binary_trees.h"

/**
 * binary_tree_inorder - traverse a tree inorder, i.e. from left to right
 *
 * @tree: tree to traverse
 * @func: function to use on each node's value
 *
 * Return: void
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
