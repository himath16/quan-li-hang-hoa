#include <stdio.h>
#include <string.h>

struct HangHoa
{
    char maHang[15];
    char tenHang[50];
    char loaiHang[30];
    float giaNhap;
    float giaBan;
    int soLuong;
};

struct HangHoa ds[100];
int soLuongHang = 0;

void khoiTaoDuLieu();
int kiemTraTrungMa(char ma[]);
void xoaBoDem();
int nhapSoNguyen(char thongBao[], int *giaTri);
int nhapSoThuc(char thongBao[], float *giaTri);
void hienThiMenu();
void themHangHoa();
void hienThiDanhSach();
void timKiemHangHoa();
void capNhatHangHoa();
void xoaHangHoa();
void thongKeTonKho();
void sapXepTheoGiaBan();
void canhBaoTonKho();

int main()
{
    int luaChon = -1;

    khoiTaoDuLieu();

    printf("==============================================\n");
    printf("   CHUONG TRINH QUAN LY HANG HOA\n");
    printf("==============================================\n");

    do
    {
        hienThiMenu();

        if (!nhapSoNguyen("Moi ban chon chuc nang: ", &luaChon))
        {
            printf("  >> Vui long nhap mot so!\n");
            luaChon = -1;
            continue;
        }

        switch (luaChon)
        {
            case 1: themHangHoa(); break;
            case 2: hienThiDanhSach(); break;
            case 3: timKiemHangHoa(); break;
            case 4: capNhatHangHoa(); break;
            case 5: xoaHangHoa(); break;
            case 6: thongKeTonKho(); break;
            case 7: sapXepTheoGiaBan(); break;
            case 8: canhBaoTonKho(); break;
            case 0: printf("\nTam biet!\n"); break;
            default: printf("  >> Lua chon khong hop le!\n");
        }
    }
    while (luaChon != 0);

    return 0;
}

void xoaBoDem()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

int nhapSoNguyen(char thongBao[], int *giaTri)
{
    char kyTu;

    printf("%s", thongBao);

    if (scanf("%d%c", giaTri, &kyTu) != 2)
    {
        xoaBoDem();
        return 0;
    }

    if (kyTu != '\n')
    {
        xoaBoDem();
        return 0;
    }

    return 1;
}

int nhapSoThuc(char thongBao[], float *giaTri)
{
    char kyTu;

    printf("%s", thongBao);

    if (scanf("%f%c", giaTri, &kyTu) != 2)
    {
        xoaBoDem();
        return 0;
    }

    if (kyTu != '\n')
    {
        xoaBoDem();
        return 0;
    }

    return 1;
}

int kiemTraTrungMa(char ma[])
{
    for (int i = 0; i < soLuongHang; i++)
    {
        if (strcmp(ds[i].maHang, ma) == 0)
        {
            return 1;
        }
    }

    return 0;
}

void khoiTaoDuLieu()
{
    struct HangHoa duLieu[] =
    {
        {"HH001", "Sua tuoi", "Thuc pham", 25000, 30000, 20},
        {"HH002", "Banh mi", "Thuc pham", 10000, 15000, 15},
        {"HH003", "Nuoc suoi", "Do uong", 5000, 10000, 30},
        {"HH004", "But bi", "Van phong pham", 3000, 5000, 4},
        {"HH005", "Vo hoc sinh", "Van phong pham", 7000, 12000, 3}
    };

    int n = sizeof(duLieu) / sizeof(duLieu[0]);

    for (int i = 0; i < n && soLuongHang < 100; i++)
    {
        if (!kiemTraTrungMa(duLieu[i].maHang))
        {
            ds[soLuongHang] = duLieu[i];
            soLuongHang++;
        }
    }
}

void hienThiMenu()
{
    printf("\n========== MENU QUAN LY HANG HOA ==========\n");
    printf("1. Them hang hoa moi\n");
    printf("2. Hien thi danh sach hang hoa\n");
    printf("3. Tim kiem hang hoa\n");
    printf("4. Cap nhat hang hoa\n");
    printf("5. Xoa hang hoa\n");
    printf("6. Thong ke ton kho\n");
    printf("7. Sap xep theo gia ban (tang dan)\n");
    printf("8. Canh bao hang sap het\n");
    printf("0. Thoat\n");
    printf("==========================================\n");
}

