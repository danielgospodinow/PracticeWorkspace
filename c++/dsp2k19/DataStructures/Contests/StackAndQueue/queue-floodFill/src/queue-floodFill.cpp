#include <vector>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Node {
    int row;
    int col;
    char character;

    Node(int _row, int _col, char _character) :
            row(_row), col(_col), character(_character) {

    }
};

char getElement(char **matrix, int rowSize, int colSize, int row, int col) {
    return (row < 0 || col < 0 || row >= rowSize || col >= colSize) ? ('\0') : (matrix[row][col]);
}

vector<Node> getChildren(char **matrix, int rowSize, int colSize, Node node) {
    vector<Node> children;

    if (getElement(matrix, rowSize, colSize, node.row + 1, node.col) != '\0') {
        children.push_back(Node(node.row + 1, node.col, matrix[node.row + 1][node.col]));
    }
    if (getElement(matrix, rowSize, colSize, node.row - 1, node.col) != '\0') {
        children.push_back(Node(node.row - 1, node.col, matrix[node.row - 1][node.col]));
    }
    if (getElement(matrix, rowSize, colSize, node.row, node.col + 1) != '\0') {
        children.push_back(Node(node.row, node.col + 1, matrix[node.row][node.col + 1]));
    }
    if (getElement(matrix, rowSize, colSize, node.row, node.col - 1) != '\0') {
        children.push_back(Node(node.row, node.col - 1, matrix[node.row][node.col - 1]));
    }

    return children;
}

void repaintMatrix(char **matrix, int rowSize, int colSize, int row, int col, char newChar) {
    if (row < 0 || col < 0 || row >= rowSize || col >= colSize) {
        return;
    }

    queue<Node> nodes;
    nodes.push(Node(row, col, getElement(matrix, rowSize, colSize, row, col)));

    while (!nodes.empty()) {
        Node currentNode = nodes.front();
        nodes.pop();

        matrix[currentNode.row][currentNode.col] = newChar;

        vector<Node> children = getChildren(matrix, rowSize, colSize, currentNode);
        for (Node const &child: children) {
            if (child.character == currentNode.character) {
                nodes.push(child);
            }
        }
    }
}

int main() {
    int rows;
    cin >> rows;
    cin.get();

    int cols;
    cin >> cols;
    cin.get();

    int startX;
    cin >> startX;
    cin.get();

    int startY;
    cin >> startY;
    cin.get();

    char color;
    cin >> color;
    cin.get();

    char **matrix = new char *[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new char[cols];
    }

    for (int i = 0; i < rows; ++i) {
        string s;
        getline(cin, s);

        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = s[j];
        }
    }

    repaintMatrix(matrix, rows, cols, startX, startY, color);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
