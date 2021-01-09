#include <iostream>

#include "cli.hpp"

Restaurant CLI::resto;
Menu CLI::menuTmp;
Invoice CLI::invoiceTmp;
bool CLI::loggedIn;

void CLI::handleCLI(Restaurant &restaurant)
{
    resto = restaurant;
    Action nextAction = MenuCLI::main();
    while (nextAction != Action::Quit)
    {
        switch (nextAction)
        {
        case Action::GotoMainMenu:
            nextAction = MenuCLI::main();
            break;

        case Action::ListMenuResto:
            nextAction = MenuCLI::listMenuResto();
            break;

        case Action::AddMenuResto:
            nextAction = MenuCLI::addMenuResto();
            break;

        case Action::EditMenuResto:
            nextAction = MenuCLI::editMenuResto();
            break;

        case Action::DeleteMenuResto:
            nextAction = MenuCLI::deleteMenuResto();
            break;

        case Action::ReviewPesanan:
            nextAction = MenuCLI::reviewPesanan();
            break;

        case Action::AddPesanan:
            nextAction = MenuCLI::addPesanan();
            break;

        case Action::CreatePesanan:
            nextAction = MenuCLI::createPesanan();
            break;

        case Action::EditPesanan:
            nextAction = MenuCLI::editPesanan();
            break;

        case Action::DeletePesanan:
            nextAction = MenuCLI::deletePesanan();
            break;

        case Action::Pesan:
            nextAction = MenuCLI::pesan();
            break;

        case Action::ListInvoice:
            nextAction = MenuCLI::listInvoice();
            break;

        case Action::HitungPenjualan:
            nextAction = MenuCLI::hitungPenjualan();
            break;

        default:
            nextAction = Action::Quit;
            break;
        }
    }
}

CLI::Action CLI::MenuCLI::main()
{
    std::string chooseStr;
    std::cout << "Main Menu" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "1. Lihat menu yang ada" << std::endl;
    std::cout << "2. Pesan" << std::endl;

    if (loggedIn)
    {
        std::cout << "3. Tambah menu" << std::endl;
        std::cout << "4. Edit menu" << std::endl;
        std::cout << "5. Hapus menu" << std::endl;
    }

    (loggedIn) ? std::cout << "l. Logout" << std::endl : std::cout << "l. Login" << std::endl;
    std::cout << "q. Keluar" << std::endl;
    std::cout << "Pilih menu: ";
    std::getline(std::cin, chooseStr);
    std::cout << std::endl;

    char choose = chooseStr.c_str()[0];
    if (choose == '1' || choose == 1)
    {
        return CLI::Action::ListMenuResto;
    }

    if (choose == '2' || choose == 2)
    {
        return CLI::Action::CreatePesanan;
    }

    if (loggedIn && (choose == '3' || choose == 3))
    {
        return CLI::Action::AddMenuResto;
    }

    if (loggedIn && (choose == '4' || choose == 4))
    {
        return CLI::Action::EditMenuResto;
    }

    if (loggedIn && (choose == '5' || choose == 5))
    {
        return CLI::Action::DeleteMenuResto;
    }

    if (choose == 'l' || choose == 'L')
    {
        if (loggedIn)
        {
            loggedIn = false;
            return Action::GotoMainMenu;
        } else {
            std::cout << "Password: ";
            std::string password;
            std::getline(std::cin, password);
            std::cout << std::endl;
            if (password.compare("l33tsupah4x0r") == 0)
            {
                loggedIn = true;
            } else {
                std::cout << "Maaf, password salah. Silahkan coba lagi" << std::endl;
            }

            return Action::GotoMainMenu;
        }
    }

    if (choose == 'q' || choose == 'Q')
    {
        return CLI::Action::Quit;
    }

    std::cout << "Pilihan tidak valid, silahkan ulangi lagi" << std::endl << std::endl;
    return CLI::Action::GotoMainMenu;
}