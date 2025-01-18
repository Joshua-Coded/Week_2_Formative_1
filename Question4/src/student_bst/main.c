#include "../../include/student_bst.h"

int main() {
    // Updated path to read from Question1's data folder
    BSTNode* root = buildBSTFromFile("../Question1/data/students.txt");
    if (root == NULL) {
        printf("Failed to load student data. Please check if file exists in Question1/data/students.txt\n");
        return 1;
    }

    char searchName[MAX_NAME];
    int choice;

    while (1) {
        printf("\nStudent BST Operations\n");
        printf("=====================\n");
        printf("1. Search by Last Name\n");
        printf("2. Display All Students (Sorted)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1:
                printf("Enter last name to search: ");
                fgets(searchName, MAX_NAME, stdin);
                searchName[strcspn(searchName, "\n")] = 0; // Remove newline
                
                BSTNode* result = searchByLastName(root, searchName);
                if (result) {
                    printf("Found: %s %s, Grade: %.2f\n", 
                           result->data.firstName, 
                           result->data.lastName, 
                           result->data.grade);
                } else {
                    printf("Student not found!\n");
                }
                break;

            case 2:
                printf("\nStudents in alphabetical order (by last name):\n");
                printf("==========================================\n");
                inorderTraversal(root);
                break;

            case 3:
                freeBST(root);
                printf("Thank you!\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
