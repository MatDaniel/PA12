#ifndef TST_REMOVELAGERBEDINGUNGENBEFEHL_H
#define TST_REMOVELAGERBEDINGUNGENBEFEHL_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

#include <string>
#include <vector>
#include "regalcontroller.h"
#include "befehle/removelagerbedingungenbefehl.h"

TEST(RemoveLagerbedingungenBefehlSuite, RemoveTest)
{

    RegalController controller(1, 2, 3);
    RemoveLagerbedingungenBefehl befehl(controller);
    auto palette = controller[5];
    palette->setLagerbedingungen("Kalt einlagern!");

    std::vector<std::string> testing_args { "5" };
    befehl.exec(testing_args);
    EXPECT_FALSE(palette->hasLagerbedingungen());

}

#endif // TST_REMOVELAGERBEDINGUNGENBEFEHL_H
