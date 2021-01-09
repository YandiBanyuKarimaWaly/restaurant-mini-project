#include <iostream>

#include "cli.hpp"

CLI::Action CLI::MenuCLI::listMenuResto()
{
    std::cout << "List Menu" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    CLI::Utilities::print("Nomor", 7);
    CLI::Utilities::print("Nama", 30);
    CLI::Utilities::print("Stok", 10);
    CLI::Utilities::print("Harga", 20);
    CLI::Utilities::print("Diskon", 20);
    std::cout << std::endl;

    std::vector<Stok> menu = resto.getMenu();
    std::uint32_t counter = 1;
    for (auto item : menu)
    {
        CLI::Utilities::print(counter, 7);
        CLI::Utilities::print(item.getNama(), 30);
        CLI::Utilities::print(item.getJumlah(), 10);
        CLI::Utilities::printMoney(item.getHarga(), 20);
        CLI::Utilities::printMoney(item.getDiskon(), 20);
        std::cout << std::endl;
        counter++;
    }

    std::cout << std::endl;

    return Action::GotoMainMenu;
}

CLI::Action CLI::MenuCLI::addMenuResto()
{
    Menu menu;
    std::string nama, hargaStr, stokStr, diskonStr;

    std::cout << "Nama menu: ";
    std::getline(std::cin, nama);
    std::cout << "Harga: Rp. ";
    std::getline(std::cin, hargaStr);
    std::cout << "Stok: ";
    std::getline(std::cin, stokStr);
    std::cout << "Diskon: Rp. ";
    std::getline(std::cin, diskonStr);
    std::cout << std::endl;

    menu.setNama(nama);
    menu.setHarga(static_cast<uint32_t>(std::stoull(hargaStr)) * 100);
    menu.setDiskon(static_cast<uint32_t>(std::stoull(diskonStr)) * 100);
    resto.addMenu(menu, static_cast<uint32_t>(std::stoull(stokStr)));

    return Action::ListMenuResto;
}

CLI::Action CLI::MenuCLI::editMenuResto()
{
    std::cout << "Edit Menu" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    CLI::Utilities::print("Nomor", 7);
    CLI::Utilities::print("Nama", 30);
    CLI::Utilities::print("Stok", 10);
    CLI::Utilities::print("Harga", 20);
    CLI::Utilities::print("Diskon", 20);
    std::cout << std::endl;

    std::vector<Stok> menu = resto.getMenu();
    std::uint32_t counter = 1;
    for (auto item : menu)
    {
        CLI::Utilities::print(counter, 7);
        CLI::Utilities::print(item.getNama(), 30);
        CLI::Utilities::print(item.getJumlah(), 10);
        CLI::Utilities::printMoney(item.getHarga(), 20);
        CLI::Utilities::printMoney(item.getDiskon(), 20);
        std::cout << std::endl;
        counter++;
    }

    std::cout << "Pilih Nomor: ";

    std::string chooseStr;
    std::getline(std::cin, chooseStr);
    std::uint32_t choose = static_cast<uint32_t>(std::stoull(chooseStr));

    std::cout << std::endl;

    if (choose > counter || choose == 0)
    {
        std::cout << "Pilihan tidak valid, silahkan ulangi lagi" << std::endl
                  << std::endl;
        return Action::EditMenuResto;
    }

    std::string newNama, newHarga, newDiskon, newStok;
    std::cout << "Nama baru (" << menu[choose-1].getNama() << "): ";
    std::getline(std::cin, newNama);
    std::cout << "Harga baru (Rp" << menu[choose-1].getHarga()/100 << "): ";
    std::getline(std::cin, newHarga);
    std::cout << "Stok baru (" << menu[choose-1].getJumlah() << "): ";
    std::getline(std::cin, newStok);
    std::cout << "Diskon baru (Rp" << menu[choose-1].getDiskon()/100 << "): ";
    std::getline(std::cin, newDiskon);

    Menu newMenu;
    newMenu.setNama(newNama);
    newMenu.setHarga(static_cast<uint32_t>(std::stoull(newHarga)) * 100);
    newMenu.setDiskon(static_cast<uint32_t>(std::stoull(newDiskon)) * 100);
    resto.editMenu(menu[choose-1], newMenu, static_cast<uint32_t>(std::stoull(newStok)));

    std::cout << std::endl;

    return Action::ListMenuResto;
}

CLI::Action CLI::MenuCLI::deleteMenuResto()
{
    std::cout << "Delete Menu" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    CLI::Utilities::print("Nomor", 7);
    CLI::Utilities::print("Nama", 30);
    CLI::Utilities::print("Stok", 10);
    CLI::Utilities::print("Harga", 20);
    CLI::Utilities::print("Diskon", 20);
    std::cout << std::endl;

    std::vector<Stok> menu = resto.getMenu();
    std::uint32_t counter = 1;
    for (auto item : menu)
    {
        CLI::Utilities::print(counter, 7);
        CLI::Utilities::print(item.getNama(), 30);
        CLI::Utilities::print(item.getJumlah(), 10);
        CLI::Utilities::printMoney(item.getHarga(), 20);
        CLI::Utilities::printMoney(item.getDiskon(), 20);
        std::cout << std::endl;
        counter++;
    }

    std::cout << "Pilih Nomor: ";

    std::string chooseStr;
    std::getline(std::cin, chooseStr);
    std::uint32_t choose = static_cast<uint32_t>(std::stoull(chooseStr));

    std::cout << std::endl;

    if (choose > counter)
    {
        std::cout << "Pilihan tidak valid, silahkan ulangi lagi" << std::endl
                  << std::endl;
        return Action::DeleteMenuResto;
    }

    resto.deleteMenu(menu[choose-1]);

    return Action::ListMenuResto;
}