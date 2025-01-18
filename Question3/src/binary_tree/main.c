#include "../../include/binary_tree.h"

int main() {
    int arr[20] = {50, 30, 70, 20, 40, 60, 80, 15, 25, 35, 45, 55, 65, 75, 85,
                   10, 22, 33, 44, 90};
    int choice, value;
    Node* root = buildTree(arr, 20);

    while (1) {
        printf("\nBinary Tree Operations\n");
        printf("=====================\n");
        printf("1. Display Tree\n");
        printf("2. Get Root Node\n");
        printf("3. Get Leaf Nodes\n");
        printf("4. Find Siblings of a Node\n");
        printf("5. Find Parent of a Node\n");
        printf("6. Find Grandchildren of a Node\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nTree Structure:\n");
                displayTree(root, 0);
                break;

            case 2:
                if (root)
                    printf("Root node: %d\n", root->data);
                break;

            case 3:
                printf("Leaf nodes: ");
                getLeafNodes(root);
                printf("\n");
                break;

            case 4: {
                printf("Enter node value to find siblings: ");
                scanf("%d", &value);
                Node* node = findNode(root, value);
                if (node) {
                    Node* sibling = getSibling(node);
                    if (sibling)
                        printf("Sibling: %d\n", sibling->data);
                    else
                        printf("No sibling found\n");
                } else {
                    printf("Node not found\n");
                }
                break;
            }

            case 5: {
                printf("Enter node value to find parent: ");
                scanf("%d", &value);
                Node* node = findNode(root, value);
                if (node && node->parent)
                    printf("Parent: %d\n", node->parent->data);
                else
                    printf("No parent found\n");
                break;
            }

            case 6: {
                printf("Enter node value to find grandchildren: ");
                scanf("%d", &value);
                Node* node = findNode(root, value);
                if (node) {
                    printf("Grandchildren: ");
                    getGrandchildren(node);
                    printf("\n");
                } else {
                    printf("Node not found\n");
                }
                break;
            }

            case 7:
                freeTree(root);
                printf("Thank you!\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
