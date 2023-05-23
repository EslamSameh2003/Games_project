#include<iostream>
#include <stdlib.h>
#include <time.h>
#include<iomanip>
#include <string>
#include <fstream>
#include <iomanip>
#include <Windows.h>
using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
int first_num_in_box = 2;
int score = 2;
int Score_tree = 0;

int size1 = 0, size2 = 0, size3 = 0, size4 = 0;
// circular box
class game_2048
{
public:

    struct node_box
    {
        int data;
        node_box* next;
    };
    node_box* head = NULL;
    node_box* tail = NULL;
    void push_box(int value)
    {
        node_box* newnode_box = new node_box;
        if (head == NULL)
        {
            newnode_box->data = value;
            head = newnode_box;
            newnode_box->next = head;
            tail = newnode_box;
        }
        else
        {
            newnode_box->data = value;
            newnode_box->next = head;
            tail->next = newnode_box;
            tail = newnode_box;
        }
    }

    // circular end 
    void insert_num_to_box()
    {
        if (first_num_in_box < score)
        {
            first_num_in_box = score;
            push_box(score);
        }
    }


    int get_num_from_box()
    {
        node_box* num_of_box = head;
        srand(time(0));
        int x = rand() % 20;
        for (int i = 0; i < x; i++)
        {
            num_of_box = num_of_box->next;
        }
        return num_of_box->data;
    }
    // main game 
    struct node
    {
        int data;
        node* down;
        node* up;
    };
    node* top_coloum1 = NULL;
    node* top_coloum2 = NULL;
    node* top_coloum3 = NULL;
    node* top_coloum4 = NULL;
    node* head_coloum1 = NULL;
    node* head_coloum2 = NULL;
    node* head_coloum3 = NULL;
    node* head_coloum4 = NULL;
    node* del = NULL;
    void push(int value, int coloum)
    {
        node* newnode = new node;
        switch (coloum)
        {
        case 1:
            if (top_coloum1 == NULL)
            {
                head_coloum1 = newnode;
                size1++;
                newnode->up = NULL;
                newnode->data = value;
                newnode->down = top_coloum1;
                top_coloum1 = newnode;
            }
            else
            {
                size1++;
                newnode->up = NULL;
                top_coloum1->up = newnode;
                newnode->data = value;
                newnode->down = top_coloum1;
                top_coloum1 = newnode;
            }
            break;
        case 2:
            if (top_coloum2 == NULL)
            {
                head_coloum2 = newnode;
                size2++;
                newnode->up = NULL;
                newnode->data = value;
                newnode->down = top_coloum2;
                top_coloum2 = newnode;
            }
            else
            {
                size2++;
                newnode->up = NULL;
                top_coloum2->up = newnode;
                newnode->data = value;
                newnode->down = top_coloum2;
                top_coloum2 = newnode;
            }
            break;
        case 3:
            if (top_coloum3 == NULL)
            {
                head_coloum3 = newnode;
                size3++;
                newnode->up = NULL;
                newnode->data = value;
                newnode->down = top_coloum3;
                top_coloum3 = newnode;
            }
            else
            {
                size3++;
                newnode->up = NULL;
                top_coloum3->up = newnode;
                newnode->data = value;
                newnode->down = top_coloum3;
                top_coloum3 = newnode;
            }

            break;
        case 4:
            if (top_coloum4 == NULL)
            {
                head_coloum4 = newnode;
                size4++;
                newnode->up = NULL;
                newnode->data = value;
                newnode->down = top_coloum4;
                top_coloum4 = newnode;
            }
            else
            {
                size4++;
                newnode->up = NULL;
                top_coloum4->up = newnode;
                newnode->data = value;
                newnode->down = top_coloum4;
                top_coloum4 = newnode;
            }


            break;
        default:
            system("cls");
            SetConsoleTextAttribute(console, 112);
            cout << "\n\n\n\n\n\t";
            SetConsoleTextAttribute(console, 4);
            cout << "  Wrong answer chose coloum between <  1 to 4  >   , Press Enter to try again \n\n\n";
            SetConsoleTextAttribute(console, 7);
            system("pause");
            break;
        }
    }

