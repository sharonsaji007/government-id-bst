#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

// Structure for a BST node
struct Node
{
    char key[MAX];
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* createNode(char key[])
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    strcpy(newNode->key, key);
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert a key into BST
struct Node* insert(struct Node *root, char key[])
{
    if (root == NULL)
    {
        return createNode(key);
    }

    if (strcmp(key, root->key) < 0)
    {
        root->left = insert(root->left, key);
    }
    else if (strcmp(key, root->key) > 0)
    {
        root->right = insert(root->right, key);
    }

    return root;
}

// Inorder traversal
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%s ", root->key);
        inorder(root->right);
    }
}

// BST Search
int bstSearch(struct Node *root, char key[])
{
    int comparisons = 0;

    while (root != NULL)
    {
        comparisons++;

        if (strcmp(key, root->key) == 0)
        {
            return comparisons;
        }
        else if (strcmp(key, root->key) < 0)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    return comparisons;
}

// Linear Search
int linearSearch(char arr[][MAX], int n, char key[])
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (strcmp(arr[i], key) == 0)
        {
            return i + 1;
        }
    }

    return n;
}

int main()
{
    char ids[][MAX] =
    {
        "A102",
        "A25",
        "A7",
        "B100",
        "B12",
        "A120",
        "B3",
        "A45"
    };

    int n = 8;
    int i;

    struct Node *root = NULL;

    // Insert all identification numbers
    for (i = 0; i < n; i++)
    {
        root = insert(root, ids[i]);
    }

    // Display inorder traversal
    printf("Inorder Traversal:\n");
    inorder(root);

    printf("\n\n");

    // Search selected identification numbers
    char searchKeys[][MAX] =
    {
        "A102",
        "A120",
        "B3",
        "A45"
    };

    int searchCount = 4;

    printf("Search Comparison:\n");
    printf("ID\t\tBST Comparisons\tLinear Comparisons\n");

    for (i = 0; i < searchCount; i++)
    {
        int bstComp = bstSearch(root, searchKeys[i]);
        int linearComp = linearSearch(ids, n, searchKeys[i]);

        printf("%s\t\t%d\t\t%d\n",
               searchKeys[i], bstComp, linearComp);
    }

    return 0;
}