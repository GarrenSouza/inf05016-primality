
#ifndef LOCAL_PRIME
#define LOCAL_PRIME

#include <gmpxx.h>

namespace local {

    typedef struct prim_test_prov {
        gmp_randstate_t __state;
        mpz_t zero, one, two;
        mpz_t a, u, rop1, rop2, t, i;
    } pt_prov;

    extern pt_prov prov;

    void factor(const mpz_t &n, mpz_t &t, mpz_t &u);

    void initialize_primality_env();

    bool primality_test(mpz_t& n, mpz_t& a);
}

#endif