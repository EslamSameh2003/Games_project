#include <iostream>
#include <cstdlib>
#include <ctime>
#include<fstream>
#include<string>
#include<windows.h>
using namespace std;
// انا ضفت تعديل عليه 

class quiz_game {

public:

	class quiz_node {
	public:
		int data;
		quiz_node* next;
	};

	quiz_node* head = NULL;

	void insert_answer(int true_ans, int pos) {

		quiz_node* newnode = new quiz_node;
		newnode->data = true_ans;
		newnode->next = NULL;

		if (pos == 1) {
			newnode->next = head;
			head = newnode;
			return;
		}

		quiz_node* temp = head;
		for (int i = 1; i < pos - 1 && temp != NULL; i++) {
			temp = temp->next;
		}

		if (temp != NULL) {
			newnode->next = temp->next;
			temp->next = newnode;
		}
	}

	void set_answers() {

		insert_answer(61, 1);                           insert_answer(5, 2);                       insert_answer(2, 3);
		insert_answer(10, 4);                           insert_answer(3, 5);                       insert_answer(5, 6);
		insert_answer(12, 7);                           insert_answer(2520, 8);                    insert_answer(21, 9);
		insert_answer(305, 10);                         insert_answer(20, 11);                     insert_answer(24, 12);
		insert_answer(168, 13);                         insert_answer(7, 14);                      insert_answer(25, 15);
		insert_answer(19, 16);                          insert_answer(35, 17);                     insert_answer(5, 18);
		insert_answer(600, 19);                         insert_answer(5, 20);                      insert_answer(48, 21);
		insert_answer(0, 22);                           insert_answer(20, 23);                     insert_answer(1260, 24);
		insert_answer(1827, 25);                        insert_answer(22, 26);                     insert_answer(6170, 27);
		insert_answer(4884, 28);                        insert_answer(297, 29);                    insert_answer(384, 30);
	}

	bool check_answer(int ans, int random) {

		
		quiz_node* ptr = head;
		for (int i = 1; i < random; i++)
		{
			ptr = ptr->next;
			// int index = i;
			// if (random == index) {
			// 	if (ans == ptr->data) {
			// 		return true;
			// 	}
			// 	else {
			// 		return false;
			// 	}
			//}
		}
		//cout << ptr->data << "\n";
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
		int curent = 0;
		srand(time(0));
		int num_line = rand()%20;
		int numq, answer;
		int score_quiz = 0;
		char choice;
	start:
		cout << "\n\n\t\t Please Enter the number of questions from < 1 : 10 > : ";
		cin >> numq;
		if (numq>10 || numq<1)
		{
            cout<<"\n\n\t\t wrong answer try again.....";
            Sleep(1500);
            system("cls");
			goto start;
		}
		Sleep(1000);
		system("cls");
		curent = num_line;
			for (int i = 0; i < curent; i++)
			{
				getline(myfile, line);
			}
			for (int i = 0; i < numq; i++)
			{
				//getline(myfile, line);
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

};

int main() {

	quiz_game* quiz = new quiz_game;
	quiz->set_answers();
	quiz->display_qa();
}
