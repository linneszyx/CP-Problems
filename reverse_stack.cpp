void insertAtBottom(stack<int> &stack, int data) {
    if(stack.empty()) {
        stack.push(data);
        return;
    }
    int temp = stack.top();
    stack.pop();
    insertAtBottom(stack, data);
    stack.push(temp);
}
void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.empty()) return;
    int temp = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack, temp);

}