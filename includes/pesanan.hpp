#ifndef PESANAN_HPP
#define PESANAN_HPP

#include "menu.hpp"

class Pesanan : protected Menu {
    private:
        std::string _catatan;
        std::uint32_t _jumlah;
    
    public:
        Pesanan(Menu menu) : Menu(menu) {}
        std::string getCatatan();
        std::string getNama();
        std::uint32_t getJumlah();
        std::uint32_t getHarga();
        std::uint32_t getDiskon();

        void setCatatan(std::string);
        void setCatatan(const char*);
        void setJumlah(std::uint32_t);

        bool operator == (Pesanan);
};

#endif