using namespace std;

#define NULL 0

struct node {
  public:
    int key;
    char type;
    struct node *next;
    struct node *prev;
};

class dList {
  public:
    dList();
    dList(int[], char[], int);
    void addFront(int, char);
    void addBack(int, char);
    node *search(int);
    void find(char);
    void moveFront(node*);
    void moveBack(node*);
    void out(int, char = 'f');
    void sort();
    node* createNode(int key, char type);
    node* remove(node *);
  private:
    //node* createNode(int key, char type);
    //node* remove(node *);

    node *head;
    node *tail;
    int size;
};

dList::dList() {
  head->key = NULL;
  head->type = NULL;
  head->next = tail;
  tail->key = NULL;
  tail->type = NULL;
  tail->prev = head;
  size = 0;
}

dList::dList(int intArr[], char charArr[], int length) {
  for(int i = 0; i < length; ++i) {
    addBack(intArr[i], charArr[i]);
  }
}

// Insert passed elements into new node at list of list
void addFront(int key, char type) {
  node *temp = head->next;
  node *newNode = createNode(key, type);
  head->next = newNode;
  temp->prev = newNode;
  newNode->prev = head;
  newNode->next = temp;
  return;
}

// Insert passed elements into new node at back of list
void addBack(int key, char type) {
  node *temp = tail->prev;
  node *newNode = createNode(key, type);
  temp->next = newNode;
  newNode->prev = temp;
  newNode->next = tail;
  tail->prev = newNode;
  return;
}

// Search the list for occurence of the key provided.
node *search(int key) {
  node *temp = head;
  while(temp->next) {
    if (temp->key == key) return temp;
    temp = temp->next;
  }
  std::cout << "Key not found";
  return NULL;
}

// Search the list and output all nodes where the provided char occurs.
void find(char type) {
  node *temp = head;
  while(temp->next) {
    if (temp->type == type) {
      std::cout << temp->key << " ";
    }
    temp = temp->next;
  }
  return;
}

// Move the node provided to the front of the list
void moveFront(node *target) {
  addFront(remove(*target))
  return;
}

// Move the node provided to the back of the list
void moveBack(node *target) {
  addBack(remove(*target));
  return;
}

// Print n nodes into the list backwards or forwards depending on parameter 'dir'
void out(int n, char dir = 'f') {
  node *list = head;
  if (dir == 'b') {
    while(list->next) {
      list = list->next;
    }
    for (int i = 0; i < n; ++i) {
      std::cout << list->key << " " << list->type << std::endl;
      list = list->prev;
    }
  }
  for (int i = 0; i < n; ++i) {                       // Defualt case
      std::cout << list->key << " " << list->type << std::endl;
      list = list->next;
  return;
}

// Some O(nlogn) sort algo I haven't written yet
// void sort() {
//   int pInd, cInd;
//   // Put elements in reverse-order priority queue
//   for (int i = 1; i < arr.length; ++i) {
//     pInd = (i - 1)/2;
//     cInd = i;
//   // add to bottom and upheap as needed
//     while (arr[cInd] < arr[pInd]) {
//       swap(arr, cInd, pInd);
//       cInd = pInd;
//       pInd = (pInd-1)/2;
//     }
//   }

//   int rInd, lInd;
//   for(int j = arr.length - 1; j >= 0l --j) {
//     swap(arr, 0, j);
//     pInd = 0;
//     lInd = pInd * 2 + 1;
//   }

//   while(lInd < j) {
//     if((lInd + 1 < j && arr[pInd]))
//   }
// }

// helper function to create nodes
/*node *createNode(int key, char type) {
  node temp* = new(node);
  temp->key = key;
  temp->type = type;
  ++size;
  return temp;
}

node *remove(node *target) {
  target->prev->next = target->next;
  target->next->prev = target->prev;
  target->next = NULL;
  target->prev = NULL;
  return target;
}*/
}
