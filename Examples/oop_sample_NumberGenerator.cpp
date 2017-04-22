#include "simple_test.h"

// а)
class NumberGenerator
{
public:
    virtual int nextInt() = 0;

    // NEVER FORGET A VIRTUAL DESTRUCTOR WHEN USING VIRTUAL METHODS
    virtual ~NumberGenerator() {}
};

// б)
class SequenceGenerator : public NumberGenerator
{
private:
    int _nextValue;

protected:
    virtual int calcNext(int previous) = 0;

public:
    SequenceGenerator(int baseNumber) : _nextValue(baseNumber) {}

    int nextInt() {
        int result = _nextValue;
        _nextValue = calcNext(result);
        return result;
    }
};

// в)
class ArithmeticProgressionGen  : public SequenceGenerator
{
private:
    int _increment;

protected:
    int calcNext(int previous) {
        return previous + _increment;
    }

public:
    ArithmeticProgressionGen(int baseNumber, int increment)
        : SequenceGenerator(baseNumber), _increment(increment)
    {}
};

// г)
class GeometricProgressionGen  : public SequenceGenerator
{
private:
    int _factor;

protected:
    int calcNext(int previous) {
        return previous * _factor;
    }

public:
    GeometricProgressionGen(int baseNumber, int factor)
        : SequenceGenerator(baseNumber), _factor(factor)
    {}
};

// EXAMPLE USAGE
void fillInNumbers(int arr[], int size, NumberGenerator& generator) {
    for (int i=0; i < size; i++) {
        arr[i] = generator.nextInt();
    }
}

int main() {
    int sample[4];
    
    int expectedNaturals[4] = {1, 2, 3, 4};
    ArithmeticProgressionGen naturals(1, 1);
    fillInNumbers(sample, 4, naturals);
    CHECK_ARR_EQUAL(sample, expectedNaturals);
    // [SUCCEEDED] Equality check for 'sample'='1, 2, 3, 4' and 'expectedNaturals'='1, 2, 3, 4'

    int expectedPowersOfMinus3[4] = {-3, 9, -27, 81};
    GeometricProgressionGen powersOfMinus3(-3, -3);
    fillInNumbers(sample, 4, powersOfMinus3);
    CHECK_ARR_EQUAL(sample, expectedPowersOfMinus3);
    // [SUCCEEDED] Equality check for 'sample'='-3, 9, -27, 81' and 'expectedPowersOfMinus3'='-3, 9, -27, 81'

    return 0;
}