#include <iostream>
#include <iomanip>

using namespace std;

// Khai bao cau truc San Pham
struct SanPham
{
    string MaSP;
    string TenSP;
    string LoaiSP;
    string KichThuoc;
    string MauSac;
    int SoLuong;
    float GiaBan;
};
typedef struct SanPham SANPHAM;

// Khai bao cau truc node San Pham
struct NodeSanPham
{
    SANPHAM Data;
    NodeSanPham *Next;
};
typedef struct NodeSanPham NODESANPHAM;

// Khai bao danh sach lien ket San Pham
struct ListSanPham
{
    NODESANPHAM *Head;
    NODESANPHAM *Tail;
};
typedef struct ListSanPham LISTSANPHAM;

// Khoi tao danh sach lien ket San Pham rong
void InitListSanPham(LISTSANPHAM &ListSP)
{
    ListSP.Head = NULL;
    ListSP.Tail = NULL;
}

// Khoi tao node San Pham
NODESANPHAM *CreateNodeSanPham(SANPHAM SP)
{
    NODESANPHAM *p;
    p = new NODESANPHAM;
    if (p == NULL)
    {
        cout << "Khong du bo nho";
        return NULL;
    }
    p->Data = SP;
    p->Next = NULL;
    return p;
}

// Them node vao cuoi danh sach lien ket San Pham
void InsertLastListSanPham(LISTSANPHAM &ListSP, NODESANPHAM *p)
{
    if (ListSP.Head == NULL)
    {
        ListSP.Head = p;
        ListSP.Tail = p;
    }
    else
    {
        ListSP.Tail->Next = p;
        ListSP.Tail = p;
    }
}

LISTSANPHAM ListSP;

// Nhap danh sach lien ket SanPham
void InputListSanPham(LISTSANPHAM &ListSP, int n)
{
    for (int i = 0; i < n; i++)
    {
        SANPHAM SP;

        cout << endl
             << "Nhap thong tin cho san pham thu " << i + 1 << endl;

        cout << setw(15) << left << "Thong tin"
             << setw(35) << left << "Gia tri" << endl
             << setfill('-') << setw(50) << "-" << endl
             << setfill(' ');

        cout << setw(15) << left << "Ma san pham:";
        cin >> SP.MaSP;

        cout << setw(15) << left << "Ten san pham:";
        cin >> SP.TenSP;

        cout << setw(15) << left << "Loai san pham:";
        cin >> SP.LoaiSP;

        cout << setw(15) << left << "Kich thuoc:";
        cin >> SP.KichThuoc;

        cout << setw(15) << left << "Mau sac:";
        cin >> SP.MauSac;

    SoLuongRepeat:
        string input;
        cout << setw(15) << left << "So luong:";
        cin >> input;
        try
        {
            SP.SoLuong = stoi(input);
        }
        catch (const invalid_argument &e)
        {
            cout << endl
                 << "Chi cho phep nhap so!!!" << endl;
            goto SoLuongRepeat;
        }

    GiaBanRepeat:
        cout << setw(15) << left << "Gia ban:";
        cin >> input;
        try
        {
            SP.GiaBan = stof(input);
        }
        catch (const invalid_argument &e)
        {
            cout << endl
                 << "Chi cho phep nhap so!!!" << endl;
            goto GiaBanRepeat;
        }
        NODESANPHAM *p = CreateNodeSanPham(SP);
        InsertLastListSanPham(ListSP, p);
    }
}

// Xuat danh sach lien ket San Pham
void PrintListSanPham(LISTSANPHAM ListSP)
{
    NODESANPHAM *p = new NODESANPHAM;
    cout << setw(4) << left << "STT"
         << setw(16) << left << "Ma SP"
         << setw(30) << left << "Ten SP"
         << setw(10) << left << "Loai SP"
         << setw(15) << left << "Kich thuoc"
         << setw(15) << left << "Mau sac"
         << setw(10) << left << "So luong"
         << setw(10) << left << "Gia ban" << endl
         << setfill('-') << setw(120) << "-" << endl
         << setfill(' ');

    int count = 1;
    for (p = ListSP.Head; p != NULL; p = p->Next)
    {
        SANPHAM SP;
        SP = p->Data;
        cout << setw(4) << left << count++
             << setw(16) << left << SP.MaSP
             << setw(30) << left << SP.TenSP
             << setw(10) << left << SP.LoaiSP
             << setw(15) << left << SP.KichThuoc
             << setw(15) << left << SP.MauSac
             << setw(10) << left << SP.SoLuong
             << setw(10) << left << SP.GiaBan << endl
             << setfill('-') << setw(120) << "-" << endl
             << endl
             << setfill(' ');
    }
    cout << "Nhan phim bat ky de thoat: ";
    string inputExit;
    cin >> inputExit;
}