    // جاهزه وخلصت 
    void add_coloum1_2()
    {
        node* test_coloum2 = head_coloum2;
        node* del = NULL;
        if (size1 == size2 && top_coloum1->data == top_coloum2->data)
        {
            top_coloum1->data = (top_coloum1->data * 2);
            del = top_coloum2;
            top_coloum2 = top_coloum2->down;
            free(del);
            if (top_coloum2 != NULL)
            {
                top_coloum2->up = NULL;
            }
            size2--;
            if (size2 == 0)
            {
                head_coloum2 = NULL;
            }

        }
        else if (size1 >= 2 && top_coloum1->data == top_coloum1->down->data)
        {
            top_coloum1->down->data = (top_coloum1->data * 2);

            del = top_coloum1;
            top_coloum1 = top_coloum1->down;

            if (top_coloum1 != NULL)
            {
                top_coloum1->up = NULL;
            }
            free(del);
            size1--;
        }
        else
        {
            for (int i = 1; i < size1; i++)
            {
                if (test_coloum2 != NULL)
                {
                    test_coloum2 = test_coloum2->up;
                }
            }
            if (test_coloum2 != NULL && top_coloum1->data == test_coloum2->data)
            {
                top_coloum1->data = (top_coloum1->data * 2);
                // هنا هستخدم بوينتر del علشان امسح النوده 
                del = test_coloum2;
                if (test_coloum2->down == NULL)
                {
                    del->up->down = NULL;
                    head_coloum2 = del->up;
                    free(del);
                    size2--;
                }
                else
                {
                    test_coloum2 = test_coloum2->down;
                    del->up->down = test_coloum2;
                    test_coloum2->up = del->up;
                    free(del);
                    size2--;
                }

            }
        }

    }
    // جاهزه وخلصت 
    void add_coloum4_3()
    {
        node* test_coloum3 = head_coloum3;
        node* del = NULL;
        if (size4 == size3 && top_coloum4->data == top_coloum3->data)
        {
            top_coloum4->data = (top_coloum4->data * 2);
            del = top_coloum3;
            top_coloum3 = top_coloum3->down;
            free(del);
            if (top_coloum3 != NULL)
            {
                top_coloum3->up = NULL;
            }
            size3--;
            if (size3 == 0)
            {
                head_coloum3 = NULL;
            }
        }
        else if (size4 >= 2 && top_coloum4->data == top_coloum4->down->data)
        {
            top_coloum4->down->data = (top_coloum4->data * 2);
            del = top_coloum4;
            top_coloum4 = top_coloum4->down;
            free(del);
            if (top_coloum4 != NULL)
            {
                top_coloum4->up = NULL;
            }
            size4--;
        }
        else
        {
            for (int i = 1; i < size4; i++)
            {
                if (test_coloum3 != NULL)
                {
                    test_coloum3 = test_coloum3->up;
                }

            }
            if (test_coloum3 != NULL && top_coloum4->data == test_coloum3->data)
            {
                top_coloum4->data = (top_coloum4->data * 2);
                // هنا هستخدم بوينتر del علشان امسح النوده 
                del = test_coloum3;
                if (test_coloum3->down == NULL)
                {
                    del->up->down = NULL;
                    head_coloum3 = del->up;
                    free(del);
                    size3--;
                }
                else
                {
                    test_coloum3 = test_coloum3->down;
                    del->up->down = test_coloum3;
                    test_coloum3->up = del->up;
                    free(del);
                    size3--;
                }

            }
        }
    }
    // جاهزه وخلصت 
    void add_coloum2_1_3()
    {
        node* test_for_coloum1 = head_coloum1;
        node* test_for_coloum3 = head_coloum3;
        node* del = NULL;
        if (size2 == size1 && top_coloum2->data == top_coloum1->data)
        {
            top_coloum2->data = (top_coloum2->data * 2);
            del = top_coloum1;
            top_coloum1 = top_coloum1->down;
            free(del);
            if (top_coloum1 != NULL)
            {
                top_coloum1->up = NULL;
            }
            size1--;
            if (size1 == 0)
            {
                head_coloum1 = NULL;
            }
        }
        else if (size2 == size3 && top_coloum2->data == top_coloum3->data)
        {
            top_coloum2->data = (top_coloum2->data * 2);
            del = top_coloum3;
            top_coloum3 = top_coloum3->down;
            free(del);
            if (top_coloum3 != NULL)
            {
                top_coloum3->up = NULL;
            }
            size3--;
            if (size3 == 0)
            {
                head_coloum3 = NULL;
            }
        }
        else if (size2 >= 2 && top_coloum2->data == top_coloum2->down->data)
        {
            top_coloum2->down->data = (top_coloum2->data * 2);
            del = top_coloum2;
            top_coloum2 = top_coloum2->down;
            free(del);
            if (top_coloum2 != NULL)
            {
                top_coloum2->up = NULL;
            }
            size2--;
        }
        else
        {
            // for coloum1
            for (int i = 1; i < size2; i++)
            {
                if (test_for_coloum1 != NULL)
                {
                    test_for_coloum1 = test_for_coloum1->up;
                }

            }
            //for coloum3
            for (int i = 1; i < size2; i++)
            {
                if (test_for_coloum3 != NULL)
                {
                    test_for_coloum3 = test_for_coloum3->up;
                }

            }
            //for coloum1
            if (test_for_coloum1 != NULL && top_coloum2->data == test_for_coloum1->data)
            {
                top_coloum2->data = (top_coloum2->data * 2);
                del = test_for_coloum1;
                if (test_for_coloum1->down == NULL)
                {
                    del->up->down = NULL;
                    head_coloum1 = del->up;
                    free(del);
                    size1--;
                }
                else
                {
                    test_for_coloum1 = test_for_coloum1->down;
                    del->up->down = test_for_coloum1;
                    test_for_coloum1->up = del->up;
                    free(del);
                    size1--;
                }
            }
            //for coloum3
            if (test_for_coloum3 != NULL && top_coloum2->data == test_for_coloum3->data)
            {
                top_coloum2->data = (top_coloum2->data * 2);
                del = test_for_coloum3;
                if (test_for_coloum3->down == NULL)
                {
                    del->up->down = NULL;
                    head_coloum3 = del->up;
                    free(del);
                    size3--;
                }
                else
                {
                    test_for_coloum3 = test_for_coloum3->down;
                    del->up->down = test_for_coloum3;
                    test_for_coloum3->up = del->up;
                    free(del);
                    size3--;
                }
            }
        }

    }
    // جاهزه وخلصت 
    void add_coloum3_2_4()
    {
        node* test_for_coloum2 = head_coloum2;
        node* test_for_coloum4 = head_coloum4;
        node* del = NULL;
        if (size2 == size3 && top_coloum2->data == top_coloum3->data)
        {
            top_coloum3->data = (top_coloum3->data * 2);
            del = top_coloum2;
            top_coloum2 = top_coloum2->down;
            free(del);
            if (top_coloum2 != NULL)
            {
                top_coloum2->up = NULL;
            }
            size2--;
            if (size2 == 0)
            {
                head_coloum2 = NULL;
            }

        }
        else if (size4 == size3 && top_coloum4->data == top_coloum3->data)
        {
            top_coloum3->data = (top_coloum3->data * 2);
            del = top_coloum4;
            top_coloum4 = top_coloum4->down;
            free(del);
            if (top_coloum4 != NULL)
            {
                top_coloum4->up = NULL;
            }
            size4--;
            if (size4 == 0)
            {
                head_coloum4 = NULL;
            }

        }
        else if (size3 >= 2 && top_coloum3->data == top_coloum3->down->data)
        {
            top_coloum3->down->data = (top_coloum3->data * 2);
            del = top_coloum3;
            top_coloum3 = top_coloum3->down;
            free(del);
            if (top_coloum3 != NULL)
            {
                top_coloum3->up = NULL;
            }
            size3--;
        }
        else
        {
            // for coloum2
            for (int i = 1; i < size3; i++)
            {
                if (test_for_coloum2 != NULL)
                {
                    test_for_coloum2 = test_for_coloum2->up;
                }

            }
            //for coloum4
            for (int i = 1; i < size3; i++)
            {
                if (test_for_coloum4 != NULL)
                {
                    test_for_coloum4 = test_for_coloum4->up;
                }

            }
            //for coloum2
            if (test_for_coloum2 != NULL && top_coloum3->data == test_for_coloum2->data)
            {
                top_coloum3->data = (top_coloum3->data * 2);
                del = test_for_coloum2;
                if (test_for_coloum2->down == NULL)
                {
                    del->up->down = NULL;
                    head_coloum2 = del->up;
                    free(del);
                    size2--;
                }
                else
                {
                    test_for_coloum2 = test_for_coloum2->down;
                    del->up->down = test_for_coloum2;
                    test_for_coloum2->up = del->up;
                    free(del);
                    size2--;
                }
            }
            //for coloum4
            if (test_for_coloum4 != NULL && top_coloum3->data == test_for_coloum4->data)
            {
                top_coloum3->data = (top_coloum3->data * 2);
                del = test_for_coloum4;
                if (test_for_coloum4->down == NULL)
                {
                    del->up->down = NULL;
                    head_coloum4 = del->up;
                    free(del);
                    size4--;
                }
                else
                {
                    test_for_coloum4 = test_for_coloum4->down;
                    del->up->down = test_for_coloum4;
                    test_for_coloum4->up = del->up;
                    free(del);
                    size4--;
                }
            }
        }
    }

