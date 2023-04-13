
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

    while (cin >> input) {
        numbers.push_back(input);
    }

    cout << "n_digits;median(ns);min(ns);max(ns)\n";

    for (auto &s: numbers) {
        vector<uint64_t> laps;
        mpz_set_str(possibly_prime, s.c_str(), 10);
        for (int i = 0; i < 20; ++i) {
            auto start = chrono::system_clock::now();
            local::primality_test(possibly_prime, composite_witness);
            laps.push_back(chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now() - start).count());
        }
        assert(laps.size() == 20);
        sort(laps.begin(), laps.end());
        cout << s.size() << ';' << ((laps[laps.size() / 2] + laps[laps.size() / 2 - 1]) / 2) << ';' << laps[0] << ';'
             << laps[19] << '\n';
        laps.clear();
    }

    return 0;
}