// Nhap danh sach san pham
void NhapDanhSachSanPham()
{
Quantity:
    int quantity;
    string inputQuantity;
    cout << "So luong san pham can nhap: ";
    cin >> inputQuantity;
    try
    {
        quantity = stoi(inputQuantity);
        InputListSanPham(ListSP, quantity);
        cout << endl
             << "Nhap danh sach thanh cong..." << endl
             << endl;
        cout << "Nhan phim bat ky de thoat: ";
        string inputExit;
        cin >> inputExit;
    }
    catch (const invalid_argument &e)
    {
        system("cls");
        cout << "Chi cho phep nhap so!!!" << endl
             << endl;
        goto Quantity;
    }
}

// Them moi san pham
void ThemMoiSanPham()
{
    InputListSanPham(ListSP, 1);
    cout << endl
         << "Them moi thanh cong..." << endl
         << endl;
    cout << "Nhan phim bat ky de thoat: ";
    string inputExit;
    cin >> inputExit;
}

// Chinh sua thong tin san pham
void ChinhSuaSanPham()
{
    string inputMaSP;
    cout << "Nhap ma san pham can chinh sua: ";
    cin >> inputMaSP;

    NODESANPHAM *p = ListSP.Head;
    while (p != NULL)
    {
        if (p->Data.MaSP == inputMaSP)
            break;
        p = p->Next;
    }
    if (p == NULL)
    {
        system("cls");
        cout << "MaSP khong ton tai!!!" << endl
             << endl;
    }
    else
    {
        SANPHAM SP;

        cout << endl
             << "Nhap thong tin cho san pham " << inputMaSP << endl;

        cout << setw(15) << left << "Thong tin"
             << setw(35) << left << "Gia tri" << endl
             << setfill('-') << setw(50) << "-" << endl
             << setfill(' ');

        cout << setw(15) << left << "Ma san pham:" << inputMaSP << endl;
        SP.MaSP = inputMaSP;

        cout << setw(15) << left << "Ten san pham:";
        cin >> SP.TenSP;

        cout << setw(15) << left << "Loai san pham:";
        cin >> SP.LoaiSP;

        cout << setw(15) << left << "Kich thuoc:";
        cin >> SP.KichThuoc;

        cout << setw(15) << left << "Mau sac:";
        cin >> SP.MauSac;

    SoLuongRepeat:
        string input;
        cout << setw(15) << left << "So luong:";
        cin >> input;
        try
        {
            SP.SoLuong = stoi(input);
        }
        catch (const invalid_argument &e)
        {
            cout << endl
                 << "Chi cho phep nhap so!!!" << endl;
            goto SoLuongRepeat;
        }

    GiaBanRepeat:
        cout << setw(15) << left << "Gia ban:";
        cin >> input;
        try
        {
            SP.GiaBan = stof(input);
        }
        catch (const invalid_argument &e)
        {
            cout << endl
                 << "Chi cho phep nhap so!!!" << endl;
            goto GiaBanRepeat;
        }

        while (p != NULL)
        {
            if (p->Data.MaSP == inputMaSP)
            {
                p->Data = SP;
                break;
            }
            p = p->Next;
        }

        system("cls");
        cout << "Chinh sua thanh cong..." << endl
             << endl;
    }
    cout << "Nhan phim bat ky de thoat: ";
    string inputExit;
    cin >> inputExit;
}

// Xoa san pham
int XoaSanPham(LISTSANPHAM &ListSP)
{
    string inputMaSP;
    cout << "Nhap ma san pham can xoa: ";
    cin >> inputMaSP;

    NODESANPHAM *p = ListSP.Head, *q = NULL;
    while (p != NULL)
    {
        if (p->Data.MaSP == inputMaSP)
            break;
        q = p;
        p = p->Next;
    }
    if (p == NULL)
        return 0;
    if (q != NULL)
    {
        if (p == ListSP.Tail)
            ListSP.Tail = q;
        q->Next = p->Next;
        free(p);
    }
    else // p là phần tử đầu xâu
    {
        ListSP.Head = p->Next;
        if (ListSP.Head == NULL)
            ListSP.Tail = NULL;
    }
    return 1;
}

