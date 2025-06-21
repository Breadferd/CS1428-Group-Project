//Author(s): Nate Hartway
//Purpose: Allow a user to purchase products from a grocery store. When the user is ready to checkout show them what theyre purchasing and their total.
//Date:6/21/2025
//Version:v0.1

#include <iostream>
#include <string>
using namespace std;

//main
//Purpose: Display products available for purchase and get users input
//Pre condition: Product file must exist 
//Post condition: Close program when user is ready to checkout
int main() {

//START Main
 
	//DECLARE product_ids, product_names, product_prices, product_ids_in_cart, product_names_in_cart, product_prices_in_cart, and user_input
	int product_ids[1], product_prices[1], product_ids_in_cart[1], product_prices_in_cart[1];
	string 	product_names[1], product_names_in_cart[1];
	int user_input;

	//ASSIGN list_of_products_size to 1 and ASSIGN cart_size to 1
	int list_of_products_size = 1;
	int cart_size = 1;

	//ASSIGN is_shopping to true
	bool is_shopping = true;

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

		//IF user_input >= 0 OR user_input <= list_of_products_size DO CALL check_discount_eligibility and CALL calculate_total
		if (user_input >= 0 || user_input <= list_of_products_size)
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