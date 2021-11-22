

struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node() : data(NULL), next(NULL), prev(NULL) {};
    Node(int _data) : data(_data), next(NULL), prev(NULL) {};
    Node(int _data, Node* _next, Node* _prev) : data(_data), next(_next), prev(_prev) {};
};

struct List 
{
    List() : head(NULL), tail(NULL) {};

    Node* head;
    Node* tail;

    void addHead( int val);
    void addTail( int val);
    void outListHead();
    void outListTail();
    int countNodeHead();
    int countNodeTail();
    Node* findPosHead(int pos);
    Node* findDataHead(int data);
    Node* findPosTail(int pos);
    Node* findDataTail(int data);
    void insertPosHead(int pos, int val);
    void insertPosTail(int pos, int val);
    Node* removeHead();
    Node* removeTail();
    void remove(int pos);
    bool isEmpty();
    void removeAll();
};

