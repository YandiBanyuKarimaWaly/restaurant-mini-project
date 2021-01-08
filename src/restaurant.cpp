#include "restaurant.hpp"

std::vector<Stok> Restaurant::getMenu()
{
    return this->_menuStok;
}

void Restaurant::addMenu(Menu menu, std::uint32_t stok)
{
    // Stok stokObj;
    // this->_menuStok.push_back(stokObj);
}

void Restaurant::deleteMenu(Menu menu)
{
    for (auto iter = this->_menuStok.begin() ; iter != this->_menuStok.end();)
    {
        if (*iter == menu)
        {
            this->_menuStok.erase(iter);
            break;
        }
        iter++;
    }
}

void Restaurant::editMenu(Menu menu, Menu menuBaru)
{
    for (auto item : this->_menuStok)
    {
        if (item == menu)
        {
            this->editMenu(menu, menuBaru, item.getJumlah());
            break;
        }
    }
}

void Restaurant::editMenu(Menu menu, Menu menuBaru, std::uint32_t stok)
{
    for (auto iter = this->_menuStok.begin() ; iter != this->_menuStok.end();)
    {
        if (*iter == menu)
        {
            this->_menuStok.erase(iter);
            break;
        }
        iter++;
    }

    Stok stokBaru(menuBaru);
    stokBaru.setJumlah(stok);
    this->_menuStok.push_back(stokBaru);
}

std::vector<Invoice> Restaurant::getInvoice()
{
    return this->_invoice;
}

void Restaurant::pesan(Invoice pesanan)
{
    this->_invoice.push_back(pesanan);
}