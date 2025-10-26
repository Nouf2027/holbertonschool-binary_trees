#include "binary_trees.h"

/**
 * binary_tree_height - Measures height of a binary tree
 * @tree: Pointer to the root node
 * Return: Height or 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	return (1 + (left > right ? left : right));
}

/**
 * binary_tree_size - Measures size of a binary tree
 * @tree: Pointer to the root node
 * Return: Size or 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, expected_size, size, i;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree) - 1;
	expected_size = 1;
	for (i = 0; i <= height; i++)
		expected_size *= 2;
	expected_size -= 1;

	size = binary_tree_size(tree);

	return (size == expected_size);
}
