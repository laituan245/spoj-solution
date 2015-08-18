// DICT - Search in the dictionary!
// http://www.spoj.com/problems/DICT/
// laituanksa245

#include <string>
#include <iostream>
using namespace std;

int totalNbFound;

struct trieNode {
  string dataStr;
  bool isLeafNode;
  trieNode * children[27];
};

trieNode * newInternalNode () {
  trieNode * tempPtr = new trieNode;
  tempPtr->isLeafNode = false;
  for (int i = 0; i < 27; i++)
    tempPtr->children[i] = NULL;
  return tempPtr;
}

trieNode * newLeafNode (string tmpStr) {
  trieNode * tempPtr = new trieNode;
  tempPtr->dataStr = tmpStr;
  tempPtr->isLeafNode = true;
  for (int i = 0; i < 27; i++)
    tempPtr->children[i] = NULL;
  return tempPtr;
}


void addToTrie (trieNode ** root, string newStr, int n) {
  if (*root == NULL) {
    *root = newLeafNode(newStr);
    return;
  }
  int tempInt = 26;
  if (n < newStr.length())
    tempInt = ((int) newStr[n]) - 97;
  if ((*root)->isLeafNode == false) {
    if ((*root)->children[tempInt] == NULL)
      (*root)->children[tempInt] = newLeafNode(newStr);
    else
      addToTrie(&((*root)->children[tempInt]), newStr, n+1);
    return;
  }
  else {
    if ((*root)->dataStr == newStr)
      return;
    string tempStr = (*root)->dataStr;
    (*root)->isLeafNode = false;
    (*root)->dataStr = "";
    trieNode * tempNode = (*root);
    int tempIndex = n;
    while (tempIndex < tempStr.length() && tempIndex < newStr.length() && tempStr[tempIndex] == newStr[tempIndex]) {
      tempInt = ((int) newStr[tempIndex]) - 97;
      tempNode->children[tempInt] = newInternalNode();
      tempNode = tempNode->children[tempInt];
      tempIndex++;
    }

    if (tempIndex < newStr.length()) {
      tempInt = ((int) newStr[tempIndex]) - 97;
      tempNode->children[tempInt] = newLeafNode(newStr);
    }
    else
      tempNode->children[26] = newLeafNode(newStr);

    if (tempIndex < tempStr.length()) {
      tempInt = ((int) tempStr[tempIndex]) - 97;
      tempNode->children[tempInt] = newLeafNode(tempStr);
    }
    else
      tempNode->children[26] = newLeafNode(tempStr);

  }
}

void findAll (trieNode* root, string key, int n) {
  if (root == NULL)
    return;
  if (root->isLeafNode) {
    if (n < key.length()) {
      if (root->dataStr != key && root->dataStr.length() > key.length())
      {
        bool isPrefix = true;
        for (int j = n; j < key.length(); j++) {
          if (key[j] != (root->dataStr)[j]) {
            isPrefix = false;
            break;
          }
        }
        if (isPrefix) {
          cout << root->dataStr << "\n";
          totalNbFound ++;
        }
      }
    }
    else {
      if (root->dataStr != key) {
        cout << root->dataStr << "\n";
        totalNbFound ++;
      }
    }
    return;
  }
  else {
    if (n < key.length ()) {
      int tempInt = ((int) key[n]) - 97;
      findAll (root->children[tempInt], key, n+1);
    }
    else {
      findAll (root->children[26], key, n + 1);
      for (int i = 0; i < 26; i++)
        findAll (root->children[i], key, n + 1);
    }
  }

}

int main () {
  int n, k;
  string tempStr;
  trieNode * root = NULL;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tempStr;
    addToTrie (&root, tempStr, 0);
  }

  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> tempStr;
    cout << "Case #" << (i+1) << ":\n";
    totalNbFound = 0;
    findAll(root, tempStr, 0);
    if (totalNbFound == 0)
      cout << "No match.\n";
  }

}
