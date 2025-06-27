//Author(s): Nate Hartway
//Purpose: Allow a user to purchase products from a grocery store. When the user is ready to checkout show them what theyre purchasing and their total.
//Date:6/27/2025
//Version:v0.5

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

void get_discounts(int& discounts_list_size, int*& discount_required_products, int*& discount_original_products, float*& discounts);
void get_products(int*& product_ids, string*& product_names, float*& product_prices, int& list_of_products_size);
void calculate_total(int user_input, int list_of_products_size, int discounts_list_size, int& cart_size, int* discount_required_products, int* product_ids, int*& product_ids_in_cart, float* discounts, float* product_prices, float*& product_prices_in_cart, int* discount_original_products, string* product_names, string*& product_names_in_cart, float& total);
//main
//Purpose: Display products available for purchase and get users input
//Pre condition: Product file must exist 
//Post condition: Close program when user is ready to checkout
int main() {

	//START Main

	//DECLARE product_ids, product_names, product_prices, product_ids_in_cart, product_names_in_cart, product_prices_in_cart, discount_required_products, 
	// discounts, discount_original_products and user_input
	int* product_ids = new int[0];
	float* product_prices = new float[0];
	int* product_ids_in_cart = new int[0];
	float* product_prices_in_cart = new float[0];
	int* discount_required_products = new int[0];
	float* discounts = new float[0];
	int* discount_original_products = new int[0];

	string* product_names = new string[0];
	string* product_names_in_cart = new string[0];
	int user_input = 0;

	//ASSIGN list_of_products_size to 1, ASSIGN discounts_list_size to 1 and ASSIGN cart_size to 1
	int list_of_products_size = 0;
	int discounts_list_size = 0;
	int cart_size = 0;
	float total = 0;

	//ASSIGN is_shopping to true
	bool is_shopping = true;

	//CALL get_products() and CALL get_discounts(discounts_list_size, discount_required_products, discount_original_products, discounts)
	get_products(product_ids, product_names, product_prices, list_of_products_size);
	get_discounts(discounts_list_size, discount_required_products, discount_original_products, discounts);

	//WHILE is_shopping IS true DO DISPLAY products from products file and checkout command 
	while (is_shopping == true)
	{

		//FOR every product in product_names OUTPUT product_names[i]
		for (int i = 0; i < 4; i++)
		{

			cout << "(" << product_ids[i] << ") " << product_names[i] << endl;

		}

		//OUTPUT Please select a product. If you're ready to checkout please enter -1
		cout << "Please select a product. If you're ready to checkout please enter -1" << endl;

		//ASSIGN user_input to user input
		cin >> user_input;

		//IF user_input >= 0 AND user_input <= list_of_products_size DO CALL check_discount_eligibility and CALL calculate_total
		if (user_input >= 0 && user_input <= list_of_products_size)
		{

			calculate_total(user_input, list_of_products_size, discounts_list_size, cart_size, discount_required_products, product_ids, product_ids_in_cart, discounts, product_prices, product_prices_in_cart, discount_original_products, product_names, product_names_in_cart, total);

		}
		//ELSE IF user_input IS -1 DO ASSIGN is_shopping to false
		else if (user_input == -1)
		{

			is_shopping = false;

		}
		//ELSE DO OUTPUT Please enter a valid input
		else
		{

			cout << "Please enter a valid input" << endl;

		}


	}


	//END	
	return 0;

}

//Get_discounts
//Author: Nate Hartway
//Objective : Get all of the discount information from the discounts file and sort the information into the correct arrays.Increment the arrays to how much information is in the file.
//Pre-condition : There must be a discounts file with information in it.
//Post-condition : Return three parallel arrays filled with the sorted discount information

