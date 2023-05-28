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
int biggest_num_in_box = 2;
int score = 0;
int size1 = 0, size2 = 0, size3 = 0, size4 = 0;
int Score_tree = 0;


class game_2048
{
public:
    // circular box
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


    void insert_num_to_box()
    {
        if (biggest_num_in_box < score)
        {
            biggest_num_in_box = score;
            push_box(score);
        }
    }

    int get_num_from_box()
    {
        node_box* num_of_box = head;
        srand(time(0));
        int count = rand() % 20;
        for (int i = 0; i < count; i++)
        {
            num_of_box = num_of_box->next;
        }
        return num_of_box->data;
    }
    // circular end 
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
            top_coloum1->up = NULL;
            free(del);
            size1--;
        }
        else
        {
            // size is different
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
                //for first node of coloum 2
                if (test_coloum2->down == NULL)
                {
                    del->up->down = NULL;
                    head_coloum2 = del->up;
                    free(del);
                    size2--;
                }
                //for any node of coloum 2
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
            top_coloum3 = top_coloum3->down;  //Null
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
            top_coloum4->up = NULL;
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
                    del->up->down = test_coloum3;// بتشاور ع اللي قبل اللي فوق
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
            top_coloum2->up = NULL;
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
            top_coloum3->up = NULL;
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
    // علشان يشوف العمود اللى اتعبى والفاضى 
    void check_the_size_of_coloums(int coloum)
    {
        switch (coloum)
        {
        case 1:
            if (size1 == 5)
            {
                size1--;
                top_coloum1 = top_coloum1->down;
                top_coloum1->up = NULL;
                system("cls");
                SetConsoleTextAttribute(console, 4);
                cout << "\n\n\n\n\n\t\t\t\t\t\t  the coloum is full try again.... \n\n\n\n\n\n";
                SetConsoleTextAttribute(console, 7);
                system("pause");
            }

            break;
        case 2:
            if (size2 == 5)
            {
                size2--;
                top_coloum2 = top_coloum2->down;
                top_coloum2->up = NULL;
                system("cls");
                SetConsoleTextAttribute(console, 4);
                cout << "\n\n\n\n\n\t\t\t\t\t\t  the coloum is full try again.... \n\n\n\n\n\n";
                SetConsoleTextAttribute(console, 7);
                system("pause");
            }

            break;
        case 3:
            if (size3 == 5)
            {
                size3--;
                top_coloum3 = top_coloum3->down;
                top_coloum3->up = NULL;
                system("cls");
                SetConsoleTextAttribute(console, 4);
                cout << "\n\n\n\n\n\t\t\t\t\t\t  the coloum is full try again.... \n\n\n\n\n\n";
                SetConsoleTextAttribute(console, 7);
                system("pause");
            }

            break;
        case 4:
            if (size4 == 5)
            {
                size4--;
                top_coloum4 = top_coloum4->down;
                top_coloum4->up = NULL;
                system("cls");
                SetConsoleTextAttribute(console, 4);
                cout << "\n\n\n\n\n\t\t\t\t\t\t  the coloum is full try again.... \n\n\n\n\n\n";
                SetConsoleTextAttribute(console, 7);
                system("pause");
            }
            break;
        default:
            break;
        }
    }

    void GUI(int x)
    {
        cout << "\t\t\tYou have the value -> \t";
        SetConsoleTextAttribute(console, 4);
        cout << "   " << x << "   ";
        SetConsoleTextAttribute(console, 112);
        cout << "\t\t\t";
        cout << "coloum = ";
        SetConsoleTextAttribute(console, 4);
    }
    // for check the value of score

    void check_score()
    {
        if (top_coloum1 != NULL)
        {
            if (top_coloum1->data >= score)
            {
                score = top_coloum1->data;
            }
        }
        if (top_coloum2 != NULL)
        {
            if (top_coloum2->data >= score)
            {
                score = top_coloum2->data;
            }
        }
        if (top_coloum3 != NULL)
        {
            if (top_coloum3->data >= score)
            {
                score = top_coloum3->data;
            }
        }
        if (top_coloum4 != NULL)
        {
            if (top_coloum4->data >= score)
            {
                score = top_coloum4->data;
            }
        }
    }
    void execuation()
    {
        game_2048 game1;
        int x = 0;
        bool game_is_end = false;
        int coloum = 0;
        game1.display_logo();
        game1.push_box(2);
    check_coloum:
        game1.display_coloums();
        game1.display_score();
        while (size1 <= 4 || size2 <= 4 || size3 <= 4 || size4 <= 4)
        {
            if (score == 2048)
            {
                game_is_end = true;
                break;
            }
            x = game1.get_num_from_box();
            game1.GUI(x);
            cin >> coloum;
            game1.push(x, coloum);
            if (coloum > 4 || coloum < 0)
            {
                goto check_coloum;
            }
            game1.check_the_size_of_coloums(coloum);
            game1.check_change_of_matrix(coloum);
            if (size1 == 4 && size2 == 4 && size3 == 4 && size4 == 4)
            {
                system("cls");
                game1.display_coloums();
                game1.display_score();
                break;
            }
            game1.check_score();
            game1.insert_num_to_box();
            system("cls");
            game1.display_coloums();
            game1.display_score();
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
            cout << "\n\t\t\t\t\t\t";
            SetConsoleTextAttribute(console, 4);
            cout << " GAME OVER ! YOU LOSE..... ";
            SetConsoleTextAttribute(console, 112);
            cout << "\n\n";
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

};


////////////////////////////////////// Game 2 //////////////////////////

class How_am_i
{
    //private
    int Score_tree = 0;
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
            cout << "-> " << curr->data << "\n";
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
            cout << "\nIs it a " << curr->data << "? (y/n): ";
            cin >> answer;
            if (answer == 'y') {
                cout << "I win!\n";
            }
            else {
                Score_tree = Score_tree + 1;
                cout << "\nI give up. What animal were you thinking of? ";
                cin.ignore();
                getline(cin, newAnimal);
                cout << "\nWhat is a yes/no question that distinguishes a <  "
                    << curr->data << " > from a < " << newAnimal << " > ? ";
                //cin.ignore();
                getline(cin, question);
                cout << "\nIf the animal were a < " << newAnimal << " > , what would the answer to that question be? ";
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
            cout << "\n" << curr->data << " (y/n): ";
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
        root->left->right->right = createLeaf("parrot");
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

            cout << "\n the list contain :- \n\n";
            SetConsoleTextAttribute(console, 3);
            displayAnimals(root);
            SetConsoleTextAttribute(console, 7);
            cout << "\n\n";
            cout << "\n Note :  this is the only animals available for now with every time you play it become more complex good luck \n" << endl;
            SetConsoleTextAttribute(console,3);
            cout << "\n\nThink of an animal and I'll try to guess it.";
            cout << "\n~* your score *~ : " << Score_tree << endl;
            playGame(root);
            cout << "Do you want to play again? (Y/N): ";
            cin >> ch;

            system("cls");
        }
        cout << "\nThanks for playing!\n";


    }

    void logo_how_am_i()
    {
        SetConsoleTextAttribute(console, 4532);
        cout << "    _    _                                                  _             ___  \n";
        cout << "   | |  | |                                                (_)           |__ \\ \n";
        cout << "   | |__| |   ___   __      __     __ _   _ __ ___          _               ) |\n";
        cout << "   |  __  |  / _ \\  \\ \\ /\\ / /    / _` | | '_ ` _ \\        | |             / / \n";
        cout << "   | |  | | | (_) |  \\ V  V /    | (_| | | | | | | |       | |            |_|  \n";
        cout << "   |_|  |_|  \\___/    \\_/\\_/      \\__,_| |_| |_| |_|       |_|            (_)  \n";
        cout << "                                                                               \n";
        // loding
        SetConsoleTextAttribute(console, 7);
        cout << "\n\n\n\n\tLOADING.....\n\t";
        SetConsoleTextAttribute(console, 4634);
        cout << "||||||||||||||||||||||||";
        // بتأخر الكود ثانيه 
        Sleep(1000);
        cout << "||||||||||||||||||||||||";
        Sleep(1000);
        cout << "|||||||||||||||||||||||";
        Sleep(1000);
        cout << "|||||||||||||||||||||||";
        Sleep(1000);
        SetConsoleTextAttribute(console, 0);
        system("cls");


    }


};


////////////////////////////////////////// Game 3///////////////////////

class quiz_game {

public:

    struct quiz_node
    {
        int data;
        quiz_node* next;
    };
    quiz_node* head = NULL;
    quiz_node* tail = NULL;
    void insert_answer(int true_ans) {

        quiz_node* newnode = new quiz_node;
        newnode->data = true_ans;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
            return;

        }
        else
        {
            tail->next = newnode;
        }


    }

    void set_answers() {

        insert_answer(61);                          insert_answer(5);                      insert_answer(2);
        insert_answer(10);                          insert_answer(3);                      insert_answer(5);
        insert_answer(12);                          insert_answer(2520);                   insert_answer(21);
        insert_answer(305);                         insert_answer(20);                     insert_answer(24);
        insert_answer(168);                         insert_answer(7);                      insert_answer(25);
        insert_answer(19);                          insert_answer(35);                     insert_answer(5);
        insert_answer(600);                         insert_answer(5);                      insert_answer(48);
        insert_answer(0);                           insert_answer(20);                     insert_answer(1260);
        insert_answer(1827);                        insert_answer(22);                     insert_answer(6170);
        insert_answer(4884);                        insert_answer(297);                    insert_answer(384);
    }

    bool check_answer(int ans, int random) {


        quiz_node* ptr = head;
        for (int i = 1; i < random; i++)
        {
            ptr = ptr->next;  
        }
        if (ans == ptr->data)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    void display_qa() {
        ifstream myfile("questions.txt");
        string line;
        srand(time(0));
        int curent = rand() % 20;
        int numq, answer;
        int score_quiz = 0;
        char choice;
    start:
        SetConsoleTextAttribute(console, 112);
        system("cls");
        SetConsoleTextAttribute(console, 112);
        cout << " Please Enter the number of questions from < 1 : 10 > : ";
        cin >> numq;
        if (numq > 10 || numq < 1)
        {
            SetConsoleTextAttribute(console, 4);
            cout << "\n\t\t\t wrong answer . try again .....\n\n";
            Sleep(1000);
            system("cls");
            goto start;
        }
        Sleep(1000);
        system("cls");
        for (int i = 0; i < curent; i++)
        {
            
            getline(myfile, line);
        }
        for (int i = 0; i < numq; i++)
        {
            
            system("cls");
            cout << line << endl;
            cout << "enter your anwser->  ";
            cin >> answer;
            if (check_answer(answer, curent)) {
                cout << "Your answer is correct" << endl;
                score_quiz += 10;
                cout << "Score: " << score_quiz << endl;
            }
            else {
                cout << "Your answer is wrong" << endl;
            }
            curent++;
            Sleep(1000);
            system("CLS");
            getline(myfile, line);

        }
        if (score_quiz >= numq * 10) {
            cout << "Congratulations, you won! " << endl;
            goto end;
        }
        else {
            cout << "Unfortunately, you lost" << endl;
            goto end;
        }
    end:
        Sleep(1000);
        system("CLS");
        cout << "\n\t Do you Want to Ask again?( Y / N )\n\t\t\t";
        cin >> choice;
        Sleep(1000);
        system("CLS");
        if (choice == 'n' || choice == 'N')
        {
            cout << "\n\n\t\t We hope you had a great time with a little fun and benefit. ";
            Sleep(1500);
            cout << "\n\n\t\t Keep in mind that: ";
            Sleep(1500);
            cout << "\n\n\t\t Creativity, when intelligence becomes a kind of fun. \n\n\t\t\t Albert Einstein \n";
            Sleep(1500);
            exit(0);
        }
        else if (choice == 'y' || choice == 'Y')
        {
            goto start;
        }
        else
        {
            cout << "\n\tWrong choose\n\tTry again\n";
            goto end;
        }
        myfile.close();
    }

    void logo_quiz()
    {
        SetConsoleTextAttribute(console, 4532);
        cout << "\t                _                                          \n";
        cout << "\t               (_)                                         \n";
        cout << "\t     __ _ _   _ _ _______      __ _  __ _ _ __ ___   ___   \n";
        cout << "\t    / _` | | | | |_  / _ \\    / _` |/ _` | '_ ` _ \\ / _ \\  \n";
        cout << "\t   | (_| | |_| | |/ /  __/   | (_| |(_| | | | | | |  __/   \n";
        cout << "\t    \\__, |\\__,_|_/___\\___|    \\__, |\\__,_|_| |_| |_|\\___|  \n";
        cout << "\t       | |                     __/ |                       \n";
        cout << "\t       |_|                    |___/                        \n";
        // loding
        SetConsoleTextAttribute(console, 7);
        cout << "\n\n\n\n\tLOADING.....\n\t";
        SetConsoleTextAttribute(console, 4634);
        cout << "||||||||||||||||||||||||";
        // بتأخر الكود ثانيه 
        Sleep(1000);
        cout << "||||||||||||||||||||||||";
        Sleep(1000);
        cout << "|||||||||||||||||||||||";
        Sleep(1000);
        cout << "|||||||||||||||||||||||";
        Sleep(1000);
        SetConsoleTextAttribute(console, 0);
        system("cls");


    }



};






int main()
{
    SetConsoleTextAttribute(console, 112);
    system("cls");
    SetConsoleTextAttribute(console, 112);

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
    cout << "\n\n Enter Your Choose : ";
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

        game2.logo_how_am_i();
        game2.built_tree();
        
        break;
    }
    case 3:
    {

        quiz_game game3;

     //  game3.logo_quiz();
        game3.set_answers();
        game3.display_qa();
        
        break;
    }
    case 4:
    {
        return 0;
        
    }

    }


    return 0;
}
