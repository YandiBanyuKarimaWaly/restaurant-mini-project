#include "menu.hpp"

std::string Menu::getNama()
{
    return this->_nama;
}

std::uint32_t Menu::getHarga()
{
    return this->_harga;
}

std::uint32_t Menu::getDiskon()
{
    return this->_diskon;
}

void Menu::setNama(std::string nama)
{
    this->_nama = nama;
}

void Menu::setNama(const char* nama)
{
    std::string namaStd(nama);
    this->setNama(namaStd);
}

void Menu::setHarga(std::uint32_t harga)
{
    this->_harga = harga;
}

void Menu::setDiskon(std::uint32_t diskon)
{
    this->_diskon = diskon;
}