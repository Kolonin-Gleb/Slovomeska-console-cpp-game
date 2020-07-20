#include "Functions.h"

string enterAction()
{
	string action = "";

	while (true)
	{
		cout << "������� 1, ����� ����������� � ���������." << endl;
		cout << "������� 2, ����� ������ ������!" << endl;
		cin >> action;
		if (action == "1" || action == "2")
		{
			return action;
		}
		else
		{
			cout << "��������� �������� �����������!" << endl;
		}
	}
}

void showGameRules()
{
	cout << "\t\t ������� ����:" << endl;
	cout << "��������� ������� ��� �����, ����� �������� ������������." << endl;
	cout << "���� ������ �������, ��� ��� �� ����� � ������ ���." << endl;
	cout << "� ��� ���� 3 �����." << endl;
	cout << "���� ����� ����������, ���� �� ����������� ������� ���������� �����."<< endl;
	cout << "���� ����� ����������, �� �� ���������." << endl;
	cout << "���� �� �������� ��� �����, �� �� ��������." << endl;
	cout << "� ��� ����� ���� 3 ���������." << endl;
	cout << "��� ������� ����� ����� ������������ ������ 1 ���������." << endl;
	cout << "���������� �������� ������ �������� ����������� �����." << endl;
	cout << "����� ������������ ��������� ������� \"���������\" � ���� ������ ������" << endl;
	cout << "����� � �������� ����!" << endl;
	cout << endl << endl;
}

void startLevel()
{
	system("cls");

	short playerLives = 3;
	short playerHints = 3;
	const short COUNT_OF_WORDS = 10;

	string words[COUNT_OF_WORDS] =
	{
		"�����"  , "�����" , "������" , "�����"  , "������",
		"�������", "������", "������", "�������", "�������"
	};
	randomizeArray(words, COUNT_OF_WORDS);

	cout << "\t\t���� ��������!" << endl;

	for (int i = 0; i < COUNT_OF_WORDS; i++)
	{
		string playerAnswer;
		string playerQuestion = generateQuestion(&words[i]);

		cout << "\n�� ����������� " << i + 1 << " ����� �� " << COUNT_OF_WORDS << endl;
		cout << "���������� �����: " << playerQuestion << endl;
		cout << "��� �����: ";
		cin >> playerAnswer;
		if (playerAnswer == "���������")
		{
			if (playerHints != 0)
			{
				string hint = generateHint(&words[i]);
				useHint(playerHints, playerQuestion, hint);
				cin >> playerAnswer;
			}
			else
			{
				cout << "���������� ����� ��������� = 0!" << endl;
				cout << "���������� �����: " << playerQuestion << endl;
				cout << "��� �����: ";
				cin >> playerAnswer;
			}
		}
		if (playerAnswer == words[i])
		{
			cout << "�����!" << endl;
		}
		else
		{
			cout << endl;
			cout << "�� ��������!" << endl;
			cout << "���������� �����: " << words[i] << endl;
			cout << "���������� ����� ������ = " << --playerLives << endl;

			if (playerLives == 0)
			{
				cout << "� ��������� �� ���������! � ��� ����������� ��������� � ��������� ���." << endl;
				break;
			}
		}
	}

	if (playerLives > 0)
	{
		cout << "\n�� ��������! �����������!" << endl;
	}
}

string generateQuestion(string* const word)
{
	string playerQuestion = *word;
	while (playerQuestion == *word)
	{
		random_shuffle(playerQuestion.begin(), playerQuestion.end());
	}
	return playerQuestion;
}

string generateHint(string* const word)
{
	string hint = *word;
	hint.erase(hint.length() / 2);
	return hint;
}

void useHint(short playerHints, string playerQuestion, string hint)
{
	cout << "������ ���������� ����� ��������� = " << --playerHints << endl << endl;
	cout << "���������� �����: " << playerQuestion << endl;
	cout << "���������: " << hint << endl;
	cout << "��� �����: ";
}

