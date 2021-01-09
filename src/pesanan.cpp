#include "pesanan.hpp"

std::string Pesanan::getCatatan()
{
    return this->_catatan;
}

std::string Pesanan::getNama()
{
    return Menu::getNama();
}

std::uint32_t Pesanan::getJumlah()
{
    return this->_jumlah;
}

std::uint32_t Pesanan::getHarga()
{
    return Menu::getHarga();
}

std::uint32_t Pesanan::getDiskon()
{
    return Menu::getDiskon();
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

bool Pesanan::operator==(Pesanan menuCmp)
{
    return (this->getNama().compare(menuCmp.getNama()) == 0) ? true : false;
}