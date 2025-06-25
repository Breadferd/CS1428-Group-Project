//Author(s): Nate Hartway
//Purpose: Allow a user to purchase products from a grocery store. When the user is ready to checkout show them what theyre purchasing and their total.
//Date:6/21/2025
//Version:v0.3

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

void get_discounts(int& discounts_list_size, int* discount_required_products, int* discount_original_products, float* discounts);
void get_products(string product_ids[], string product_names[], double* product_prices[], int* list_size);

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
	int user_input;

	//ASSIGN list_of_products_size to 1, ASSIGN discounts_list_size to 1 and ASSIGN cart_size to 1
	int list_of_products_size = 0;
	int discounts_list_size = 0;
	int cart_size = 0;

	//ASSIGN is_shopping to true
	bool is_shopping = true;

	//CALL get_products() and CALL get_discounts(discounts_list_size, discount_required_products, discount_original_products, discounts)
	get_discounts(discounts_list_size, discount_required_products, discount_original_products, discounts);

	//WHILE is_shopping IS true DO DISPLAY products from products file and checkout command 
	while (is_shopping == true)
	{

		//FOR every product in product_names OUTPUT product_names[i]
		for (int i = 0; i < list_of_products_size; i++)
		{

			cout << product_names[i] << endl;

		}

		//OUTPUT Please select a product. If you're ready to checkout please enter -1
		cout << "Please select a product. If you're ready to checkout please enter -1" << endl;

		//ASSIGN user_input to user input
		cin >> user_input;

		//IF user_input >= 0 AND user_input <= list_of_products_size DO CALL check_discount_eligibility and CALL calculate_total
		if (user_input >= 0 && user_input <= list_of_products_size)
		{



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

void get_discounts(int &discounts_list_size, int* discount_required_products, int* discount_original_products, float* discounts)
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
			for (int i = 0; i < discounts_list_size; i++)
			{

				temp_required_products[i] = discount_required_products[i];
				temp_original_products[i] = discount_original_products[i];
				temp_discounts[i] = discounts[i];

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

}

void get_products(string product_ids[], string product_names[], double* product_prices[], int* list_size) {
    string current_line;

	size_t last_digit_pos;
	size_t searcher;
    list_size = 0;
		if (searcher != string::npos)
		{
	string temp_id 
        string temp_name;
        double temp_price;
			
    cout << "Enter product ID, Name, and Price" << endl;

    for (i=0; list_size > i; i++) {
        cout << "Product " << list_size + 1 << ": ";
        cin >> current_line;


	temp_id = current_line; 


        cin >> temp_name >> temp_price;

        product_ids[i] = temp_id;
        product_names[i] = temp_name;
        product_prices[i] = temp_price; }

                                    
		}
				//DECLARE col_1, col_2, col_3, and line_reader
			int col_1, col_2;
			float col_3;
			std::istringstream line_reader(current_line);

			//ASSIGN col_1, col_2, col_3 and to line_reader
			line_reader >> col_1 >> col_2 >> col_3;

			//ASSIGN temp_ID to col_1, ASSIGN temp_names to col_2, and 
			//ASSIGN temp_price to col_3
			temp_id[list_size] = col_1;
			temp_name[list_size] = col_2;
			temp_price[list_size] = col_3;
}
