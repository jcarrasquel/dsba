#ifndef TST_MYCASE_H
#define TST_MYCASE_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

struct BankAccount
{
    double balance;
    BankAccount()
    {
        balance = 0;
    }
    void deposit(double money){
        balance += money;
    }
};

TEST(MySuite, MyCase)
{
    BankAccount bankAccount;
    EXPECT_EQ(0, bankAccount.balance);
}

TEST(MySuite, DepositOK)
{
    BankAccount bankAccount;
    bankAccount.deposit(1000);
    EXPECT_EQ(1000, bankAccount.balance);
}

#endif // TST_MYCASE_H
