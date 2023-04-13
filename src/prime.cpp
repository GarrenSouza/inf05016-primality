
#include <prime.hpp>
#include <iostream>

namespace local {

    gmp_randstate_t __state;
    mpz_t zero, one, two;
    mpz_t  u, rop1, rop2, t, i, c;

    pt_prov prov;

    void initialize_primality_env() {
        gmp_randinit_default(__state);
        mpz_init_set_ui(zero, 0);
        mpz_init_set_ui(one, 1);
        mpz_init_set_ui(two, 2);
        mpz_init(prov.a);
        mpz_init(prov.t);
        mpz_init(prov.u);
        mpz_init(prov.rop1);
        mpz_init(prov.i);
        mpz_init(c);
        mpz_init(t);
        mpz_init(u);
        mpz_init(rop1);
        mpz_init(rop2);
        mpz_init(i);
    }

    void factor(const mpz_t &n, mpz_t &t, mpz_t &u) {
        static const mp_bitcnt_t _two = 1;

        mpz_set(u, n);
        mpz_set_ui(t, 0);
        while (mpz_even_p(u) && mpz_cmp(u, zero) > 0) {
            mpz_cdiv_q_2exp(u, u, _two);
            mpz_add_ui(t, t, 1);
        }
    }

    bool primality_test(mpz_t &n, mpz_t &a) {


        // 'a' is a random number in the range [0, n-1]
        do {
            mpz_urandomm(a, __state, n);
        } while (mpz_cmp_ui(a, 0) == 0);

        // gcd(a, n) != 1 test
        mpz_gcd(rop1, n, a);
        if (mpz_cmp(rop1, one) != 0)
            return false;

        // n - 1 = 2^t*u
        mpz_sub_ui(rop2, n, 1); // rop2 = n - 1
        factor(rop2, t, u);

        // if a^u is congruent to 1 mod n -> yes
        mpz_powm(rop1, a, u, n);
        if (mpz_cmp(rop1, one) == 0)
            return true;

        // if (a^u)^(2^i) is congruent to -1 for any i in [0, t -1] -> yes
        mpz_set(i, zero);
        for (; mpz_cmp(i, t) < 0; mpz_add_ui(i, i, 1))
            if (mpz_cmp_si(rop1, -1) == 0)
                return true;
            else
                mpz_powm_ui(rop1, rop1, 2, n);

        return false;
    }
}
