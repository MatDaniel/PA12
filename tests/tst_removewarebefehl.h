#ifndef TST_REMOVEWAREBEFEHL_H
#define TST_REMOVEWAREBEFEHL_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

#include <string>
#include <vector>
#include "regalcontroller.h"
#include "befehle/removewarebefehl.h"

TEST(RemoveWareBefehlSuite, RemoveTest)
{

    RegalController controller(1, 2, 3);
    auto palette = controller[5];

    palette->setWare("Pizza");
    palette->setAnzahl(42);
    palette->setLagerbedingungen("Kalt einlagern!");

    RemoveWareBefehl befehl(controller);
    std::vector<std::string> testing_args;
    testing_args.push_back("5");
    befehl.exec(testing_args);

    EXPECT_TRUE(palette->empty());
    EXPECT_EQ(palette->anzahl(), 0);
    EXPECT_FALSE(palette->hasLagerbedingungen());

}

#endif // TST_REMOVEWAREBEFEHL_H
