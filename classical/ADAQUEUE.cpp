// ADAQUEUE - Ada and Queue
// http://www.spoj.com/problems/ADAQUEUE/

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

struct node {
  int data;
  node * prev;
  node * next;
};

node * make_node (int new_data) {
    node * new_node = new node();
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void insert_at_front(int new_data, node ** front, node ** back, int & nb_elements, int & direction) {
  node * new_node = make_node(new_data);
  if ((*front) == NULL && (*back) == NULL) {
    *front = new_node;
    *back = new_node;
    direction = +1;
  } else {
    if (direction > 0) {
      new_node->next = *front;
      (*front)->prev = new_node;
    } else {
      new_node->prev = *front;
      (*front)->next = new_node;
    }
    *front = new_node;
  }
  nb_elements++;
}

void insert_at_back(int new_data, node ** front, node ** back, int & nb_elements, int & direction) {
  node * new_node = make_node(new_data);
  if ((*front) == NULL && (*back) == NULL) {
    *front = new_node;
    *back = new_node;
    direction = +1;
  } else {
    if (direction > 0) {
      new_node->prev = *back;
      (*back)->next = new_node;
    } else {
      new_node->next = *back;
      (*back)->prev = new_node;
    }
    *back = new_node;
  }
  nb_elements++;
}

void remove_from_front(node ** front, node ** back, int & nb_elements, int & direction) {
  if (nb_elements == 1) {
    *front = NULL;
    *back = NULL;
    direction = +1;
  } else {
    node * tmp_node;
    if (direction > 0) {
      tmp_node = (*front)->next;
      tmp_node->prev = NULL;
      (*front) = tmp_node;
    } else {
      tmp_node = (*front)->prev;
      tmp_node->next = NULL;
      (*front) = tmp_node;
    }
  }
  nb_elements -= 1;
}

void remove_from_back(node ** front, node ** back, int & nb_elements, int & direction) {
  if (nb_elements == 1) {
    *front = NULL;
    *back = NULL;
    direction = +1;
  } else {
    node * tmp_node;
    if (direction > 0) {
      tmp_node = (*back)->prev;
      tmp_node->next = NULL;
      (*back) = tmp_node;
    } else {
      tmp_node = (*back)->next;
      tmp_node->prev = NULL;
      (*back) = tmp_node;
    }
  }
  nb_elements -= 1;
}

int main() {
  int q, n, nb_jobs = 0, direction = +1;
  node * front = NULL;
  node * back = NULL;
  string operation;
  cin >> q;
  for (int z = 0; z < q; z++) {
    operation = "";
    while (operation == "")
      cin >> operation;
    if (operation == "back") {
      if (nb_jobs == 0)
        cout << "No job for Ada?\n";
      else {
        cout << back->data << "\n";
        remove_from_back(&front, &back, nb_jobs, direction);
      }
    } else if (operation == "front") {
      if (nb_jobs == 0)
        cout << "No job for Ada?\n";
      else {
        cout << front->data << "\n";
        remove_from_front(&front, &back, nb_jobs, direction);
      }
    } else if (operation == "reverse") {
      node * tmp = front;
      front = back;
      back = tmp;
      direction = direction * (-1);
    } else if (operation == "push_back") {
      cin >> n;
      insert_at_back(n, &front, &back, nb_jobs, direction);
    } else if (operation == "toFront") {
      cin >> n;
      insert_at_front(n, &front, &back, nb_jobs, direction);
    }
  }

}
