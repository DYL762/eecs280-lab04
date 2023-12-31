#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <istream>
using namespace std;


struct Meal{
    string type;         // e.g. Entree
    string name;         // e.g. Sushi
    double price;        // e.g. 5.00
};

struct Order{
    string order_num;
    double total_cost;
    vector<Meal> meals;
};

// REQUIRES: order points to a valid Order
// MODIFIES: *order
// EFFECTS: Initializes one order by reading from the input stream
// Input stream format: <order_num> <num_meals> <meal1_type> <meal1_name> <meal1_price> ...
// Example: 1 3 Entree Sushi 5.00 Dessert Mochi 3.50 Appetizer Tempura 3.00
// *Notes:
//    - You may assume that all inputs in the input stream (e.g. meal types and meal names) will be one word (no spaces in between)
//    - The order of meals into the meals array does not matter (e.g. Dessert can come before Appetizer).
void Order_Init(Order *order, istream &is) {
    int num_meals;
    // read in order number and number of meals from 'is'
    is >> order->order_num >> num_meals;

    // initialize variables that will be read by stream
    string type, name;
    double meal_price;
    double total_price = 0.0;

    // initialize the meals by reading from 'is'
    for (int i = 0; i < num_meals; ++i) {
        is >> type >> name >> meal_price;
        order->meals.at(i).type = type;
        order->meals.at(i).name = name;
        order->meals.at(i).price = meal_price;
        total_price += meal_price;
    }
    
    // set the total cost for the order   
    order->total_cost = total_price;
}



int main(int argc, char *argv[]) {
    // check if there are three arguments in the command line
    // and print a helpful message
    if(argc != 3) {
        cout << "Make sure you order properly!" << endl;
        cout << "Usage: ./delivery.exe [delivery_file] [tip_percentage]" << endl;
        return 1;
    }

    // create a file stream for the input file
    ifstream fin;

    // read in the number of orders
    string filename = argv[1];
    fin.open(filename);

    // intalize num_orders orders and add each order to this vector
    int num_orders;
    double tip = atoi(argv[2]);
    double total_cost = 0.0;
    fin >> num_orders;
    vector<Order> orders;
    for (int i = 0; i < num_orders; i++)
    {
        Order_Init(&orders.at(i), fin);
        total_cost += orders.at(i).total_cost;
    }
    
    

    // calculate the total cost for the delivery (all orders)


    // Print out the total cost with tip

    cout << "The delivery total with tip is $" << total_cost*(1.0 + tip/100.0);


}