#include "restaurant.hpp"
#include "cli.hpp"

int main(int argc, char* argv[])
{
   Restaurant resto;
   CLI::handleCLI(resto);
   return 0;
}