void themHangHoa()
{
    int n;

    if (soLuongHang >= 100)
    {
        printf("Danh sach da day!\n");
        return;
    }

    do
    {
        if (!nhapSoNguyen("Nhap so luong hang can them: ", &n))
        {
            printf("  >> Vui long nhap so nguyen!\n");
            n = -1;
        }
        else if (n <= 0 || n > 100 - soLuongHang)
        {
            printf("  >> So luong phai tu 1 den %d!\n",
                   100 - soLuongHang);
        }
    }
    while (n <= 0 || n > 100 - soLuongHang);

    for (int i = 0; i < n; i++)
    {
        printf("\n--- Nhap hang thu %d ---\n", i + 1);

        while (1)
        {
            printf("Ma hang: ");
            scanf("%14s", ds[soLuongHang].maHang);
            xoaBoDem();

            if (kiemTraTrungMa(ds[soLuongHang].maHang))
            {
                printf("  >> Ma hang da ton tai! Nhap lai.\n");
            }
            else
            {
                break;
            }
        }

        printf("Ten hang: ");
        fgets(ds[soLuongHang].tenHang, 50, stdin);
        ds[soLuongHang].tenHang[
            strcspn(ds[soLuongHang].tenHang, "\n")] = '\0';

        printf("Loai hang: ");
        fgets(ds[soLuongHang].loaiHang, 30, stdin);
        ds[soLuongHang].loaiHang[
            strcspn(ds[soLuongHang].loaiHang, "\n")] = '\0';

        while (!nhapSoThuc("Gia nhap: ",
                            &ds[soLuongHang].giaNhap)
               || ds[soLuongHang].giaNhap < 0)
        {
            printf("  >> Gia nhap phai la so khong am!\n");
        }

        while (!nhapSoThuc("Gia ban: ",
                            &ds[soLuongHang].giaBan)
               || ds[soLuongHang].giaBan < 0)
        {
            printf("  >> Gia ban phai la so khong am!\n");
        }

        while (!nhapSoNguyen("So luong: ",
                              &ds[soLuongHang].soLuong)
               || ds[soLuongHang].soLuong < 0)
        {
            printf("  >> So luong phai la so nguyen khong am!\n");
        }

        soLuongHang++;
        printf("Them hang hoa thanh cong!\n");
    }
}

void hienThiDanhSach()
{
    if (soLuongHang == 0)
    {
        printf("\nDanh sach hang hoa rong!\n");
        return;
    }

    printf("\n========== DANH SACH HANG HOA (%d mat hang) ==========\n",
           soLuongHang);

    for (int i = 0; i < soLuongHang; i++)
    {
        printf("\nMa hang: %s\n", ds[i].maHang);
        printf("Ten hang: %s\n", ds[i].tenHang);
        printf("Loai hang: %s\n", ds[i].loaiHang);
        printf("Gia nhap: %.2f\n", ds[i].giaNhap);
        printf("Gia ban: %.2f\n", ds[i].giaBan);
        printf("So luong: %d\n", ds[i].soLuong);
        printf("--------------------------------------\n");
    }
}

void timKiemHangHoa()
{
    char tuKhoa[50];
    int timThay = 0;

    printf("Nhap ma hoac ten hang can tim: ");
    fgets(tuKhoa, 50, stdin);
    tuKhoa[strcspn(tuKhoa, "\n")] = '\0';

    for (int i = 0; i < soLuongHang; i++)
    {
        if (strcmp(ds[i].maHang, tuKhoa) == 0 ||
            strstr(ds[i].tenHang, tuKhoa) != NULL)
        {
            printf("\nMa hang: %s\n", ds[i].maHang);
            printf("Ten hang: %s\n", ds[i].tenHang);
            printf("Loai hang: %s\n", ds[i].loaiHang);
            printf("Gia nhap: %.2f\n", ds[i].giaNhap);
            printf("Gia ban: %.2f\n", ds[i].giaBan);
            printf("So luong: %d\n", ds[i].soLuong);

            timThay = 1;
        }
    }

    if (!timThay)
    {
        printf("Khong tim thay hang hoa!\n");
    }
}

