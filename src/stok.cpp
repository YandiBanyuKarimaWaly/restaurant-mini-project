#include "stok.hpp"

std::uint32_t Stok::getJumlah()
{
    return this->_jumlah;
}

std::string Stok::getNama()
{
    return Menu::getNama();
}

std::uint32_t Stok::getHarga()
{
    return Menu::getHarga();
}

std::uint32_t Stok::getDiskon()
{
    return Menu::getDiskon();
}

void Stok::setJumlah(std::uint32_t jumlah)
{
    this->_jumlah = jumlah;
}

bool Stok::operator==(Stok menuCmp)
{
    return (this->getNama().compare(menuCmp.getNama()) == 0) ? true : false;
}

bool Stok::operator==(Pesanan menuCmp)
{
    return (this->getNama().compare(menuCmp.getNama()) == 0) ? true : false;
}