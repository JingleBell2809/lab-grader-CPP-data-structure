#include <bits/stdc++.h>
using namespace std;
 

struct Node {
    string c;
    struct Node* next;
};
 
struct Node* newNode(string c)
{
    Node* temp = new Node;
    temp->c = c;
    temp->next = NULL;
    return temp;
};
 
void reverse_word(string& str)
{
    reverse(str.begin(), str.end());
}
 
void reverse(struct Node* head)
{
    struct Node* ptr = head;
 
    while (ptr != NULL) {
        reverse_word(ptr->c);
        ptr = ptr->next;
    }
}
 
void printList(struct Node* head)
{
    while (head != NULL) {
        cout << head->c << " ";
        head = head->next;
    }
}
 
int main()
{
    Node* head = newNode("Bell");
    head->next = newNode("Premkamon");
    head->next->next = newNode("Kaosawang");
 
    printList(head);
 
    reverse(head);
    cout<<endl;
 
    printList(head);
 
    return 0;
}
