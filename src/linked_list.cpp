#include "assignment/linked_list.hpp"

#include <utility> // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    if (size_ > 1) {
      Node *new_head;
      Node *prev = nullptr;
      Node *current = front_;
      Node *next = current->next;
      Node *temp;
      for (int i = 0; i < size_ - 1; i++) {
        temp = next->next;
        next->next = current;
        current->next = prev;
        prev = current;
        current = next;
        next = temp;
      }
      new_head = back_;
      back_ = front_;
      front_ = new_head;
    }
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    if (size_ > 1) {
      reverse_recursive_helper(front_->next, front_);
      Node* node1 = front_;
      Node* node2 = back_;
      front_ = node2;
      back_ = node1;
      back_->next = nullptr;
    }
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    if (curr->next != nullptr) {
      LinkedList::reverse_recursive_helper(curr->next, curr);
    }
    curr->next = prev;
  }

}  // namespace assignment
