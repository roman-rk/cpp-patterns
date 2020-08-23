#include <iostream>

struct Command
{
  enum Action { deposit, withdraw } action;
  int amount{0};
  bool success{false};
};

struct Account
{
  int balance{0};

  void process(Command& cmd)
  {
    switch(cmd.action)
    {
      case Command::Action::deposit:
        balance += cmd.amount;
        cmd.success = true;
        return;
      case Command::Action::withdraw:
        if (balance >= cmd.amount)
        {
          balance -= cmd.amount;
          cmd.success = true;
          return;
        }
        else
        {
          cmd.success = false;
          return;
        }
      default:
        cmd.success = false;
    }
  }
};

int main()
{
  Command c{Command::Action::deposit, 100, false};
  Account a;
  a.process(c);
  std::cout << a.balance;
}