// Tim kiem san pham
void TimKiemSanPham()
{
    int optionSearch;
    string inputSearch;
    cout << "1. Tim kiem theo ma san pham" << endl
         << "2. Tim kiem theo ten san pham" << endl
         << "3. Tim kiem san pham co so luong lon nhat" << endl
         << "4. Tim kiem san pham co so luong nho nhat" << endl
         << "5. Tim kiem san pham co gia ban lon nhat" << endl
         << "6. Tim kiem san pham co gia ban nho nhat" << endl
         << setfill('-') << setw(50) << "-" << endl
         << setfill(' ')
         << "Lua chon cua ban: ";
    cin >> inputSearch;
    try
    {
        optionSearch = stoi(inputSearch);
        if (optionSearch == 1)
        {
            string inputMaSP;
            cout << "Nhap ma san pham can tim: ";
            cin >> inputMaSP;
            NODESANPHAM *p = ListSP.Head;
            while (p != NULL)
            {
                if (p->Data.MaSP == inputMaSP)
                {
                    SANPHAM SP;
                    SP = p->Data;
                    cout << setw(20) << left << "Ma SP"
                         << setw(30) << left << "Ten SP"
                         << setw(10) << left << "Loai SP"
                         << setw(15) << left << "Kich thuoc"
                         << setw(15) << left << "Mau sac"
                         << setw(10) << left << "So luong"
                         << setw(10) << left << "Gia ban" << endl
                         << setfill('-') << setw(120) << "-" << endl
                         << setfill(' ');
                    cout << setw(20) << left << SP.MaSP
                         << setw(30) << left << SP.TenSP
                         << setw(10) << left << SP.LoaiSP
                         << setw(15) << left << SP.KichThuoc
                         << setw(15) << left << SP.MauSac
                         << setw(10) << left << SP.SoLuong
                         << setw(10) << left << SP.GiaBan << endl
                         << setfill('-') << setw(120) << "-" << endl
                         << endl
                         << setfill(' ');
                    break;
                }
                p = p->Next;
            }
            if (p == NULL)
            {
                system("cls");
                cout << "MaSP khong ton tai!!!" << endl
                     << endl;
            }
        }
        else if (optionSearch == 2)
        {
            string inputTenSP;
            cout << "Nhap ten san pham can tim: ";
            cin >> inputTenSP;
            NODESANPHAM *p = ListSP.Head;
            while (p != NULL)
            {
                if (p->Data.MaSP == inputTenSP)
                {
                    SANPHAM SP;
                    SP = p->Data;
                    cout << setw(20) << left << "Ma SP"
                         << setw(30) << left << "Ten SP"
                         << setw(10) << left << "Loai SP"
                         << setw(15) << left << "Kich thuoc"
                         << setw(15) << left << "Mau sac"
                         << setw(10) << left << "So luong"
                         << setw(10) << left << "Gia ban" << endl
                         << setfill('-') << setw(120) << "-" << endl
                         << setfill(' ');
                    cout << setw(20) << left << SP.MaSP
                         << setw(30) << left << SP.TenSP
                         << setw(10) << left << SP.LoaiSP
                         << setw(15) << left << SP.KichThuoc
                         << setw(15) << left << SP.MauSac
                         << setw(10) << left << SP.SoLuong
                         << setw(10) << left << SP.GiaBan << endl
                         << setfill('-') << setw(120) << "-" << endl
                         << endl
                         << setfill(' ');
                    break;
                }
                p = p->Next;
            }
            if (p == NULL)
            {
                system("cls");
                cout << "TenSP khong ton tai!!!" << endl
                     << endl;
            }
        }
        else if (optionSearch == 3)
        {
            NODESANPHAM *p = ListSP.Head;
            SANPHAM SP;
            int count = 0;
            while (p != NULL)
            {
                if (count == 0)
                    SP = p->Data;
                else
                {
                    if (p->Data.SoLuong > SP.SoLuong)
                        SP = p->Data;
                }
                count++;
                p = p->Next;
            }
            if (count == 0)
            {
                system("cls");
                cout << "Danh sach rong!!!" << endl
                     << endl;
            }
            else
            {
                cout << setw(20) << left << "Ma SP"
                     << setw(30) << left << "Ten SP"
                     << setw(10) << left << "Loai SP"
                     << setw(15) << left << "Kich thuoc"
                     << setw(15) << left << "Mau sac"
                     << setw(10) << left << "So luong"
                     << setw(10) << left << "Gia ban" << endl
                     << setfill('-') << setw(120) << "-" << endl
                     << setfill(' ');
                cout << setw(20) << left << SP.MaSP
                     << setw(30) << left << SP.TenSP
                     << setw(10) << left << SP.LoaiSP
                     << setw(15) << left << SP.KichThuoc
                     << setw(15) << left << SP.MauSac
                     << setw(10) << left << SP.SoLuong
                     << setw(10) << left << SP.GiaBan << endl
                     << setfill('-') << setw(120) << "-" << endl
                     << endl
                     << setfill(' ');
            }
        }
        else if (optionSearch == 4)
        {
            NODESANPHAM *p = ListSP.Head;
            SANPHAM SP;
            int count = 0;
            while (p != NULL)
            {
                if (count == 0)
                    SP = p->Data;
                else
                {
                    if (p->Data.SoLuong < SP.SoLuong)
                        SP = p->Data;
                }
                count++;
                p = p->Next;
            }
            if (count == 0)
            {
                system("cls");
                cout << "Danh sach rong!!!" << endl
                     << endl;
            }
            else
            {
                cout << setw(20) << left << "Ma SP"
                     << setw(30) << left << "Ten SP"
                     << setw(10) << left << "Loai SP"
                     << setw(15) << left << "Kich thuoc"
                     << setw(15) << left << "Mau sac"
                     << setw(10) << left << "So luong"
                     << setw(10) << left << "Gia ban" << endl
                     << setfill('-') << setw(120) << "-" << endl
                     << setfill(' ');
                cout << setw(20) << left << SP.MaSP
                     << setw(30) << left << SP.TenSP
                     << setw(10) << left << SP.LoaiSP
                     << setw(15) << left << SP.KichThuoc
                     << setw(15) << left << SP.MauSac
                     << setw(10) << left << SP.SoLuong
                     << setw(10) << left << SP.GiaBan << endl
                     << setfill('-') << setw(120) << "-" << endl
                     << endl
                     << setfill(' ');
            }
        }
        else if (optionSearch == 5)
        {
            NODESANPHAM *p = ListSP.Head;
            SANPHAM SP;
            int count = 0;
            while (p != NULL)
            {
                if (count == 0)
                    SP = p->Data;
                else
                {
                    if (p->Data.GiaBan > SP.GiaBan)
                        SP = p->Data;
                }
                count++;
                p = p->Next;
            }
            if (count == 0)
            {
                system("cls");
                cout << "Danh sach rong!!!" << endl
                     << endl;
            }
            else
            {
                cout << setw(20) << left << "Ma SP"
                     << setw(30) << left << "Ten SP"
                     << setw(10) << left << "Loai SP"
                     << setw(15) << left << "Kich thuoc"
                     << setw(15) << left << "Mau sac"
                     << setw(10) << left << "So luong"
                     << setw(10) << left << "Gia ban" << endl
                     << setfill('-') << setw(120) << "-" << endl
                     << setfill(' ');
                cout << setw(20) << left << SP.MaSP
                     << setw(30) << left << SP.TenSP
                     << setw(10) << left << SP.LoaiSP
                     << setw(15) << left << SP.KichThuoc
                     << setw(15) << left << SP.MauSac
                     << setw(10) << left << SP.SoLuong
                     << setw(10) << left << SP.GiaBan << endl
                     << setfill('-') << setw(120) << "-" << endl
                     << endl
                     << setfill(' ');
            }
        }
        else if (optionSearch == 6)
        {
            NODESANPHAM *p = ListSP.Head;
            SANPHAM SP;
            int count = 0;
            while (p != NULL)
            {
                if (count == 0)
                    SP = p->Data;
                else
                {
                    if (p->Data.GiaBan < SP.GiaBan)
                        SP = p->Data;
                }
                count++;
                p = p->Next;
            }
            if (count == 0)
            {
                system("cls");
                cout << "Danh sach rong!!!" << endl
                     << endl;
            }
            else
            {
                cout << setw(20) << left << "Ma SP"
                     << setw(30) << left << "Ten SP"
                     << setw(10) << left << "Loai SP"
                     << setw(15) << left << "Kich thuoc"
                     << setw(15) << left << "Mau sac"
                     << setw(10) << left << "So luong"
                     << setw(10) << left << "Gia ban" << endl
                     << setfill('-') << setw(120) << "-" << endl
                     << setfill(' ');
                cout << setw(20) << left << SP.MaSP
                     << setw(30) << left << SP.TenSP
                     << setw(10) << left << SP.LoaiSP
                     << setw(15) << left << SP.KichThuoc
                     << setw(15) << left << SP.MauSac
                     << setw(10) << left << SP.SoLuong
                     << setw(10) << left << SP.GiaBan << endl
                     << setfill('-') << setw(120) << "-" << endl
                     << endl
                     << setfill(' ');
            }
        }
        else
        {
            system("cls");
            cout << "Khong co chuc nang nay!!!" << endl
                 << endl;
        }
    }
    catch (const invalid_argument &e)
    {
        system("cls");
        cout << "Chi cho phep nhap so!!!" << endl
             << endl;
    }
    cout << "Nhan phim bat ky de thoat: ";
    string inputExit;
    cin >> inputExit;
}