    void check_change_of_matrix(int coloum)
    {
        switch (coloum)
        {
        case 1:
            for (int i = 0; i < 8; i++)
            {
                add_coloum1_2();
            }
            break;
        case 2:
            for (int i = 0; i < 8; i++)
            {
                add_coloum2_1_3();
            }

            break;
        case 3:
            for (int i = 0; i < 8; i++)
            {
                add_coloum3_2_4();
            }

            break;
        case 4:
            for (int i = 0; i < 8; i++)
            {
                add_coloum4_3();
            }
            break;
        default:
            break;
        }
    }

    void display_coloums()
    {
        node* d_coloum1 = NULL;
        node* d_coloum2 = NULL;
        node* d_coloum3 = NULL;
        node* d_coloum4 = NULL;
        d_coloum1 = head_coloum1;
        d_coloum2 = head_coloum2;
        d_coloum3 = head_coloum3;
        d_coloum4 = head_coloum4;
        //علشان نخلى الباك جروند لونه ابيض 
        SetConsoleTextAttribute(console, 112);
        system("cls");
        SetConsoleTextAttribute(console, 112);
        cout << "\n\n";
        cout << "\n\t\t\t\t\t   c1      c2       c3      c4\n";
        for (int i = 0; i < 4; i++)
        {

            cout << "\n\t\t\t\t\t---------------------------------\n";
            for (int r1 = 0; r1 < 1; r1++)
            {
                if (d_coloum1 != NULL)
                {
                    cout << "\t\t\t\t\t|  " << d_coloum1->data << "\t";
                    d_coloum1 = d_coloum1->up;
                }
                else { cout << "\t\t\t\t\t|\t"; }

                if (d_coloum2 != NULL)
                {
                    cout << "|  " << d_coloum2->data << "\t";
                    d_coloum2 = d_coloum2->up;
                }
                else { cout << "|\t"; }

                if (d_coloum3 != NULL)
                {
                    cout << "|  " << d_coloum3->data << "\t";
                    d_coloum3 = d_coloum3->up;
                }
                else { cout << "|\t"; }

                if (d_coloum4 != NULL)
                {
                    cout << "|  " << d_coloum4->data << "\t|";
                    d_coloum4 = d_coloum4->up;
                }
                else { cout << "|\t|"; }
            }
        }
        cout << "\n\t\t\t\t\t---------------------------------\n\n\n";
    }


