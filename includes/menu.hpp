#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <cstdint>

class Menu {
    private:
        std::string _nama;
        std::uint32_t _harga;
        std::uint32_t _diskon;

    public:
        std::string getNama();
        std::uint32_t getHarga();
        std::uint32_t getDiskon();

        void setNama(std::string);
        void setNama(const char*);
        void setHarga(std::uint32_t);
        void setDiskon(std::uint32_t);
};

#endif