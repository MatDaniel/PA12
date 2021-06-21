#ifndef TST_EXITBEFEHL_H
#define TST_EXITBEFEHL_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

#include <string>
#include <vector>
#include "befehle/exitbefehl.h"

TEST(ExitBefehlSuite, ExitTest)
{

    ExitBefehl befehl;
    std::vector<std::string> testing_args;
    EXPECT_EXIT(befehl.exec(testing_args), ExitedWithCode(0), "");

}


#endif // TST_EXITBEFEHL_H
