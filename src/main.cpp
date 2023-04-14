
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

    mpz_t possibly_prime, base, i, f;
    mpz_init(possibly_prime);
    mpz_init(base);
    mpz_init(i);
    mpz_init(f);

    mpf_t n_f, d_f;
    mpf_init(n_f);
    mpf_init(d_f);

    string input;

    cout << "d;false_positives\n";
    while (cin >> input) {
        mpz_set_str(possibly_prime, input.c_str(), 10);

        mpf_set_z(d_f, possibly_prime);
        mpz_set_ui(f, 0);

        for (mpz_set_ui(i, 1); mpz_cmp(i, possibly_prime) < 0; mpz_add_ui(i, i, 1))
            if (local::primality_test(possibly_prime, i)) mpz_add_ui(f, f, 1);

        mpf_set_z(n_f, f);
        mpf_div(d_f, n_f, d_f);
        cout << input.size() << ";";
        gmp_printf ("%.Ff\n", d_f);
    }

    return 0;
}
