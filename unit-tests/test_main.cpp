#include "test_math.hh"

int main(int argc, char** argv)
{
    int status = 0;
    {
        TestMath testCase;
        status |= QTest::qExec(&testCase, argc, argv);
    }
//    {
//        TestSubject testCase;
//        status |= QTest::qExec(&testCase, argc, argv);
//    }
    return status;
}
