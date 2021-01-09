#include "restaurant.hpp"

std::vector<Stok> Restaurant::getMenu()
{
    return this->_menuStok;
}

void Restaurant::addMenu(Menu menu, std::uint32_t stok)
{
    Stok stokObj(menu);
    stokObj.setJumlah(stok);
    this->_menuStok.push_back(stokObj);
}

void Restaurant::deleteMenu(Stok menu)
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

void Restaurant::editMenu(Stok menu, Menu menuBaru)
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

void Restaurant::editMenu(Stok menu, Menu menuBaru, std::uint32_t stok)
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

Stok Restaurant::findMenu(Pesanan pesanan)
{
    for (auto item : this->_menuStok)
    {
        if (item == pesanan) { return item; }
    }

    Menu empty;
    Stok emptyItem(empty);
    return emptyItem;
}

void Restaurant::pesan(Invoice pesanan)
{
    std::vector<Pesanan> pesananList = pesanan.getDetailPesanan();
    for (auto item : pesananList)
    {
        Menu menuDipesan;
        menuDipesan.setDiskon(item.getDiskon());
        menuDipesan.setHarga(item.getHarga());
        menuDipesan.setNama(item.getNama());

        Stok menu = this->findMenu(item);
        if (!menu.getNama().empty())
        {
            this->editMenu(menu, menuDipesan, menu.getJumlah()-item.getJumlah());
        }
    }
    this->_invoice.push_back(pesanan);
}