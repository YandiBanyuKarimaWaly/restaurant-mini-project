#ifndef RESTAURANT_HPP
#define RESTAURANT_HPP

#include <vector>
#include <cstdint>
#include "stok.hpp"
#include "invoice.hpp"

class Restaurant {
    private:
        std::vector<Stok> _menuStok;
        std::vector<Invoice> _invoice;

        Stok findMenu(Pesanan);

    public:
        std::vector<Stok> getMenu();
        void addMenu(Menu, std::uint32_t);
        void deleteMenu(Stok);
        void editMenu(Stok, Menu);
        void editMenu(Stok, Menu, std::uint32_t);

        std::vector<Invoice> getInvoice();
        void pesan(Invoice);
};

#endif