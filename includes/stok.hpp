#ifndef STOK_HPP
#define STOK_HPP

#include "menu.hpp"

class Stok : protected Menu {
    private:
        std::uint32_t _jumlah;
    
    public:
        Stok(Menu menu) : Menu(menu) {}
        std::uint32_t getJumlah();

        void setJumlah(std::uint32_t);

        bool operator== (Menu);
};

#endif