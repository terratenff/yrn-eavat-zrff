#include "test_math.hh"
#include "test_inputoutput.hh"
#include "test_fitness.hh"

int main(int argc, char** argv)
{
    int status = 0;
    {
        TestMath testCase;
        status |= QTest::qExec(&testCase, argc, argv);
    }
    {
        TestInputOutput testCase;
        status |= QTest::qExec(&testCase, argc, argv);
    }
    {
        TestFitness testCase;
        status |= QTest::qExec(&testCase, argc, argv);
    }
    return status;
}