void get_discounts(int& discounts_list_size, int*& discount_required_products, int*& discount_original_products, float*& discounts)
{

	//DECLARE file_reader, current_line, last_digit_pos and searcher
	fstream file_reader;
	string current_line;
	size_t last_digit_pos;
	size_t searcher;

	//INPUT file_reader
	file_reader.open("Discounts.txt");

	//WHILE file_reader != null 
	while (getline(file_reader, current_line))
	{

		//ASSIGN searcher to current_line.find_first_of("0123456789");
		searcher = current_line.find_first_of("0123456789");

		//IF searcher IS NOT NULL DO DECALRE temp_required_products, temp_original_products, and temp_discounts
		if (searcher != string::npos)
		{

			int* temp_required_products = new int[discounts_list_size + 1];
			int* temp_original_products = new int[discounts_list_size + 1];
			float* temp_discounts = new float[discounts_list_size + 1];

			//FOR evey entry in discount_required_products, discount_original_products and discounts 
			// DO ASSIGN temp_required_products[i] to discount_required_products[i], ASSIGN temp_original_products[i] to discount_original_products[i],
			//and ASSIGN temp_discounts[i] to discounts[i]
			if (discounts_list_size > 0)
			{

				for (int i = 0; i < discounts_list_size; i++)
				{

					temp_required_products[i] = discount_required_products[i];
					temp_original_products[i] = discount_original_products[i];
					temp_discounts[i] = discounts[i];

				}

			}

			//DECLARE col_1, col_2, col_3, and line_reader
			int col_1, col_2;
			float col_3;
			std::istringstream line_reader(current_line);

			//ASSIGN col_1, col_2, col_3 and to line_reader
			line_reader >> col_1 >> col_2 >> col_3;

			//ASSIGN temp_required_products[discounts_list_size] to col_1, ASSIGN temp_original_products[discounts_list_size] to col_2, and 
			//ASSIGN temp_discounts[discounts_list_size] to col_3
			temp_required_products[discounts_list_size] = col_1;
			temp_original_products[discounts_list_size] = col_2;
			temp_discounts[discounts_list_size] = col_3;

			//DELETE discount_required_products, discount_original_products, and discounts from memory
			delete[] discount_required_products;
			delete[] discount_original_products;
			delete[] discounts;

			//ASSIGN discount_required_products = temp_required_products, ASSIGN discount_original_products = temp_original_products, and 
			//ASSIGN discounts = temp_discounts
			discount_required_products = temp_required_products;
			discount_original_products = temp_original_products;
			discounts = temp_discounts;

			//CALC discounts_list_size++
			discounts_list_size++;

		}

	}

	file_reader.close();

}
//Get_discounts
//Author: Brad Hunt
//Objective : read product information from a productfile & produce it in main
//Pre-condition : There must be a products file with information in it.
//Post-condition : Return three parallel arrays filled with the sorted product information

void get_products(int*& product_ids, string*& product_names, float*& product_prices, int& list_of_products_size) {
	//DECLARE file_reader, current_line, last_digit_pos and searcher

	fstream file_reader;
	string current_line;
	size_t last_digit_pos;
	size_t searcher;



	//INPUT file_reader
	file_reader.open("Products.txt");
	while (getline(file_reader, current_line))
	{
		//ASSIGN searcher to current_line.find_first_of("0123456789");
		searcher = current_line.find_first_of("0123456789");
		//IF searcher IS NOT NULL DO DECALRE temp_required_products, temp_original_products, and temp_discounts

		if (searcher != string::npos)
		{
			int* temp_id = new int[list_of_products_size + 1];
			string* temp_name = new string[list_of_products_size + 1];
			float* temp_price = new float[list_of_products_size + 1];

			if (list_of_products_size > 0)
			{

				for (int i = 0; i < list_of_products_size; i++) {

					temp_id[i] = product_ids[i];
					temp_name[i] = product_names[i];
					temp_price[i] = product_prices[i];

				}

			}

			//DECLARE col_1, col_2, col_3, and line_reader
			int col_1;
			string col_2;
			float col_3;
			std::istringstream line_reader(current_line);

			//ASSIGN col_1, col_2, col_3 and to line_reader
			line_reader >> col_1 >> col_2 >> col_3;

			//ASSIGN temp_ID to col_1, ASSIGN temp_names to col_2, and
			//ASSIGN temp_price to col_3
			temp_id[list_of_products_size] = col_1;
			temp_name[list_of_products_size] = col_2;
			temp_price[list_of_products_size] = col_3;

			delete[] product_ids;
			delete[] product_names;
			delete[] product_prices;

			product_ids = temp_id;
			product_names = temp_name;
			product_prices = temp_price;


			list_of_products_size++;
		}
	}

	file_reader.close();

}

