#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

struct Student {
	string name;
	string surname;
	int age;
    int id;

	string get_info_as_string() {
        return "ID: " + to_string(id) + " | Name: " + name + " | Surname : " + surname + " | Age : " + to_string(age);
	}
};

const string FILE_OF_DATA = "MyFile.txt"; //Шлях до файлу
const int RESERVE_SIZE = 100; //Максимальна кількість елементів масиву
int ID = 0;

void generateStudentArray(Student* arr_of_students, int& number_of_students);
void writeFileStudents(Student* arr_of_students, int number_of_students);
void writeEndFileStudents(Student new_student);
void addStudentInArray(Student* arr_of_students, int& number_of_students);
void showStudentArray(Student* arr_of_students, int number_of_students);
void readFileStudents(Student* arr_of_students);

string centerString(const std::string& str, int width);

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Ukrainian");

	Student arr_of_students[RESERVE_SIZE];
	int number_of_students = 0;

	generateStudentArray(arr_of_students, number_of_students);
	writeFileStudents(arr_of_students, number_of_students);

	addStudentInArray(arr_of_students, number_of_students);

	readFileStudents(arr_of_students);

	return 0;
}

string centerString(const std::string& str, int width) {
    if (str.length() >= width) return str;

    int padding = width - str.length();
    return std::string(padding / 2, ' ') + str + std::string((padding + 1) / 2, ' ');
}

void generateStudentArray(Student* arr_of_students, int& number_of_students)
{
	number_of_students = 2;
	arr_of_students[0].name = "Alex";
	arr_of_students[0].surname = "Black";
	arr_of_students[0].age = 20;
	arr_of_students[0].id = ID++;
	arr_of_students[1].name = "Ivan";
	arr_of_students[1].surname = "Ivanov";
	arr_of_students[1].age = 25;
	arr_of_students[1].id = ID++;

}

void writeFileStudents(Student* arr_of_students, int number_of_students)
{
    ofstream fout(FILE_OF_DATA, ios::out); // Відкрили файл для запису 
    for (int i = 0; i < number_of_students; i++)
    {
		fout << arr_of_students[i].get_info_as_string();
        if (i < number_of_students - 1)
        {
            fout << endl;
        }
    }
    fout.close();
}

void writeEndFileStudents(Student new_student)
{
    ofstream fadd(FILE_OF_DATA, ios::app); // Відкрили файл для дозапису 
    fadd << endl;
    fadd << new_student.get_info_as_string();
    fadd.close();
}

void addStudentInArray(Student* arr_of_students, int& number_of_students)
{

    if (number_of_students + 1 <= RESERVE_SIZE)
    {
        number_of_students++;
        cout << "Напишіть ім'я студента: ";
        cin >> arr_of_students[number_of_students - 1].name; cout << "Напишіть фамілію студента: ";
        cin >> arr_of_students[number_of_students - 1].surname; cout << "Напишіть вік студента: ";
        cin >> arr_of_students[number_of_students - 1].age;
		arr_of_students[number_of_students - 1].id = ID++;
        writeEndFileStudents(arr_of_students[number_of_students - 1]);
    }
    else cout << "Недостатньо пам'яті для додавання нового елемента!" << endl;
}

void showStudentArray(Student* arr_of_students, int number_of_students)
{
    for (int i = 0; i < number_of_students; i++) {
        cout << arr_of_students[i].get_info_as_string() << endl;
    }
}

//void readFileStudents(Student* arr_of_students, int& number_of_students)
//{
//    ifstream fin(FILE_OF_DATA, ios::in); // Відкрили файл для читання
//    if (!fin.is_open())
//        cout << "Вказаний файл не існує!" << endl;
//    else
//    {
//        int i = 0;
//        while (!fin.eof())
//        {
//            if (i < RESERVE_SIZE)
//            {
//                fin >> arr_of_students[i].name
//                    >> arr_of_students[i].surname
//                    >> arr_of_students[i].age;
//                i++;
//            }
//            else
//            {
//                cout << "Недостатньо пам'яті для читання усіх даних!" << endl;
//                break;
//            }
//        }
//        number_of_students = i;
//    }
//    fin.close(); //Закрили файл
//}

void readFileStudents(Student* arr_of_students)
{
    ifstream fin(FILE_OF_DATA, ios::in);
	if (!fin.is_open())
		cout << "Вказаний файл не існує!" << endl;
    else {
        char ch;
        while (fin.get(ch)) { // Читаємо файл символ за символом
            std::cout << ch;   // Виводимо символ на консоль
        }
    }
	fin.close();
}