    // for check the value of score

    void check_score()
    {
        if (top_coloum1 != NULL)
        {
            if (top_coloum1->data > score)
            {
                score = top_coloum1->data;
            }
        }
        if (top_coloum2 != NULL)
        {
            if (top_coloum2->data > score)
            {
                score = top_coloum2->data;
            }
        }
        if (top_coloum3 != NULL)
        {
            if (top_coloum3->data > score)
            {
                score = top_coloum3->data;
            }
        }
        if (top_coloum4 != NULL)
        {
            if (top_coloum4->data > score)
            {
                score = top_coloum4->data;
            }
        }
    }

    //////////////////////////////// logo func ///////////////////////
    void display_logo()
    {
        SetConsoleTextAttribute(console, 4532);
        cout << " .----------------.  .----------------.  .----------------.  .---------------- ." << endl;
        cout << "| .--------------. || .--------------. || .--------------. || .--------------. |" << endl;
        cout << "| |    _____     | || |     ____     | || |   _    _     | || |     ____     | |" << endl;
        cout << "| |   / ___ `.   | || |   .'    '.   | || |  | |  | |    | || |   .' __ '.   | |" << endl;
        cout << "| |  |_/___) |   | || |  |  .--.  |  | || |  | |__| |_   | || |   | (__) |   | |" << endl;
        cout << "| |   .'____.'   | || |  | |    | |  | || |  |____   _|  | || |   .`____'.   | |" << endl;
        cout << "| |  / /____     | || |  |  `--'  |  | || |      _| |_   | || |  | (____) |  | |" << endl;
        cout << "| |  |_______|   | || |   '.____.'   | || |     |_____|  | || |  `.______.'  | |" << endl;
        cout << "| |              | || |              | || |              | || |              | |" << endl;
        cout << " '----------------'  '----------------'  '----------------'  '----------------' " << endl;
        cout << "\n";
        SetConsoleTextAttribute(console, 0);
        // loding
        SetConsoleTextAttribute(console, 7);
        cout << "\n\n\n\n\tLOADING.....\n\t";
        SetConsoleTextAttribute(console, 4634);
        cout << "||||||||||||||||||||||||";
        wait(1);
        cout << "||||||||||||||||||||||||";
        wait(1);
        cout << "|||||||||||||||||||||||";
        wait(1);
        cout << "|||||||||||||||||||||||";
        wait(1);
        SetConsoleTextAttribute(console, 0);
        system("cls");
    }
    void wait(int seconds)
    {
        int endwait;
        endwait = clock() + seconds * CLOCKS_PER_SEC;
        while (clock() < endwait) {}
    }
    void display_score()
    {
        cout << "\n\n";
        SetConsoleTextAttribute(console, 112);
        cout << "\n\t\t\t\t\t   ";
        SetConsoleTextAttribute(console, 4);
        cout << " SCORE = ";
        SetConsoleTextAttribute(console, 112);
        cout << "\t  ";
        SetConsoleTextAttribute(console, 4);
        cout << "  " << score << " / 2048   ";
        SetConsoleTextAttribute(console, 112);
        cout << "\n\t\t\t\n\n\n\n";
    }