// Sap xep san pham
void SapXepSanPham()
{
    int optionSort;
    string inputSort;
    cout << "1. Sap xep theo ten san pham" << endl
         << "2. Sap xep theo so luong san pham" << endl
         << "3. Sap xep theo gia ban tu thap den cao" << endl
         << "4. Sap xep theo gia ban tu cao den thap" << endl
         << setfill('-') << setw(50) << "-" << endl
         << setfill(' ')
         << "Lua chon cua ban: ";
    cin >> inputSort;
    try
    {
        optionSort = stoi(inputSort);
        if (optionSort == 1)
        {
            NODESANPHAM *p, *q;
            SANPHAM SP;
            p = ListSP.Head;
            while (p != NULL)
            {
                q = p->Next;
                while (q != NULL)
                {
                    if (p->Data.TenSP > q->Data.TenSP)
                    {
                        SANPHAM hoandoi = p->Data;
                        p->Data = q->Data;
                        q->Data = hoandoi;
                    }
                    q = q->Next;
                }
                p = p->Next;
            }
            system("cls");
            cout << "Sap xep theo ten san pham thanh cong!!!" << endl
                 << endl;
        }
        else if (optionSort == 2)
        {
            NODESANPHAM *p, *q;
            SANPHAM SP;
            p = ListSP.Head;
            while (p != NULL)
            {
                q = p->Next;
                while (q != NULL)
                {
                    if (p->Data.SoLuong > q->Data.SoLuong)
                    {
                        SANPHAM hoandoi = p->Data;
                        p->Data = q->Data;
                        q->Data = hoandoi;
                    }
                    q = q->Next;
                }
                p = p->Next;
            }
            system("cls");
            cout << "Sap xep theo so luong thanh cong!!!" << endl
                 << endl;
        }
        else if (optionSort == 3)
        {
            NODESANPHAM *p, *q;
            SANPHAM SP;
            p = ListSP.Head;
            while (p != NULL)
            {
                q = p->Next;
                while (q != NULL)
                {
                    if (p->Data.GiaBan < q->Data.GiaBan)
                    {
                        SANPHAM hoandoi = p->Data;
                        p->Data = q->Data;
                        q->Data = hoandoi;
                    }
                    q = q->Next;
                }
                p = p->Next;
            }
            system("cls");
            cout << "Sap xep gia ban tu thap den cao thanh cong!!!" << endl
                 << endl;
        }
        else if (optionSort == 4)
        {
            NODESANPHAM *p, *q;
            SANPHAM SP;
            p = ListSP.Head;
            while (p != NULL)
            {
                q = p->Next;
                while (q != NULL)
                {
                    if (p->Data.GiaBan > q->Data.GiaBan)
                    {
                        SANPHAM hoandoi = p->Data;
                        p->Data = q->Data;
                        q->Data = hoandoi;
                    }
                    q = q->Next;
                }
                p = p->Next;
            }
            system("cls");
            cout << "Sap xep gia ban tu cao den thap thanh cong!!!" << endl
                 << endl;
        }
        else
        {
            system("cls");
            cout << "Khong co chuc nang nay!!!" << endl
                 << endl;
        }
    }
    catch (const invalid_argument &e)
    {
        system("cls");
        cout << "Chi cho phep nhap so!!!" << endl
             << endl;
    }
    cout << "Nhan phim bat ky de thoat: ";
    string inputExit;
    cin >> inputExit;
}

