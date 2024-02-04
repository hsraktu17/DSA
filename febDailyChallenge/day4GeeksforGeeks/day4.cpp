#include<bits/stdc++.h>

using namespace std;

struct LinkedList{
    int val;
    LinkedList* next;
    LinkedList(int x) : val(x) , next(nullptr){}
};

/*
LinkedList(int x){
    x = val;
    next = nullptr;
}

*/

LinkedList* createLinkedList(int arr[], int n) {
    LinkedList* head = nullptr;
    LinkedList* prev = nullptr;
    for (int i = 0; i < n; ++i) {
        LinkedList* newNode = new LinkedList(arr[i]);
        if (!head) {
            head = newNode;
        } else {
            prev->next = newNode;
        }
        prev = newNode;
    }
    return head;
}


LinkedList* reverseLinkedList(LinkedList* head) {
    LinkedList* prev = nullptr;
    LinkedList* curr = head;
    while (curr) {
        LinkedList* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

int compareLists(LinkedList* l1, LinkedList* l2) {
    while (l1 && l2) {
        if (l1->val != l2->val) {
            return l1->val - l2->val;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    if (!l1 && !l2) {
        return 0;
    } else if (!l1) {
        return -1;
    } else {
        return 1;
    }
}

LinkedList* subtractLinkedLists(LinkedList* l1, LinkedList* l2){

    int compare = compareLists(l1,l2);
    if(compare < 0){
        swap(l1,l2);
    }else if(compare == 0){
        return new LinkedList(0);
    }

    l1 = reverseLinkedList(l1);
    l2 = reverseLinkedList(l2);
    
    LinkedList* result = nullptr;
    LinkedList* prev = nullptr;

    int borrow = 0;

    while(l1 || l2){
        int val1 = l1 ? l1 ->val : 0;
        int val2 = l2 ? l2 ->val : 0;
        int diff = val1 - val2 - borrow;

        if(diff < 0){
            diff += 10;
            borrow = 1;
        }
        else{
            borrow = 0;
        }

        LinkedList* newNode = new LinkedList(diff);

        if(!result){
            result = newNode;
        }
        else{
            prev -> next = newNode;
        }

        prev = newNode;
        if(l1) l1 = l1 ->next;
        if(l2) l2 = l2 ->next;
    }
    LinkedList* temp = result;
    LinkedList* prevTemp = nullptr;
    while (temp && temp->val == 0) {
        prevTemp = temp;
        temp = temp->next;
        delete prevTemp;
    }

    return result ? result : new LinkedList(0);
     
}

void printLinkedList(LinkedList* head) {
    while (head) {
        cout << head->val;
        head = head->next;
    }
    cout << endl;
}

int main(){
    int arr1[] = {1, 0, 0}; // Represents number 100
    int arr2[] = {1, 2};    // Represents number 12

    LinkedList* l1 = createLinkedList(arr1, sizeof(arr1) / sizeof(arr1[0]));
    LinkedList* l2 = createLinkedList(arr2, sizeof(arr2) / sizeof(arr2[0]));

    LinkedList* result = subtractLinkedLists(l1, l2);

    cout << "Result: ";
    printLinkedList(result);

    return 0;
}