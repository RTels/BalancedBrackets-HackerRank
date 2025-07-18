#include <iostream>
#include <string>

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T data) {
        this->data = data;
        next = nullptr;
    }
};

template <typename T>
class Stack {
    Node<T>* head;

public:
    Stack() { head = nullptr; }

    bool isEmpty() {
        return head == nullptr;
    }

    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    void pop() {
        if (isEmpty()) {
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    T peek() { return head->data; }


};

std::string isBalanced(std::string str) {
    Stack<char> stack;

    for (auto c : str) {
        switch (c) {
            case '(':
            case '{':
            case '[':
                stack.push(c);
                break;

            case ')':
                if (stack.isEmpty() || stack.peek() != '(') return "NO";
                stack.pop();
                break;

            case '}': 
                if (stack.isEmpty() || stack.peek() != '{') return "NO";
                stack.pop();
                break;

            case ']':
                if (stack.isEmpty() || stack.peek() != '[')  return "NO";
                stack.pop();
                break;    
        
        }

    }

    return stack.isEmpty() ? "YES" : "NO";

}


int main () {

    int n;
    std::cin >> n;
    while (n-- > 0) {
        std::string str;
        std::cin >> str;
        std::cout << isBalanced(str) << std::endl;
    }

    return 0;
}
