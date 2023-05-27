#include <iostream>
#include <cstdlib>
#include <ctime>
#include<fstream>
#include<string>
#include<windows.h>
using namespace std;
int Score_tree = 0;

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
        char answer;
        string newAnimal;
        string question;
        char newAnswer;
        if (curr->left == NULL && curr->right == NULL) {
            cout << "Is it a " << curr->data << "? (y/n): ";
            cin >> answer;
            if (answer == 'y') {
                cout << "I win!\n";
            }
            else {
                Score_tree = Score_tree + 1;
                cout << "I give up. What animal were you thinking of? ";

                getline(cin, newAnimal);
                cout << "What is a yes/no question that distinguishes a <  "
                    << curr->data << " > from a < " << newAnimal << " > ? ";
                //cin.ignore();
                getline(cin, question);
                cout << "If the animal were a < " << newAnimal << " > , what would the answer to that question be? ";
                cin >> newAnswer;
                Node* newQuestion = createLeaf(question);
                Node* newAnimalNode = createLeaf(newAnimal);
                Node* oldAnimalNode = createLeaf(curr->data);
                if (newAnswer == 'y') {
                    curr->data = question;
                    curr->right = newAnimalNode;
                    curr->left = oldAnimalNode;
                }
                else {
                    curr->data = question;
                    curr->left = newAnimalNode;
                    curr->right = oldAnimalNode;
                }
            }
        }
        else {
            cout << curr->data << " (y/n): ";
            char answer;
            cin >> answer;
            if (answer == 'y') {
                playGame(curr->right);
            }
            else {
                playGame(curr->left);
            }
        }
    }
    void built_tree()
    {
        Node* root = createLeaf("is it invertebrate ?");//لافقريات
        root->right = createLeaf("is it mollusks ?"); //رخويات
        root->right->right = createLeaf("Does it have 8 lesgs?"); //8 ارجل
        root->right->right->left = createLeaf("Mollusca"); // حلزونه 
        root->right->right->right = createLeaf("Octopus");//اخطبوط
        root->right->left = createLeaf("is it insects");// حشره
        root->right->left->right = createLeaf("is it can fly");
        root->right->left->right->right = createLeaf("butterfly");//فراشه
        root->right->left->right->left = createLeaf("Ant");// نمله
        root->right->left->left = createLeaf("True Crabs");// سرطان البحر 
        root->left = createLeaf("is it birds");
        root->left->right = createLeaf("can Talk ?");
        root->left->right->left = createLeaf("bird"); // عصفوره
        root->left->left = createLeaf("Is it mammals ?");// ثديات 
        root->left->left->right = createLeaf("Is it the fastest ?");
        root->left->left->right->right = createLeaf("Cheetah");// فهد
        root->left->left->right->left = createLeaf("Is it have hump ?"); // سنام 
        root->left->left->right->left->right = createLeaf("Camel");// جمل 
        root->left->left->right->left->left = createLeaf("Cow");//بقره 
        root->left->left->left = createLeaf("Bee");//نحله  



        char ch = 'y';
        while (ch == 'Y' || ch == 'y') {
            cout << "\n\t               //////////////////////////////////////////////////////////////////////////////                      " << endl;
            cout << "                                              Welcome to our game                                                              " << endl;
            cout << "\t               //////////////////////////////////////////////////////////////////////////////                      " << endl;

            displayAnimals(root);
            cout << "\nthis is the only animals available for now with every time you play it become more complex good luck \n" << endl;

            cout << "\n\nThink of an animal and I'll try to guess it.";
            cout << "\t~* your score *~ : " << Score_tree << endl;

            playGame(root);

            cout << "Do you want to play again? (Y/N): ";
            cin >> ch;
           
            system("cls");
        }
        cout << "Thanks for playing!\n";


    }



};
int main() 
{
    How_am_i game2;
    game2.built_tree();
	
}