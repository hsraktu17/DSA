#include<bits/stdc++.h>

using namespace std;

const long long unsigned int MOD = 1000000007;

struct Node {
    int data;
    struct Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

int size(Node* head){
    Node* curr = head;
    int sizer = 0;
    while(curr -> next !=  NULL){
        sizer++;
        curr = curr -> next;
    }
    return sizer;
}

long long unsigned int decimalValue(Node *head){
    // Your Code Here
    int sizer = size(head);
    long long unsigned int decimalValue = 0;
    while (head != nullptr) {
    decimalValue = (decimalValue * 2 + head->data) % MOD;
        head = head->next;
    }
    return decimalValue;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(1);
    
    cout << "Decimal value: " << decimalValue(head) << endl;

    // Free memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}