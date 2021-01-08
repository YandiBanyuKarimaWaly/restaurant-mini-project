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
        std::uint32_t getJumlah();

        void setCatatan(std::string);
        void setCatatan(const char*);
        void setJumlah(std::uint32_t);

        bool operator == (Menu);
};

#endif