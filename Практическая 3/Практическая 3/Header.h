#ifndef Header_H
#define Header_H

struct Node
{
    int data;
    Node* next;
    Node* prev;
};
void addHead(Node*& head, Node*& tail, int val);
void addTail(Node* head, Node*& tail, int val);
void outListHead(Node* head);
void outListTail(Node* tail);
int countNodeHead(Node* head);
int countNodeTail(Node* tail);
Node* findPosHead(Node* head, int pos);
Node* findDataHead(Node* head, Node* tail, int data);
Node* findPosTail(Node* tail, int pos);
Node* findDataTail(Node* head, Node* tail, int data);
void insertPosHead(Node*& head, int pos, int val);
void insertPosTail(Node*& tail, int pos, int val);
Node* removeHead(Node*& head, Node* tail);
Node* removeTail(Node* head, Node*& tail);
void remove(Node*& head, Node*& tail, int pos);
bool isEmpty(Node* head);
void removeAll(Node*& head, Node*& tail);

#endif