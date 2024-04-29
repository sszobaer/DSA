#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    int freq;
    Node *left, *right;
};

Node* createNode(char data, int freq, Node* left = nullptr, Node* right = nullptr) {
    return new Node{data, freq, left, right};
}

void generateCodes(Node* root, const string& code, unordered_map<char, string>& codes) {
    if (root == nullptr) return;
    if (!root->left && !root->right) {
        codes[root->data] = code;
        return;
    }
    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

void buildHuffmanTree(const unordered_map<char, int>& charFreq) {
    auto compare = [](Node* a, Node* b) { return a->freq > b->freq; };
    priority_queue<Node*, vector<Node*>, decltype(compare)> pq(compare);

    for (const auto& pair : charFreq) {
        pq.push(createNode(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        pq.push(createNode('\0', left->freq + right->freq, left, right));
    }

    Node* root = pq.top();

    unordered_map<char, string> codes;
    generateCodes(root, "", codes);

    cout << "Huffman Codes:\n";
    for (const auto& pair : codes) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

int main() {
    unordered_map<char, int> charFreq = {
       
    };

    buildHuffmanTree(charFreq);

    return 0;
}
