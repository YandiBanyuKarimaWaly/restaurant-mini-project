#include "stok.hpp"

std::uint32_t Stok::getJumlah()
{
    return this->_jumlah;
}

void Stok::setJumlah(std::uint32_t jumlah)
{
    this->_jumlah = jumlah;
}

bool Stok::operator==(Menu menuCmp)
{
    return (this->getNama().compare(menuCmp.getNama()) == 0) ? true : false;
}