#include "invoice.hpp"

std::time_t Invoice::getTimestamp()
{
    return this->_timestamp;
}

std::uint32_t Invoice::getDiskon()
{
    return this->_diskon;
}

std::vector<Pesanan> Invoice::getDetailPesanan()
{
    return this->_pesanan;
}

void Invoice::tambahMenu(Menu menu, std::uint32_t jumlah, std::string catatan)
{
    Pesanan pesanan(menu);
    pesanan.setJumlah(jumlah);
    pesanan.setCatatan(catatan);

    this->_pesanan.push_back(pesanan);
}

void Invoice::tambahMenu(Menu menu, std::uint32_t jumlah, const char* catatan)
{
    std::string catatanStd(catatan);
    this->tambahMenu(menu, jumlah, catatanStd);
}

void Invoice::hapusMenu(Menu menu)
{
    for (auto iter = this->_pesanan.begin() ; iter != this->_pesanan.end();)
    {
        if (*iter == menu)
        {
            this->_pesanan.erase(iter);
            break;
        }
        iter++;
    }
}

void Invoice::editMenu(Menu menu, std::uint32_t jumlah, std::string catatan)
{
    for (auto item : this->_pesanan)
    {
        if (item == menu)
        {
            item.setJumlah(jumlah);
            item.setCatatan(catatan);
            break;
        }
    }
}

void Invoice::editMenu(Menu menu, std::uint32_t jumlah, const char* catatan)
{
    std::string catatanStd(catatan);
    this->editMenu(menu, jumlah, catatanStd);
}

void Invoice::setDiskon(std::uint32_t diskon)
{
    this->_diskon = diskon;
}