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

    public:
        std::vector<Stok> getMenu();
        void addMenu(Menu, std::uint32_t);
        void deleteMenu(Menu);
        void editMenu(Menu, Menu);
        void editMenu(Menu, Menu, std::uint32_t);

        std::vector<Invoice> getInvoice();
        void pesan(Invoice);
};

#endif