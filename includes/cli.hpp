#ifndef CLI_HPP
#define CLI_HPP

#include <iostream>
#include <iomanip>

#include "restaurant.hpp"

namespace CLI
{
    enum Action
    {
        Quit,
        GotoMainMenu,

        ListMenuResto,
        AddMenuResto,
        EditMenuResto,
        DeleteMenuResto,

        ReviewPesanan,
        CreatePesanan,
        AddPesanan,
        EditPesanan,
        DeletePesanan,

        Pesan,
        ListInvoice,
        HitungPenjualan,
    };

    extern Restaurant resto;
    extern Invoice invoiceTmp;
    extern Menu menuTmp;
    extern bool loggedIn;

    void handleCLI(Restaurant &);
    namespace Utilities {
        template<typename T> void print(T t, const int& width, char fill = ' ')
        {
            std::cout << std::left << std::setw(width) << std::setfill(fill) << t;
        }

        template<typename T> void printMoney(T t, const int& width)
        {
            std::cout.imbue(std::locale("id_ID.UTF-8"));
            std::cout << std::showbase << std::left << std::setw(width) << std::setfill(' ') << std::put_money(t) << std::noshowbase;
        }
    }
    namespace MenuCLI
    {
        Action main();

        // Menu resto
        Action listMenuResto();
        Action addMenuResto();
        Action editMenuResto();
        Action deleteMenuResto();

        // Pemesanan
        Action reviewPesanan();
        Action createPesanan();
        Action addPesanan();
        Action editPesanan();
        Action deletePesanan();

        // Invoice resto
        Action pesan();
        Action listInvoice();
        Action hitungPenjualan();
    }; // namespace Menu
};     // namespace CLI

#endif