

template<class T>
UnsortedList<T>::UnsortedList() {
    length = 0;
    head = nullptr;
}

template<class T>
void UnsortedList<T>::MakeEmpty() {
    length = 0;

    while(head != nullptr){
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

template<class T>
bool UnsortedList<T>::IsFull() const {
    return false;
}

template<class T>
int UnsortedList<T>::GetLength() const {
    return length;
}

template<class T>
bool UnsortedList<T>::Contains(T someItem) {
    Node* currN = head;
    while(currN -> next != nullptr){
        if(currN -> value = someItem){
            return true;
        }
        currN = currN -> next;
    }
    return false;
}

template<class T>
void UnsortedList<T>::AddItem(T item) {
    Node* node = new Node;
    node -> value = item;
    node -> next = head;
    head = node;
    length ++;
}

template<class T>
void UnsortedList<T>::DeleteItem(T item) {
    Node* currN = head;
    Node* prevN = nullptr;
    while(currN -> next != nullptr){
        if(currN -> value == item){
            if(prevN != nullptr){
                prevN -> next = currN -> next;
            }else{
                head = head->next;
            }
            delete currN;
            length--;
        }
        prevN = currN;
        currN = currN -> next;
    }
}

template<class T>
void UnsortedList<T>::ResetIterator() {
    it = head;
}

template<class T>
T UnsortedList<T>::GetNextItem() {
    T value = it->value;
    it = it->next;
    return value;
}
