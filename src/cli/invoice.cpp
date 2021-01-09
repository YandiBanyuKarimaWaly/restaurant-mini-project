#include "cli.hpp"

CLI::Action CLI::MenuCLI::pesan()
{
    resto.pesan(invoiceTmp);
    return Action::ListMenuResto;
}

CLI::Action CLI::MenuCLI::listInvoice()
{
    return Action::GotoMainMenu;
}

CLI::Action CLI::MenuCLI::hitungPenjualan()
{
    return Action::GotoMainMenu;
}