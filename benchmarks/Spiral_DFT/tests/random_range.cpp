#include <random>
#include <cmath>

static unsigned int seed;
static std::default_random_engine gen;

double getRandNumUniform(int magnitude) {
    static std::uniform_int_distribution<int> distribution(0.0);

    int rnum = distribution(gen);

    double min = pow(2, magnitude);
    double max = pow(2, magnitude+1);

    return (max - min) * ( (double)(rnum + 1) / (double)INT32_MAX ) + min;
}

double getRandomPositiveDouble(int min_exp, int dyn_range) {
    std::uniform_int_distribution<int> distribution(min_exp,min_exp + dyn_range);
    int rand_magintud = distribution(gen);

    return getRandNumUniform(rand_magintud);
}

///
/// \param neg : Percentage of negative numbers (0-100)
/// \param min_exp : Minimum exponent to generate random number
/// \param dyn_range : Dynamic range in bits
/// \return random number r = [2^(min_exp), 2^(min_exp + dyn_range)]
///
double getRandomDouble(int min_exp, int dyn_range, size_t neg = 0) {
    static std::uniform_int_distribution<int> distribution(0,99);
    int coin = distribution(gen);
    double r_num = getRandomPositiveDouble(min_exp, dyn_range);
    if (coin < neg) {
        r_num = -r_num;
    }

    return r_num;
}

void initRandomSeed() {
    static std::random_device r;
    seed = r();
    gen.seed(seed);
}

void restartRandomGenSeed() {
    gen.seed(seed);
}