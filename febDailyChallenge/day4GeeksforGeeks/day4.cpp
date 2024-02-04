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

    ListNode* l1 = createLinkedList(arr1, sizeof(arr1) / sizeof(arr1[0]));
    ListNode* l2 = createLinkedList(arr2, sizeof(arr2) / sizeof(arr2[0]));

    ListNode* result = subtractLinkedLists(l1, l2);

    cout << "Result: ";
    printLinkedList(result);

    return 0;
}