// Menu san pham
bool SanPhamMenu()
{
    bool exitMainMenu = false;
    bool exitSanPhamMenu = false;
    int optionSanPhamMenu;
    int status;
    string inputSanPhamMenu;
    string inputContinue;
    string inputExit;
    do
    {
        system("cls");
        cout << "Quan ly san pham" << endl
             << setfill('-') << setw(50) << "-" << endl
             << "0. Nhap danh sach" << endl
             << "1. In danh sach" << endl
             << "2. Them moi" << endl
             << "3. Chinh sua" << endl
             << "4. Xoa" << endl
             << "5. Tim kiem" << endl
             << "6. Sap xep" << endl
             << "7. Tinh toan" << endl
             << "8. Thong ke" << endl
             << "9. Thoat" << endl
             << setfill('-') << setw(50) << "-" << endl
             << setfill(' ')
             << "Lua chon cua ban: ";
        cin >> inputSanPhamMenu;
        try
        {
            optionSanPhamMenu = stoi(inputSanPhamMenu);
            switch (optionSanPhamMenu)
            {
            case 0:
                // Nhap danh sach
                system("cls");
                NhapDanhSachSanPham();
                break;
            case 1:
                // In danh sach
                system("cls");
                PrintListSanPham(ListSP);
                break;
            case 2:
                // Them moi
                system("cls");
                ThemMoiSanPham();
                break;
            case 3:
                // Chinh sua
                system("cls");
                ChinhSuaSanPham();
                break;
            case 4:
                // Xoa
                system("cls");
                status = XoaSanPham(ListSP);
                if (status == 0)
                {
                    system("cls");
                    cout << "MaSP khong ton tai!!!" << endl
                         << endl;
                    cout << "Nhan phim bat ky de thoat: ";
                    cin >> inputExit;
                }
                else
                {
                    system("cls");
                    cout << "Xoa thanh cong..." << endl
                         << endl;
                    cout << "Nhan phim bat ky de thoat: ";
                    cin >> inputExit;
                }
                break;
            case 5:
                // Tim kiem
                system("cls");
                TimKiemSanPham();
                break;
            case 6:
                // Sap xep
                system("cls");
                SapXepSanPham();
                break;
            case 7:
                // Tinh toan
                break;
            case 8:
                // Thong ke
                break;
            case 9:
                // Thoat
                exitSanPhamMenu = true;
                break;
            default:
                system("cls");
                cout << "Khong co chuc nang nay!!!" << endl
                     << endl;
                cout << "Nhan phim bat ky de tiep tuc: ";
                cin >> inputContinue;
                break;
            }
        }
        catch (const invalid_argument &e)
        {
            system("cls");
            cout << "Chi cho phep nhap so!!!" << endl
                 << endl;
            cout << "Nhan phim bat ky de tiep tuc: ";
            cin >> inputContinue;
        }
    } while (!exitSanPhamMenu);

    return exitMainMenu;
}