//Author: Ernesto Jaimes-Lara 
//Objective: Function to calculate items in cart 
//Pre-Condition: User adds valid product to cart 
//Post-Condition: Calculate and display items with total 

//START 



void calculate_total(int user_input, int list_of_products_size, int discounts_list_size, int& cart_size, int* discount_required_products, int* product_ids, int*& product_ids_in_cart, float* discounts, float* product_prices, float*& product_prices_in_cart, int* discount_original_products, string* product_names, string*& product_names_in_cart, float& total) {
	//DECLARE 2 variables for selected cost and item name
	string selected_product_name;
	float selected_product_cost;

	//FOR i < list_of_products_size IF user_input = product_ids THEN ASSIGN product_names to selected_product_name and THEN ASSIGN product_prices to selected_product_cost
	for (int i = 0; i < list_of_products_size; i++) {
		if (user_input == product_ids[i]) {
			selected_product_name = product_names[i];
			selected_product_cost = product_prices[i];
		}
	}
	//FOR j < discounts_list_size
	for (int j = 0; j < discounts_list_size; j++) {
		//IF user_input = discount_required_products
		if (user_input == discount_required_products[j]) {
			//THEN FOR k < cart_size IF product_ids_in_cart = discount_original_products
			for (int k = 0; k < cart_size; k++) {
				if (product_ids_in_cart[k] == discount_original_products[j]) {
					//THEN ASSIGN discounts to product_prices_in_cart
					product_prices_in_cart[k] = discounts[j];
				}
			}
		}
		//ELSE IF user_input = discount_original_products THEN FOR k < cart_size IF product_ids_in_cart = discount_required_products THEN ASSIGN discounts to selected_product_cost
		else if (user_input == discount_original_products[j]) {
			for (int k = 0; k < cart_size; k++) {
				if (product_ids_in_cart[k] == discount_required_products[j]) {
					selected_product_cost = discounts[j];
				}
			}
		}
	}
	//DECLARE temporary array variables 
	int* temp_ids = new int[cart_size + 1];
	float* temp_prices = new float[cart_size + 1];
	string* temp_names = new string[cart_size + 1];
	//FOR i < cart_size ASSIGN product_ids_in_cart, product_prices_in_cart, product_names_in_cart to temps
	for (int i = 0; i < cart_size; i++) {
		temp_ids[i] = product_ids_in_cart[i];
		temp_prices[i] = product_prices_in_cart[i];
		temp_names[i] = product_names_in_cart[i];
	}
	//ASSIGN user_input to temp_ids ASSIGN selected_product_cost to temp_prices, and ASSIGN selected_product_name to temp_names
	temp_ids[cart_size] = user_input;
	temp_prices[cart_size] = selected_product_cost;
	temp_names[cart_size] = selected_product_name;

	//DELETE product_ids_in_cart, product_prices_in_cart, and product_names_in_cart from memory
	delete[] product_ids_in_cart;
	delete[] product_prices_in_cart;
	delete[] product_names_in_cart;

	//ASSIGN temp_ids to product_ids_in_cart, ASSIGN temp_prices to product_prices_in_cart, and ASSIGN temp_names to product_names_in_cart
	product_ids_in_cart = temp_ids;
	product_prices_in_cart = temp_prices;
	product_names_in_cart = temp_names;

	//cart_size++
	cart_size++;

	total = 0;
	//OUTPUT current items in cart
	cout << "Items in Cart: " << endl;
	//FOR i < cart_size OUTPUT product_prices_in_cart with product_prices_in_cart and CALCULATE total
	for (int i = 0; i < cart_size; i++) {
		cout << product_names_in_cart[i] << ": " << fixed << setprecision(2) << product_prices_in_cart[i] << endl;
		total += product_prices_in_cart[i];
	}

	//OUTPUT total
	cout << "Cart Total: " << fixed << setprecision(2) << total << endl;
}
