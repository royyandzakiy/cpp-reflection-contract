#include <iostream>
#include <contracts> // For std::contracts::contract_violation
#include <source_location>

// C++26 uses the new 'pre' and 'post' keywords directly in the function signature
int Withdraw(int balance, int amount)
	pre(amount > 0)
		pre(amount <= balance)
			post(result : result >= 0)
{
	// You can also use contract_assert for internal logic checks
	contract_assert(balance >= 0);

	return balance - amount;
}

/**
 * In C++26, if a contract is violated, the implementation calls
 * the contract-violation handler. You can define your own:
 */
void handle_contract_violation(const std::contracts::contract_violation &violation)
{
	// Get the source location (file, line, function name)
	std::source_location loc = violation.location();

	std::cerr << "--- Contract Violation Detected ---" << "\n";

	// The comment usually contains the text of the failed predicate
	std::cerr << "Predicate: " << violation.comment() << "\n";

	// Accessing location details via std::source_location
	std::cerr << "Location:  " << loc.file_name() << ":" << loc.line()
			  << " in " << loc.function_name() << "\n";

	// Check if the program is about to terminate based on evaluation semantics
	if (violation.is_terminating())
	{
		std::cerr << "Action:    The program will now terminate." << "\n";
	}
	else
	{
		std::cerr << "Action:    Continuing execution (Observe semantic)." << "\n";
	}

	std::cerr << "-----------------------------------" << std::endl;
}

int main()
{
	int balance = 100;
	int amount = 40;

	// Standard execution
	int new_balance = Withdraw(balance, amount);

	std::cout << "Old balance: " << balance << "\n";
	std::cout << "Withdrawn:   " << amount << "\n";
	std::cout << "New balance: " << new_balance << "\n";

	return 0;
}