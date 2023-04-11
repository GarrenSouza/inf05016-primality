
#include <prime.hpp>
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    local::initialize_primality_env();

    mpz_t possibly_prime, composite_witness;
    mpz_init(possibly_prime);
    mpz_init(composite_witness);

    string input;
    cin >> input;

    FILE *tmpFile;
    tmpFile = tmpfile();
    fwrite(input.c_str(), sizeof(char), input.size(), tmpFile);
    fseek(tmpFile, 0, SEEK_SET);

    mpz_inp_str(possibly_prime, tmpFile, 10);

    if (local::primality_test(possibly_prime, composite_witness))
        cout << "possibly prime\n";
    else
        cout << "composite\n";

    return 0;
}
