#include <iostream>
using namespace std;

/** 1. Создать класс Person (человек) с полями: имя, возраст, пол и вес. Определить методы переназначения имени, изменения возраста и веса.
Создать производный класс Student (студент), имеющий поле года обучения. Определить методы переназначения и увеличения этого значения.
 Создать счетчик количества созданных студентов. В функции main() создать несколько (не больше трёх) студентов. Вывести информацию о них.**/
class Person {
protected:
    string name;
    int age;
    string gender;
    double weight;
public:
    static int number;
    void setName(string n) {
        name = n;
    }
    void setAge(int a) {
        age = a;
    }
    void setWeight(double w) {
        weight = w;
    }
};

int Person::number = 0;

class Student : public Person {
    int year;
public:
    Student(string g) {
        number++;
        gender = g;
    }
    void setYear(int y) {
        year = y;
    }
    void nextYear() {
        year++;
    }
    void info() {
        cout << endl << "Student: " << name << endl << "Age: " << age << endl << "Gender: " << gender << endl
             << "Weight: " << weight << endl << "Year: " << year << endl;
    }
};

/** 2. Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт).
У Fruit есть две переменные-члена: name (имя) и color (цвет). Добавить новый класс GrannySmith, который наследует класс Apple.**/
class Fruit {
protected:
    string name, color;
public:
    string getName() {
        return name;
    }
    string getColor() {
        return color;
    }
};

class Apple : public Fruit {
public:
    Apple(string clr = "", string nm = "apple") {
        color = clr;
        name = nm;
    }
};

class Banana : public Fruit {
public:
    Banana(string clr = "yellow", string nm = "banana") {
        color = clr;
        name = nm;
    }
};

class GrannySmith : public Apple {
public:
    GrannySmith(string clr = "green", string nm = "Granny Smith apple") : Apple(clr, nm) {}
};

int main() {
    Student s1("Male");
    s1.setName("Egor");
    s1.setAge(18);
    s1.setWeight(70);
    s1.setYear(1);
    s1.info();

    Student s2("Female");
    s2.setName("Anna");
    s2.setAge(21);
    s2.setWeight(53);
    s2.setYear(4);
    s2.nextYear();
    s2.info();

//    Student s3("Male");
//    Student s4("Male");

    cout << endl << "Number of students: " << Person::number << endl;

    Apple a("red");
    Banana b;
    GrannySmith c;

    cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
    return 0;
}
