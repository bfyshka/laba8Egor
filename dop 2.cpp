#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// current date
int tday = 31; 
int tmonth = 12;
int tyear = 2020;

class Product
{
public:
    int number;
    string name;
    int pricefor1;
    int amount;
    int day;
    int month;
    int year;


    void add()
    {
        cin.ignore(100, '\n');
        cout << "Enter product's name: ";
        getline(cin, name);
        cout << "Enter product's price for 1: ";
        cin >> pricefor1;
        cout << "Enter product's amount: ";
        cin >> amount;
        cout << "Enter product's day of posteplenie: ";
        cin >> day;
        cout << "Enter product's month of posteplenie: ";
        cin >> month;
        cout << "Enter product's year of posteplenie: ";
        cin >> year;
    }
};

vector <Product> init_products()
{
    ifstream cin("inputdata.txt");
    ofstream fout("outputdata.txt");
    int products_number;
    cin >> products_number;
    cin.ignore(100, '\n');
    cout << "Getting information about products from a file..." << endl;
    vector <Product> input(products_number);
    for (int i = 0; i < products_number; i++)
    {
        input[i].number = i + 1;
        getline(cin, input[i].name);
        cin >> input[i].pricefor1;
        cin >> input[i].amount;
        cin >> input[i].day;
        cin >> input[i].month;
        cin >> input[i].year;
        cin.ignore(100, '\n');

        cout << "Product #" << input[i].number << endl;
        cout << "Product's name: " << input[i].name << endl;
        cout << "Product's price for 1: " << input[i].pricefor1 << endl;
        cout << "Product's amount: " << input[i].amount << endl;
        cout << "Product's date: " << input[i].day << "." << input[i].month << "." << input[i].year << endl << endl;

        if (input[i].amount * input[i].pricefor1 > 100000)
        {
            if(input[i].year == tyear)
            {
                if (input[i].month == tmonth && tday - input[i].day == 30)
                {
                    fout << "Product #" << input[i].number << endl;
                    fout << "Product's name: " << input[i].name << endl;
                    fout << "Product's price for 1: " << input[i].pricefor1 << endl;
                    fout << "Product's amount: " << input[i].amount << endl;
                    fout << "Product's date: " << input[i].day << "." << input[i].month << "." << input[i].year << endl << endl;
                }
                else if (tmonth - input[i].month >= 1)
                {
                    fout << "Product #" << input[i].number << endl;
                    fout << "Product's name: " << input[i].name << endl;
                    fout << "Product's price for 1: " << input[i].pricefor1 << endl;
                    fout << "Product's amount: " << input[i].amount << endl;
                    fout << "Product's date: " << input[i].day << "." << input[i].month << "." << input[i].year << endl << endl;
                }
            }
            else if (tyear - input[i].year >= 1)
            {
                fout << "Product #" << input[i].number << endl;
                fout << "Product's name: " << input[i].name << endl;
                fout << "Product's price for 1: " << input[i].pricefor1 << endl;
                fout << "Product's amount: " << input[i].amount << endl;
                fout << "Product's date: " << input[i].day << "." << input[i].month << "." << input[i].year << endl << endl;
            }  
        }
    }
    return input;
}

void add_product(vector <Product> &products)
{
    cout << "Enter information about product #" << products.size() + 1 << endl;
    Product new_product;
    new_product.add();
    new_product.number = products.size() + 1;
    products.push_back(new_product);
    ofstream fout;
    fout.open("outputdata.txt", fstream::app);
    fout << "Product #" << products.size() << endl;
    fout << "Product's name: " << new_product.name << endl;
    fout << "Product's price for 1: " << new_product.pricefor1 << endl;
    fout << "Product's amount: " << new_product.amount << endl;
    fout << "Product's date: " << new_product.day << "." << new_product.month << "." << new_product.year << endl << endl;
    fout.close();
}

void print_file()
{
    ifstream cin ("outputdata.txt");
    string temp;
    while (!cin.eof())
    {
        getline(cin, temp);
        cout << temp << endl;
    }
}

void delete_product(vector <Product> &products, int pos) // not used
{

    products.erase(products.begin() + pos);
}

int main()
{
    vector <Product> products = init_products();

    cout << "Do you want to see 'outputdata.txt' (Y or N) ";
    char anstosee;
    cin >> anstosee;
    cout << endl;
    if (anstosee == 'Y') print_file();

    while (true)
    {
        cout << endl << "Do you want to add new product? (Y or N): ";
        char answer;
        cin >> answer;
        cout << endl;
        if (answer == 'Y') add_product(products);
        else if (answer == 'N') break;

        cout << endl << "Do you want to see new 'outputdata.txt' (Y or N) ";
        char anstoseenew;
        cin >> anstoseenew;
        cout << endl;
        if (anstoseenew == 'Y') print_file();
    }
}