// Menu chinh cua chuong trinh
void MainMenu()
{
    bool exit = false;
    int option;
    string input;
    do
    {
        cout << "Chuong trinh quan ly cua hang thoi trang" << endl
             << setfill('-') << setw(50) << "-" << endl
             << "1. San pham" << endl
             << "2. Hoa don" << endl
             << "3. Khach hang" << endl
             << "4. Nhan vien" << endl
             << "5. Thoat" << endl
             << setfill('-') << setw(50) << "-" << endl
             << setfill(' ')
             << "Lua chon cua ban: ";
        cin >> input;
        try
        {
            option = stoi(input);
            switch (option)
            {
            case 1:
                // San pham
                system("cls");
                exit = SanPhamMenu();
                break;
            case 2:
                // Hoa don
                break;
            case 3:
                // Khach hang
                break;
            case 4:
                // Nhan vien
                break;
            case 5:
                // Thoat
                exit = true;
                break;
            default:
                system("cls");
                cout << "Khong co chuc nang nay!!!" << endl
                     << endl;
                break;
            }
        }
        catch (const invalid_argument &e)
        {
            system("cls");
            cout << "Chi cho phep nhap so!!!" << endl
                 << endl;
        }
    } while (!exit);
}

int main()
{
    InitListSanPham(ListSP);
    MainMenu();
    cout << endl
         << "Ket thuc chuong trinh...";
    return 0;
}