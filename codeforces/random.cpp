#include <iostream>
#include <random>

int main() {
    // Seed with a real random value, if available
    std::random_device rd;

    // Initialize Mersenne Twister with the random seed
    std::mt19937 gen(rd());

    // Define the range for the random numbers (optional, you can modify as needed)
    std::uniform_int_distribution<> dis(1, 5); // Generates numbers in the range [1, 100]

    // Generate two random numbers
    int random_num1 = dis(gen);
    int random_num2 = dis(gen);

    // Output the random numbers
    std::cout << "Random Number 1: " << random_num1 << std::endl;
    std::cout << "Random Number 2: " << random_num2 << std::endl;

    return 0;
}
