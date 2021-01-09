#include "cli.hpp"

CLI::Action CLI::MenuCLI::reviewPesanan()
{
    std::cout << "Review Pesanan" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    CLI::Utilities::print("Nomor", 7);
    CLI::Utilities::print("Nama", 30);
    CLI::Utilities::print("Jumlah", 10);
    CLI::Utilities::print("Harga", 20);
    CLI::Utilities::print("Diskon", 20);
    std::cout << "Catatan" << std::endl;

    std::vector<Pesanan> menu = invoiceTmp.getDetailPesanan();
    std::uint32_t counter = 1;
    std::uint32_t tally = 0, diskonTally = 0, total = 0;
    for (auto item : menu)
    {
        CLI::Utilities::print(counter, 7);
        CLI::Utilities::print(item.getNama(), 30);
        CLI::Utilities::print(item.getJumlah(), 10);
        CLI::Utilities::printMoney(item.getHarga(), 20);
        CLI::Utilities::printMoney(item.getDiskon(), 20);
        std::cout << item.getCatatan() << std::endl;
        counter++;
        tally += item.getHarga()*item.getJumlah();
        diskonTally += item.getDiskon()*item.getJumlah();
    }
    std::cout << "----------------------------------------";
    std::cout << std::endl << "Sub-total:    ";
    CLI::Utilities::printMoney(tally, 20);
    std::cout << std::endl << "Diskon total: ";
    CLI::Utilities::printMoney(diskonTally, 20);
    std::cout << std::endl << "Harga akhir:  ";
    CLI::Utilities::printMoney(tally-diskonTally, 20);
    std::cout << std::endl << std::endl;
    std::cout << "a = Tambah Menu, d = Delete Menu, e = Edit Menu, p = Pesan" << std::endl;
    std::cout << "Pilihan: ";

    std::string chooseStr;
    std::getline(std::cin, chooseStr);
    std::cout << std::endl;

    char choose = chooseStr.c_str()[0];
    if (choose == 'a' || choose == 'A')
    {
        return Action::AddPesanan;
    }

    if (choose == 'd' || choose == 'D')
    {
        return Action::DeletePesanan;
    }

    if (choose == 'e' || choose == 'E')
    {
        return Action::EditPesanan;
    }

    if (choose == 'p' || choose == 'P')
    {
        return Action::Pesan;
    }

    std::cout << "Pilihan tidak valid, silahkan ulangi lagi" << std::endl << std::endl;
    return CLI::Action::ReviewPesanan;
}

CLI::Action CLI::MenuCLI::addPesanan()
{
    std::cout << "List Menu" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    CLI::Utilities::print("Nomor", 7);
    CLI::Utilities::print("Nama", 30);
    CLI::Utilities::print("Stok", 10);
    CLI::Utilities::print("Harga", 20);
    CLI::Utilities::print("Diskon", 20);
    std::cout << std::endl;

    std::vector<Stok> menu = resto.getMenu();
    std::uint32_t counter = 1;
    for (auto item : menu)
    {
        CLI::Utilities::print(counter, 7);
        CLI::Utilities::print(item.getNama(), 30);
        CLI::Utilities::print(item.getJumlah(), 10);
        CLI::Utilities::printMoney(item.getHarga(), 20);
        CLI::Utilities::printMoney(item.getDiskon(), 20);
        std::cout << std::endl;
        counter++;
    }

    std::cout << "Pilih Menu: ";

    std::string chooseStr;
    std::getline(std::cin, chooseStr);
    std::uint32_t choose = static_cast<uint32_t>(std::stoull(chooseStr));

    if (choose > counter || choose == 0)
    {
        std::cout << "Pilihan tidak valid, silahkan ulangi lagi" << std::endl
                  << std::endl;
        return Action::AddPesanan;
    }

    std::string jumlah, catatan;
    std::cout << "Jumlah pemesanan: ";
    std::getline(std::cin, jumlah);

    std::uint32_t jumlahInt = static_cast<std::uint32_t>(std::stoull(jumlah));
    if (jumlahInt > menu[choose-1].getJumlah())
    {
        std::cout << "Stok tidak mencukupi. Silahkan coba lagi" << std::endl
                  << std::endl;
        return Action::AddPesanan;
    }

    std::cout << "Catatan: ";
    std::getline(std::cin, catatan);

    Menu pesanMenu;
    pesanMenu.setDiskon(menu[choose-1].getDiskon());
    pesanMenu.setHarga(menu[choose-1].getHarga());
    pesanMenu.setNama(menu[choose-1].getNama());

    invoiceTmp.tambahMenu(pesanMenu, jumlahInt, catatan);

    return Action::ReviewPesanan;
}

CLI::Action CLI::MenuCLI::createPesanan()
{
    Invoice newInvoice;
    invoiceTmp = newInvoice;
    return Action::ReviewPesanan;
}

