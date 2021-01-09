#ifndef STOK_HPP
#define STOK_HPP

#include "menu.hpp"
#include "pesanan.hpp"

class Stok : protected Menu {
    private:
        std::uint32_t _jumlah;
    
    public:
        Stok(Menu menu) : Menu(menu) {}
        std::uint32_t getJumlah();
        std::string getNama();
        std::uint32_t getHarga();
        std::uint32_t getDiskon();

        void setJumlah(std::uint32_t);

        bool operator== (Stok);
        bool operator== (Pesanan);
};

#endif