void capNhatHangHoa()
{
    char ma[15];
    int timThay = 0;

    printf("Nhap ma hang can cap nhat: ");
    scanf("%14s", ma);
    xoaBoDem();

    for (int i = 0; i < soLuongHang; i++)
    {
        if (strcmp(ds[i].maHang, ma) == 0)
        {
            timThay = 1;

            printf("Nhap ten hang moi: ");
            fgets(ds[i].tenHang, 50, stdin);
            ds[i].tenHang[
                strcspn(ds[i].tenHang, "\n")] = '\0';

            printf("Nhap loai hang moi: ");
            fgets(ds[i].loaiHang, 30, stdin);
            ds[i].loaiHang[
                strcspn(ds[i].loaiHang, "\n")] = '\0';

            while (!nhapSoThuc("Nhap gia nhap moi: ",
                                &ds[i].giaNhap)
                   || ds[i].giaNhap < 0)
            {
                printf("  >> Gia nhap phai la so khong am!\n");
            }

            while (!nhapSoThuc("Nhap gia ban moi: ",
                                &ds[i].giaBan)
                   || ds[i].giaBan < 0)
            {
                printf("  >> Gia ban phai la so khong am!\n");
            }

            while (!nhapSoNguyen("Nhap so luong moi: ",
                                  &ds[i].soLuong)
                   || ds[i].soLuong < 0)
            {
                printf("  >> So luong phai la so nguyen khong am!\n");
            }

            printf("Cap nhat thanh cong!\n");
            break;
        }
    }

    if (!timThay)
    {
        printf("Khong tim thay ma hang!\n");
    }
}

void xoaHangHoa()
{
    char ma[15];
    int timThay = 0;

    printf("Nhap ma hang can xoa: ");
    scanf("%14s", ma);
    xoaBoDem();

    for (int i = 0; i < soLuongHang; i++)
    {
        if (strcmp(ds[i].maHang, ma) == 0)
        {
            for (int j = i; j < soLuongHang - 1; j++)
            {
                ds[j] = ds[j + 1];
            }

            soLuongHang--;
            printf("Xoa hang hoa thanh cong!\n");
            timThay = 1;
            break;
        }
    }

    if (!timThay)
    {
        printf("Khong tim thay ma hang!\n");
    }
}

void thongKeTonKho()
{
    int tongSoLuong = 0;
    double tongVonTonKho = 0;
    double tongGiaTriBan = 0;
    double tongLoiNhuan = 0;

    if (soLuongHang == 0)
    {
        printf("\nDanh sach hang hoa rong!\n");
        return;
    }

    for (int i = 0; i < soLuongHang; i++)
    {
        tongSoLuong += ds[i].soLuong;
        tongVonTonKho += ds[i].giaNhap * ds[i].soLuong;
        tongGiaTriBan += ds[i].giaBan * ds[i].soLuong;
        tongLoiNhuan +=
            (ds[i].giaBan - ds[i].giaNhap) * ds[i].soLuong;
    }

    printf("\n========== THONG KE TON KHO ==========\n");
    printf("Tong so mat hang: %d\n", soLuongHang);
    printf("Tong so luong ton kho: %d\n", tongSoLuong);
    printf("Tong von hang ton kho: %.0f VND\n", tongVonTonKho);
    printf("Gia tri ban du kien: %.0f VND\n", tongGiaTriBan);
    printf("Loi nhuan gop du kien: %.0f VND\n", tongLoiNhuan);
    printf("======================================\n");
}

void sapXepTheoGiaBan()
{
    struct HangHoa tam;

    for (int i = 0; i < soLuongHang - 1; i++)
    {
        for (int j = i + 1; j < soLuongHang; j++)
        {
            if (ds[i].giaBan > ds[j].giaBan)
            {
                tam = ds[i];
                ds[i] = ds[j];
                ds[j] = tam;
            }
        }
    }

    printf("Da sap xep theo gia ban tang dan!\n");
    hienThiDanhSach();
}

void canhBaoTonKho()
{
    int coHangSapHet = 0;

    printf("\n========== CANH BAO TON KHO ==========\n");

    for (int i = 0; i < soLuongHang; i++)
    {
        if (ds[i].soLuong <= 5)
        {
            printf("Ma hang: %s\n", ds[i].maHang);
            printf("Ten hang: %s\n", ds[i].tenHang);
            printf("So luong con lai: %d\n", ds[i].soLuong);
            printf("--------------------------------------\n");
            coHangSapHet = 1;
        }
    }

    if (!coHangSapHet)
    {
        printf("Khong co mat hang nao sap het!\n");
    }
}
