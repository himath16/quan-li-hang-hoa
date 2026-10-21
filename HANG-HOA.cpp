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
    int luaChon;
    
    printf("==============================================\n");
    printf("   CHUONG TRINH QUAN LY HANG HOA\n");
    printf("==============================================\n");

    do 
    {
        hienThiMenu();
        printf("Moi ban chon chuc nang: ");
        if (scanf("%d", &luaChon) != 1) {
            printf("  >> Vui long nhap mot so!\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
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
    int n, i, k;

    if (soLuongHang >= 100) 
    {
        printf("Danh sach da day!\n");
        return;
    }

    printf("Nhap so luong hang can them: ");
    scanf("%d", &n);
    getchar();

    for (i = 0; i < n; i++) 
    {
        if (soLuongHang >= 100) 
        {
            printf("Danh sach da day!\n");
            break;
        }

        printf("\n--- Nhap hang thu %d ---\n", i + 1);

        while (1) 
        {
            int trung = 0;
            printf("Ma hang: ");
            scanf("%14s", ds[soLuongHang].maHang);
            getchar();
            for (k = 0; k < soLuongHang; k++)
                {
                if (strcmp(ds[k].maHang,
                           ds[soLuongHang].maHang) == 0) 
                    {
                        trung = 1;
                        break;
                    }
            }
            if (trung) 
            {
                printf("  >> Ma hang da ton tai! Nhap lai.\n");
                continue;
            }
            break;
        }

        printf("Ten hang: ");
        fgets(ds[soLuongHang].tenHang, 50, stdin);
        ds[soLuongHang].tenHang[
            strcspn(ds[soLuongHang].tenHang, "\n")] = '\0';

        printf("Loai hang: ");
        fgets(ds[soLuongHang].loaiHang, 30, stdin);
        ds[soLuongHang].loaiHang[
            strcspn(ds[soLuongHang].loaiHang, "\n")] = '\0';

        do 
            {
            printf("Gia nhap: ");
            scanf("%f", &ds[soLuongHang].giaNhap);
            getchar();
            if (ds[soLuongHang].giaNhap < 0) {
                printf("  >> Gia nhap khong duoc am! Nhap lai.\n");
            }
        } 
            while (ds[soLuongHang].giaNhap < 0);

        do 
        {
            printf("Gia ban: ");
            scanf("%f", &ds[soLuongHang].giaBan);
            getchar();
            if (ds[soLuongHang].giaBan < 0) {
                printf("  >> Gia ban khong duoc am! Nhap lai.\n");
            }
        } while (ds[soLuongHang].giaBan < 0);

        do {
            printf("So luong: ");
            scanf("%d", &ds[soLuongHang].soLuong);
            getchar();
            if (ds[soLuongHang].soLuong < 0) {
                printf("  >> So luong khong duoc am! Nhap lai.\n");
            }
        } while (ds[soLuongHang].soLuong < 0);

        soLuongHang++;
        printf("Them hang hoa thanh cong!\n");
    }
}

void hienThiDanhSach() {
    int i;

    if (soLuongHang == 0) {
        printf("\nDanh sach hang hoa rong!\n");
        return;
    }

    printf("\n========== DANH SACH HANG HOA (%d mat hang) ==========\n",
           soLuongHang);
    for (i = 0; i < soLuongHang; i++) {
        printf("\nMa hang: %s\n", ds[i].maHang);
        printf("Ten hang: %s\n", ds[i].tenHang);
        printf("Loai hang: %s\n", ds[i].loaiHang);
        printf("Gia nhap: %.2f\n", ds[i].giaNhap);
        printf("Gia ban: %.2f\n", ds[i].giaBan);
        printf("So luong: %d\n", ds[i].soLuong);
        printf("--------------------------------------\n");
    }
}

void timKiemHangHoa() {
    char tuKhoa[50];
    int i, timThay = 0;
    printf("Nhap ma hoac ten hang can tim: ");
    fgets(tuKhoa, 50, stdin);
    tuKhoa[strcspn(tuKhoa, "\n")] = '\0';
    for (i = 0; i < soLuongHang; i++) {
        if (strcmp(ds[i].maHang, tuKhoa) == 0 ||
            strstr(ds[i].tenHang, tuKhoa) != NULL) {

            printf("\nMa hang: %s\n", ds[i].maHang);
            printf("Ten hang: %s\n", ds[i].tenHang);
            printf("Loai hang: %s\n", ds[i].loaiHang);
            printf("Gia nhap: %.2f\n", ds[i].giaNhap);
            printf("Gia ban: %.2f\n", ds[i].giaBan);
            printf("So luong: %d\n", ds[i].soLuong);

            timThay = 1;
        }
    }
    if (timThay == 0) {
        printf("Khong tim thay hang hoa!\n");
    }
}

void capNhatHangHoa() {
    char ma[15];
    int i, timThay = 0;

    printf("Nhap ma hang can cap nhat: ");
    scanf("%14s", ma);
    getchar();

    for (i = 0; i < soLuongHang; i++) {
        if (strcmp(ds[i].maHang, ma) == 0) {
            printf("Nhap ten hang moi: ");
            fgets(ds[i].tenHang, 50, stdin);
            ds[i].tenHang[
                strcspn(ds[i].tenHang, "\n")
            ] = '\0';

            printf("Nhap loai hang moi: ");
            fgets(ds[i].loaiHang, 30, stdin);
            ds[i].loaiHang[strcspn(ds[i].loaiHang, "\n")] = '\0';
            printf("Nhap gia nhap moi: ");
            scanf("%f", &ds[i].giaNhap);
            printf("Nhap gia ban moi: ");
            scanf("%f", &ds[i].giaBan);
            printf("Nhap so luong moi: ");
            scanf("%d", &ds[i].soLuong);
            getchar();
            printf("Cap nhat thanh cong!\n");
            timThay = 1;
            break;
        }
    }
    if (timThay == 0) {
        printf("Khong tim thay ma hang!\n");
    }
}

void xoaHangHoa() {
    char ma[15];
    int i, j, timThay = 0;
    printf("Nhap ma hang can xoa: ");
    scanf("%14s", ma);
    getchar();
    for (i = 0; i < soLuongHang; i++) {
        if (strcmp(ds[i].maHang, ma) == 0) {
            for (j = i; j < soLuongHang - 1; j++) {
                ds[j] = ds[j + 1];
            }
            soLuongHang--;
            printf("Xoa hang hoa thanh cong!\n");
            timThay = 1;
            break;
        }
    }
    if (timThay == 0) {
        printf("Khong tim thay ma hang!\n");
    }
}

void thongKeTonKho() {
    int i;
    int tongSoLuong = 0;
    float tongVonTonKho = 0;
    float tongGiaTriBan = 0;
    float tongLoiNhuan = 0;
    if (soLuongHang == 0) {
        printf("\nDanh sach hang hoa rong!\n");
        return;
    }
    for (i = 0; i < soLuongHang; i++) {
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

void sapXepTheoGiaBan() {
    int i, j;
    struct HangHoa tam;
    for (i = 0; i < soLuongHang - 1; i++) {
        for (j = i + 1; j < soLuongHang; j++) {
            if (ds[i].giaBan > ds[j].giaBan) {
                tam = ds[i];
                ds[i] = ds[j];
                ds[j] = tam;
            }
        }
    }
    printf("Da sap xep theo gia ban tang dan!\n");
    hienThiDanhSach();
}

void canhBaoTonKho() {
    int i;
    int coHangSapHet = 0;
    printf("\n========== CANH BAO TON KHO ==========\n");
    for (i = 0; i < soLuongHang; i++) {
        if (ds[i].soLuong <= 5) {
            printf("Ma hang: %s\n", ds[i].maHang);
            printf("Ten hang: %s\n", ds[i].tenHang);
            printf("So luong con lai: %d\n", ds[i].soLuong);
            printf("--------------------------------------\n");
            coHangSapHet = 1;
        }
    }
    if (coHangSapHet == 0) {
        printf("Khong co mat hang nao sap het!\n");
    }
}
