#include "../../include/binary_tree.h"
#include <assert.h>

void test_creation() {
    printf("\nTesting node creation...\n");
    Node* node = createNode(5);
    assert(node != NULL);
    assert(node->data == 5);
    assert(node->left == NULL);
    assert(node->right == NULL);
    free(node);
    printf("✓ Node creation test passed\n");
}

void test_tree_building() {
    printf("\nTesting tree building...\n");
    int arr[] = {1, 2, 3, 4, 5};
    Node* root = buildTree(arr, 5);
    assert(root != NULL);
    assert(root->data == 1);
    assert(root->left->data == 2);
    assert(root->right->data == 3);
    freeTree(root);
    printf("✓ Tree building test passed\n");
}

void test_node_finding() {
    printf("\nTesting node finding...\n");
    int arr[] = {1, 2, 3, 4, 5};
    Node* root = buildTree(arr, 5);
    Node* found = findNode(root, 3);
    assert(found != NULL);
    assert(found->data == 3);
    found = findNode(root, 10);
    assert(found == NULL);
    freeTree(root);
    printf("✓ Node finding test passed\n");
}

void test_leaf_nodes() {
    printf("\nTesting leaf nodes identification...\n");
    int arr[] = {1, 2, 3, 4, 5};
    Node* root = buildTree(arr, 5);
    printf("Leaf nodes (should be 4, 5): ");
    getLeafNodes(root);
    printf("\n");
    freeTree(root);
    printf("✓ Leaf nodes test passed (verify output manually)\n");
}

void test_sibling_finding() {
    printf("\nTesting sibling finding...\n");
    int arr[] = {1, 2, 3};
    Node* root = buildTree(arr, 3);
    Node* node = root->left;  // node with value 2
    Node* sibling = getSibling(node);
    assert(sibling != NULL);
    assert(sibling->data == 3);
    freeTree(root);
    printf("✓ Sibling finding test passed\n");
}

void test_grandchildren() {
    printf("\nTesting grandchildren finding...\n");
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    Node* root = buildTree(arr, 7);
    printf("Grandchildren of root (should be 4, 5, 6, 7): ");
    getGrandchildren(root);
    printf("\n");
    freeTree(root);
    printf("✓ Grandchildren test passed (verify output manually)\n");
}

int main() {
    printf("Starting Binary Tree Test Suite\n");
    printf("===============================\n");

    test_creation();
    test_tree_building();
    test_node_finding();
    test_leaf_nodes();
    test_sibling_finding();
    test_grandchildren();

    printf("\nAll tests completed successfully!\n");
    return 0;
}
