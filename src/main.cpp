
#include <prime.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <cassert>

using namespace std;

int main() {
    local::initialize_primality_env();
    vector<string> numbers;

    mpz_t possibly_prime, composite_witness;
    mpz_init(possibly_prime);
    mpz_init(composite_witness);

    string input;

    cin >> input;

    mpz_set_str(possibly_prime, input.c_str(), 10);
    if (local::primality_test(possibly_prime, composite_witness))
        cout << "s\n";
    else
        cout << "n\n";

    return 0;
}
