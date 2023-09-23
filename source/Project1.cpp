#include <iostream>
using namespace std;

//Functions
void main_func();
void add_teacher();
void add_student();
//-----------------

//Classes
class students
{
    public:
        string name;
        int age;
        int bn;

        students(string name , int age , float bn)
        {
            this -> name = name;
            this -> age = age;
            this -> bn = bn;
        }

        void show(int j)
        {
            cout << "\n----------- Student "<< j+1 <<" information -----------\n";
            cout << "Name " << j+1 <<":" << name << endl;
            cout << "age " << j+1 <<":" << age << endl;
            cout << "Bench Number " << j+1 <<":" << bn << endl;
            cout << "---------------------------------------------\n";
        }
};
class teachers
{
    public:
        string name;
        int age;
        float salary;

        teachers(string name , int age , float salary)
        {
            this -> name = name;
            this -> age = age;
            this -> salary = salary;
        }

        void show(int j)
        {
            cout << "\n----------- Teacher "<< j+1 <<" information -----------\n";
            cout << "Name " << j+1 <<":" << name << endl;
            cout << "age " << j+1 <<":" << age << endl;
            cout << "salary " << j+1 <<":" << salary << endl;
            cout << "---------------------------------------------\n";
        }
};

//-----------------
int main()
{
    main_func();
    return 0;
}

//FunctionsDetails
void main_func()
{
    int choice;
    do
    {
        cout << "\n-------- system options --------"
            "\n1- Press 1 to add teachers"
            "\n2- Press 2 to add students"
            "\n3- Press 3 to exit";

        cout << "\n------------------\n";
        cin >> choice;
        cout << "\n------------------\n";

        switch(choice)
        {
            case 1:
                add_teacher();
                break;

            case 2:
                add_student();
                break;

            case 3:
                break;

            default:
                cout << "\nEnter a valid number!\n";
        }
    }while(choice != 3);

}



void add_teacher()
{
    string names[10];
    int ages[10];
    float salaries[10];

    int teacherChoice;
    cout << "Enter the number of Teachers: \n";
    cout << "------------------\n";
    cin >> teacherChoice;
    cout << "------------------\n";

    //For for getting data from user
    for(int i= 0 ; i < teacherChoice ; i++)
    {
        cout << "Enter Name " << i+1 << ": \n";
        cout << "------------------\n";
        cin >> names[i] ;
        cout << "\n------------------\n";

        cout << "Enter age " << i+1 << ": \n";
        cout << "------------------\n";
        cin >> ages[i] ;
        cout << "\n------------------\n";

        cout << "Enter salary " << i+1 << ": \n";
        cout << "------------------\n";
        cin >> salaries[i] ;
        cout << "\n------------------\n";
    }

    for(int j = 0 ; j < teacherChoice ; j++)
    {
        teachers teacher(names[j] , ages[j] , salaries[j]);
        teacher.show(j);
    }

}


void add_student()
{
    string names[10];
    int ages[10];
    float bns[10];

    int studentChoice;
    cout << "Enter the number of students: \n";
    cout << "------------------\n";
    cin >> studentChoice;
    cout << "------------------\n";

    //For for getting data from user
    for(int i= 0 ; i < studentChoice ; i++)
    {
        cout << "Enter Name " << i+1 << ": \n";
        cout << "------------------\n";
        cin >> names[i] ;
        cout << "\n------------------\n";

        cout << "Enter age " << i+1 << ": \n";
        cout << "------------------\n";
        cin >> ages[i] ;
        cout << "\n------------------\n";

        cout << "Enter bn " << i+1 << ": \n";
        cout << "------------------\n";
        cin >> bns[i] ;
        cout << "\n------------------\n";
    }

    for(int j = 0 ; j < studentChoice ; j++)
    {
        students student(names[j] , ages[j] , bns[j]);
        student.show(j);
    }

}













