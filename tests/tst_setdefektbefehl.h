#ifndef TST_SETDEFEKTBEFEHL_H
#define TST_SETDEFEKTBEFEHL_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

#include <string>
#include <vector>
#include "regalcontroller.h"
#include "befehle/setdefektbefehl.h"

TEST(SetDefektBefehlSuite, SetTest)
{

    RegalController controller(1, 2, 3);
    SetDefektBefehl befehl(controller);
    auto palette = controller[5];

    std::vector<std::string> testing_args0 { "5", "true" };
    befehl.exec(testing_args0);
    EXPECT_TRUE(palette->defekt());

    std::vector<std::string> testing_args1 { "5", "lul" };
    befehl.exec(testing_args1);
    EXPECT_TRUE(palette->defekt());

    std::vector<std::string> testing_args2 { "5", "false" };
    befehl.exec(testing_args2);
    EXPECT_FALSE(palette->defekt());

    std::vector<std::string> testing_args3 { "5", "lul" };
    befehl.exec(testing_args3);
    EXPECT_FALSE(palette->defekt());

}


#endif // TST_SETDEFEKTBEFEHL_H
