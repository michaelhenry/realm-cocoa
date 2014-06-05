#include "test_only.hpp"

namespace {

struct TestOnly {
    const char* m_test_name;
    TestOnly():
        m_test_name(0)
    {
    }
};

TestOnly& access_test_only()
{
    static TestOnly x;
    return x;
}

} // anonymous namespace

namespace tightdb {
namespace test_util {

SetTestOnly::SetTestOnly(const char* test_name)
{
    TestOnly& test_only = access_test_only();
    test_only.m_test_name = test_name;
}

const char* get_test_only()
{
    TestOnly& test_only = access_test_only();
    return test_only.m_test_name;
}

} // namespace test_util
} // namespace tightdb