#include "pesanan.hpp"

std::string Pesanan::getCatatan()
{
    return this->_catatan;
}

std::uint32_t Pesanan::getJumlah()
{
    return this->_jumlah;
}

void Pesanan::setCatatan(std::string catatan)
{
    this->_catatan = catatan;
}

void Pesanan::setCatatan(const char* catatan)
{
    std::string catatanStd(catatan);
    this->setCatatan(catatanStd);
}

void Pesanan::setJumlah(std::uint32_t jumlah)
{
    this->_jumlah = jumlah;
}

bool Pesanan::operator==(Menu menuCmp)
{
    return (this->getNama().compare(menuCmp.getNama()) == 0) ? true : false;
}