CLI::Action CLI::MenuCLI::editPesanan()
{
    std::cout << "Edit Pesanan" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    CLI::Utilities::print("Nomor", 7);
    CLI::Utilities::print("Nama", 30);
    CLI::Utilities::print("Jumlah", 10);
    CLI::Utilities::print("Harga", 20);
    CLI::Utilities::print("Diskon", 20);
    std::cout << "Catatan" << std::endl;

    std::vector<Pesanan> menu = invoiceTmp.getDetailPesanan();
    std::uint32_t counter = 1;
    std::uint32_t tally = 0, diskonTally = 0, total = 0;
    for (auto item : menu)
    {
        CLI::Utilities::print(counter, 7);
        CLI::Utilities::print(item.getNama(), 30);
        CLI::Utilities::print(item.getJumlah(), 10);
        CLI::Utilities::printMoney(item.getHarga(), 20);
        CLI::Utilities::printMoney(item.getDiskon(), 20);
        std::cout << item.getCatatan() << std::endl;
        counter++;
        tally += item.getHarga()*item.getJumlah();
        diskonTally += item.getDiskon()*item.getJumlah();
    }
    std::cout << "----------------------------------------";
    std::cout << std::endl << "Sub-total:    ";
    CLI::Utilities::printMoney(tally, 20);
    std::cout << std::endl << "Diskon total: ";
    CLI::Utilities::printMoney(diskonTally, 20);
    std::cout << std::endl << "Harga akhir:  ";
    CLI::Utilities::printMoney(tally-diskonTally, 20);
    std::cout << std::endl << std::endl;

    std::cout << "Pilih Menu: ";

    std::string chooseStr;
    std::getline(std::cin, chooseStr);
    std::uint32_t choose = static_cast<uint32_t>(std::stoull(chooseStr));

    if (choose > counter || choose == 0)
    {
        std::cout << "Pilihan tidak valid, silahkan ulangi lagi" << std::endl
                  << std::endl;
        return Action::EditPesanan;
    }

    std::string jumlahBaru, catatanBaru;
    std::cout << "Jumlah (" << menu[choose-1].getJumlah() << "): ";
    std::getline(std::cin, jumlahBaru);

    std::uint32_t jumlahInt = static_cast<std::uint32_t>(std::stoull(jumlahBaru));
    if (jumlahInt > menu[choose-1].getJumlah())
    {
        std::cout << "Stok tidak mencukupi. Silahkan coba lagi" << std::endl
                  << std::endl;
        return Action::EditPesanan;
    }

    std::cout << "Catatan: ";
    std::getline(std::cin, catatanBaru);

    invoiceTmp.editMenu(menu[choose-1], static_cast<uint32_t>(std::stoull(jumlahBaru)), catatanBaru);

    return Action::ReviewPesanan;
}

CLI::Action CLI::MenuCLI::deletePesanan()
{
    std::cout << "Hapus Pesanan" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    CLI::Utilities::print("Nomor", 7);
    CLI::Utilities::print("Nama", 30);
    CLI::Utilities::print("Jumlah", 10);
    CLI::Utilities::print("Harga", 20);
    CLI::Utilities::print("Diskon", 20);
    std::cout << "Catatan" << std::endl;

    std::vector<Pesanan> menu = invoiceTmp.getDetailPesanan();
    std::uint32_t counter = 1;
    std::uint32_t tally = 0, diskonTally = 0, total = 0;
    for (auto item : menu)
    {
        CLI::Utilities::print(counter, 7);
        CLI::Utilities::print(item.getNama(), 30);
        CLI::Utilities::print(item.getJumlah(), 10);
        CLI::Utilities::printMoney(item.getHarga(), 20);
        CLI::Utilities::printMoney(item.getDiskon(), 20);
        std::cout << item.getCatatan() << std::endl;
        counter++;
        tally += item.getHarga()*item.getJumlah();
        diskonTally += item.getDiskon()*item.getJumlah();
    }
    std::cout << "----------------------------------------";
    std::cout << std::endl << "Sub-total:    ";
    CLI::Utilities::printMoney(tally, 20);
    std::cout << std::endl << "Diskon total: ";
    CLI::Utilities::printMoney(diskonTally, 20);
    std::cout << std::endl << "Harga akhir:  ";
    CLI::Utilities::printMoney(tally-diskonTally, 20);
    std::cout << std::endl << std::endl;

    std::cout << "Pilih Menu: ";

    std::string chooseStr;
    std::getline(std::cin, chooseStr);
    std::uint32_t choose = static_cast<uint32_t>(std::stoull(chooseStr));
    std::cout << std::endl;

    if (choose > counter || choose == 0)
    {
        std::cout << "Pilihan tidak valid, silahkan ulangi lagi" << std::endl
                  << std::endl;
        return Action::DeletePesanan;
    }

    invoiceTmp.hapusMenu(menu[choose-1]);

    return Action::ReviewPesanan;
}