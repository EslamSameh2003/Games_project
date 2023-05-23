#include <iostream>
#include <queue>
#include <string>

using namespace std;

int score;

class How_am_i
{
public:

    struct Node {
        string data;
        Node* left;
        Node* right;
    };

    Node* createLeaf(string data) {
        Node* leaf = new Node;
        leaf->data = data;
        leaf->left = NULL;
        leaf->right = NULL;
        return leaf;
    }

    void displayAnimals(Node* curr) {
        if (curr == NULL) {
            return;
        }
        if (curr->left == NULL && curr->right == NULL) {
            cout << curr->data << endl;
        }
        else {
            displayAnimals(curr->left);
            displayAnimals(curr->right);
        }
    }
    void playGame(Node* curr) {

        if (curr->left == NULL && curr->right == NULL) {
            cout << "Is it a " << curr->data << "? (y/n): ";
            char answer;
            cin >> answer;
            if (answer == 'y') {
                cout << "I win!\n";
            }
            else {
                score = score + 1;
                cout << "I give up. What animal were you thinking of? ";
                string newAnimal;
                cin >> newAnimal;
                cout << "What is a yes/no question that distinguishes a "
                    << curr->data << " from a " << newAnimal << "? ";
                string question;
                cin.ignore();
                getline(cin, question);
                cout << "If the animal were a " << newAnimal << ", what would the answer to that question be? ";
                string newAnswer;
                getline(cin, newAnswer);
                Node* newQuestion = createLeaf(question);
                Node* newAnimalNode = createLeaf(newAnimal);
                Node* oldAnimalNode = createLeaf(curr->data);
                if (newAnswer == "y") {
                    curr->data = question;
                    curr->right = oldAnimalNode;
                    curr->left = newAnimalNode;
                }
                else {
                    curr->data = question;
                    curr->right = newAnimalNode;
                    curr->left = oldAnimalNode;
                }
            }
        }
        else {
            cout << curr->data << " (y/n): ";
            char answer;
            cin >> answer;
            if (answer == 'y') {
                playGame(curr->left);
            }
            else {
                playGame(curr->right);
            }
        }
    }

    void deleteTree(Node* root) {
        if (root == NULL) {
            return;
        }
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
    void built_tree()
    {
        Node* root = createLeaf("is it a mammal?");
        root->left = createLeaf("does it have fur?");
        root->right = createLeaf("Does it have feathers?");
        root->right->right = createLeaf("Does it fly?");
        root->right->right->right = createLeaf("birs");
        root->left->right = createLeaf("does it have four legs");
        root->left->right->right = createLeaf("lion");
        root->left->right->left = createLeaf("horse");
        root->left->left = createLeaf("does it live in water");
        root->left->left->left = createLeaf("fish");
        root->left->left->right = createLeaf("bear");
        char ch = 'y';
        while (ch == 'Y' || ch == 'y') {
            cout << "\n\t               //////////////////////////////////////////////////////////////////////////////                      " << endl;
            cout << "                                              Welcome to our game                                                              " << endl;
            cout << "\t               //////////////////////////////////////////////////////////////////////////////                      " << endl;

            displayAnimals(root);
            cout << "\nthis is the only animals available for now with every time you play it become more complex good luck \n" << endl;

            cout << "\n\nThink of an animal and I'll try to guess it.";
            cout << "~*your score*~ :" << score << endl;

            playGame(root);

            cout << "Do you want to play again? (Y/N): ";
            cin >> ch;
            // Clean up memory
            //deleteTree(root);
            system("cls");
        }
        cout << "Thanks for playing!\n";


    }


    

   


};


int main() {

    
   

   
    return 0;
}