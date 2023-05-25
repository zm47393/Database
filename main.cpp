#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Student {
public:
    string Nazwisko;
    string Imie;
    string NrAlbumu;
    string Grupa;
    int Rok;

    friend ostream& operator<<(ostream& os, const Student& student) {
        os << "Nazwisko: " << student.Nazwisko << endl;
        os << "Imie: " << student.Imie << endl;
        os << "Nr albumu: " << student.NrAlbumu << endl;
        os << "Grupa: " << student.Grupa << endl;
        os << "Rok: " << student.Rok << endl;
        return os;
    }
};

int main() {
    vector<Student> listaStudentow;

    // Dodawanie studentów do listy
    Student student1;
    student1.Nazwisko = "Kowalski";
    student1.Imie = "Jan";
    student1.NrAlbumu = "12345";
    student1.Grupa = "A";
    student1.Rok = 2;
    listaStudentow.push_back(student1);

    Student student2;
    student2.Nazwisko = "Nowak";
    student2.Imie = "Anna";
    student2.NrAlbumu = "67890";
    student2.Grupa = "B";
    student2.Rok = 3;
    listaStudentow.push_back(student2);

    // Zapisywanie listy studentów do pliku
    ofstream plikWyjsciowy("lista_studentow.txt");
    if (plikWyjsciowy.is_open()) {
        for (const auto& student : listaStudentow) {
            plikWyjsciowy << student << endl;
        }
        plikWyjsciowy.close();
    } else {
        cout << "Nie mozna otworzyc pliku do zapisu." << endl;
        return 1;
    }

    // Wczytywanie listy studentów z pliku
    ifstream plikWejsciowy("lista_studentow.txt");
    if (plikWejsciowy.is_open()) {
        string linia;
        while (getline(plikWejsciowy, linia)) {
            Student student;
            getline(plikWejsciowy, student.Nazwisko);
            getline(plikWejsciowy, student.Imie);
            getline(plikWejsciowy, student.NrAlbumu);
            getline(plikWejsciowy, student.Grupa);
            plikWejsciowy >> student.Rok;
            listaStudentow.push_back(student);
        }
        plikWejsciowy.close();
    } else {
        cout << "Nie mozna otworzyc pliku do odczytu." << endl;
        return 1;
    }

    // Wyświetlanie wszystkich studentów
    cout << "Wszyscy studenci:" << endl;
    for (const auto& student : listaStudentow) {
        cout << student << endl;
    }

    // Wyświetlanie studentów 3. roku za pomocą count_if
    int rok = 3;
    int liczbaStudentow3Roku = count_if(listaStudentow.begin(), listaStudentow.end(),
        [rok](const Student& student) {
            return student.Rok == rok;
        });

    cout << "Liczba studentów " << rok << ". roku: " << liczbaStudentow3Roku << endl;

    return 0;
}
