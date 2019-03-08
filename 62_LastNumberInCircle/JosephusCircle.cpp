// cpp program to find last man standing
#include <algorithm>
#include <iostream>
using namespace std;

// structure for a node in circular linked list
struct Node
{
    int data;
    struct Node *next;
};

// to create a new node of circular linked list
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    return temp;
}

/* function to find the only number left 
   after one in every m-th node is removed
   in a circle of n nodes */
void getJosephusPosition(int n, int m)
{
    if (n < 1 || m < 1) {
        printf("Invalid param(s) n = %d, m = %d.\n", n, m);
        return;
    }
    // create a circular linked list of size n.
    Node* headPtr = newNode(0);
    Node* tailPtr = headPtr;
    for (int i = 1; i < n; i++)
    {
        tailPtr->next = newNode(i);
        tailPtr = tailPtr->next;
    }
    // connect last node to first
    tailPtr->next = headPtr;

    // while only one node is left in the linked list
    Node *pioneer = headPtr, *follower = tailPtr;
    while (pioneer->next != pioneer)
    {
        // find m-th node
        for (int cnt = 1; cnt < m; cnt++) {
            follower = pioneer;
            pioneer = pioneer->next;
        }

        // remove the m-th node
        follower->next = pioneer->next;
        pioneer = follower->next;
    }

    printf("Last node left standing (Josephus Position) is %d.\n", pioneer->data);
}

/* Driver program to test above functions */
int main(int argc, char* argv[])
{
    printf("62_LastNumberInCircle/JosephusCircle is running ...\n");

    // int n = 5, m = 1; // 4
    // int n = 5, m = 2; // 2
    int n = 5, m = 3; // 3
    // int n = 6, m = 6; // 3
    // int n = 6, m = 7; // 4
    // int n = 4000, m = 997; // 1027
    getJosephusPosition(n, m);

    return 0;
}
