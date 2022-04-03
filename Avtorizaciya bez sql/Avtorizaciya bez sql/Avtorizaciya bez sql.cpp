#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>


using namespace std;
void vhod();
void vyhod();
void registr();
bool check(string, string);
bool check_2(string);
void menu();
void zapis();
void vyvod();
void poisk();


string main_log = " ";


void menu()
{
    system("cls");
    cout << "1  -  Выход из аккаунта" << endl
        << "2  -  Ввод строки" << endl
        << "3  -  Вывод всех строк и их авторов"<<endl
        << "4  -  Поиск строк по автору"<<endl;
    int i = 0;
    cin >> i;
    switch (i)
    {
    case 1:vyhod(); break;
    case 2:zapis(); break;
    case 3:vyvod(); break;
    case 4:poisk(); break;
    }
}
void poisk()
{
    cout << "Введите автора:" << endl;
    string s;
    cin >> s;
    s = "(" + s + ")";
    string stroka;
    ifstream file("stroki.txt");
    char buff[50];
    int i = 0;
    while (getline(file, stroka)) {
        file >> buff;
        if (strcmp(s.c_str(), buff) == 0&&i==0)
        {
            cout <<stroka << endl;
        }
        else
        {
            cout << buff << stroka << endl;
        }
        i++;
    }
    cout << "Перейти в меню и отчистить экран?" << endl
        << "1  -  Да" << endl;
    int w;
    while (true)
    {
        cin >> w;
        if (w == 1)
        {
            menu();
        }
    }
}
void zapis()
{
    system("cls");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 
    setlocale(LC_ALL, "Rus");
    cout << "Введите свою строку:" << endl;
    string s="";
    string q = " 1234567";
    while (s<q)
    {
        getline(cin, s);
    }
    cout << "Желаете сохранить строку?" << endl
        << "Да  -  1" << endl
        << "Нет -  2" << endl;
    int w;
    cin >> w;
    if (w == 1)
    {
        ofstream rd;
        rd.open("stroki.txt", ios_base::app);
        rd <<"(" << main_log <<")" << " - " << s;
        rd << endl;
        rd.close();
    }
    menu();
}
void vyvod()
{
    system("cls");
    string s; 
    ifstream file("stroki.txt"); 
    cout << "Автор:" << " " << "Строка"<<endl;
    while (getline(file, s)) { 
        cout << s << endl; 

    }

    file.close(); 
    cout << "Перейти в меню и отчистить экран?" << endl
        << "1  -  Да" << endl;
    int w;
    while (true)
    {
        cin >> w;
        if (w == 1)
        {
            menu();
        }
    }
}








int main()
{
    setlocale(LC_ALL, "rus");
        
    cout << "1 - Вход" << endl;
    cout << "2 - Регестрация" << endl;
    int a;
    cin >> a;
    ifstream fs("users.txt", ios::in | ios::binary);
    string str;
    switch (a)
    {
    case 1: vhod(); break;
    case 2: registr(); break;
    }
}
void registr()
{
    bool flag = false;
    string login_new, password_new;
    cout << "Введите логин нового пользователя: " << endl;
    cin >> login_new;
    cout << "Введите пароль нового пользователя: " << endl;
    cin >> password_new;
    ofstream fout("D:\ users.txt", ios::app);
    fout << endl << login_new << " " << password_new;
    flag = check(login_new,password_new);
    if (flag == true)
    {
        cout << "Поздравляем! Регистрация прошла успешно! " << endl;
        main();
    }
    cout << "Ошибка, повторите попытку " << endl;
    main();
}
bool check(string login, string password)
{
    ifstream fs("users.txt", ios::in); 
    if (!fs) return 1; 
    string s;
    string danny = login + " " + password;
    while (getline(fs, s)) { 
        if (strcmp(s.c_str(), danny.c_str()) == 0)
        {  
            return true;
            fs.close();
        }
    }
    return false;
    fs.close();
}
void vhod()
{

    bool flag = false;

    string login, password;
    cout << "Введите логин: " << endl;
    cin >> login;
    cout << "Введите пароль: " << endl;
    cin >> password;
    flag = check(login, password);
    if (flag == true)
    {
        cout << "Вы вошли в систему!" << endl;
        main_log = login;
        menu();
    }
    else
    {
        cout << "Неверный пароль. Попробуйте еще раз." << endl;
        main();

    }
    system("pause");
}
void vyhod()
{
    main_log = " ";
    main();
}