    void execuation()
    {
       
        int x = 0;
        bool game_is_end = false;
        int coloum = 0;

        display_logo();

        push_box(2);
    check_coloum:
        display_coloums();
        display_score();
        while (size1 != 5 && size2 != 5 && size3 != 5 && size4 != 5)
        {
            if (score == 2048)
            {
                game_is_end = true;
                break;
            }
            x = get_num_from_box();
            cout << "\t\t\tYou have the value -> \t";
            SetConsoleTextAttribute(console, 4);
            cout << "   " << x << "   ";
            SetConsoleTextAttribute(console, 112);
            cout << "\t\t\t";
            cout << "coloum = ";
            SetConsoleTextAttribute(console, 4);
            cin >> coloum;
            push(x, coloum);
            if (coloum > 4 || coloum < 0)
            {
                goto check_coloum;
            }
            check_change_of_matrix(coloum);
            check_score();
            insert_num_to_box();
            system("cls");
            display_coloums();
            display_score();
        }
        if (game_is_end)
        {
            cout << "\t\t\t\t\t  ";
            SetConsoleTextAttribute(console, 4);
            cout << " < CONGRATULATION >  YOU WIN ";
            SetConsoleTextAttribute(console, 112);
            cout << "\n\n";
        }
        else
        {
            cout << "\t\t\t\t\t  ";
            SetConsoleTextAttribute(console, 4);
            cout << " GAME OVER ! YOU LOSE..... ";
            SetConsoleTextAttribute(console, 112);
            cout << "\n\n";
        }




    }


};

////////////////////////////////////// Game 2 //////////////////////////


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
                Score_tree = Score_tree + 1;
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
            cout << "\t~* your score *~ : " << Score_tree << endl;

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



int main()
{
    cout << "\n\t               //////////////////////////////////////////////////////////////////////////////                      " << endl;
    cout << "                                              Welcome to our game                                                              " << endl;
    cout << "\t               //////////////////////////////////////////////////////////////////////////////                      " << endl;

    cout << "                                                List Of Game \n";
    cout << "\t               //////////////////////////////////////////////////////////////////////////////                      " << endl;

    cout << endl;
    cout << "                                                1 - Game_2048 \n";
    cout << "                                                2 - Game_Who am i ? \n";
    cout << "                                                3 - Game_Quiz \n";
    cout << "                                                4 - To Exit Game  \n";
    cout << " Enter Your Choose : ";
    int ch;
    cin >> ch;

    system("cls");

    switch (ch)
    {
    case 1:
      {
        game_2048 game1;
        game1.execuation();
        
        break;
      }
    case 2:
    {
        How_am_i game2;
        game2.built_tree();
        break;
    }
    case 3:
    {
        How_am_i game2;
        game2.built_tree();
        break;
    }
    case 4:
    {
        return 0;
        
    }

    }


    return 0;
}
