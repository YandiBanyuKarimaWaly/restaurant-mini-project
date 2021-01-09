#ifndef INVOICE_HPP
#define INVOICE_HPP

#include <vector>
#include <cstdint>
#include <string>
#include <ctime>
#include "pesanan.hpp"

class Invoice {
    private:
        std::time_t _timestamp;
        std::uint32_t _diskon;
        std::vector<Pesanan> _pesanan;

    public:
        Invoice() : _timestamp(std::time(nullptr)) {}
        std::time_t getTimestamp();
        std::uint32_t getDiskon();
        std::vector<Pesanan> getDetailPesanan();

        void tambahMenu(Menu, std::uint32_t, std::string);
        void tambahMenu(Menu, std::uint32_t, const char*);
        void hapusMenu(Pesanan);
        void editMenu(Pesanan, std::uint32_t, std::string);
        void editMenu(Pesanan, std::uint32_t, const char*);
        void setDiskon(std::uint32_t);
};

#endif