/******************************************************************************
 * Họ và tên: [ĐIỀN TÊN TẠI ĐÂY]
 * MSSV:      [ĐIỀN MSSV TẠI ĐÂY]
 * Lớp:       [ĐIỀN LỚP TẠI ĐÂY]
 *****************************************************************************/

// Tạo file asm2.c và hoàn thiện nội dung Assignment từ nội dung file asm1.c


// Danh sách các chức năng trong ASM1:
// 1. Chức năng số 1: Kiểm tra số nguyên
// 2. Chức năng số 2. Tìm Ước số chung và bội số chung của 2 số 
// 3. Chức năng số 3: Chương trình tính tiền cho quán Karaoke
// 4. Chức năng số 4: Tính tiền điện 
// 5. Chức năng số 5: Chức năng đổi tiền 
// 6. Chức năng số 6: Xây dựng chức năng tính lãi suất vay ngân hàng vay trả góp 
// 7. Chức năng số 7: Xây dựng chương trình vay tiền mua xe
// 8. Chức năng số 8: Sắp xếp thông tin sinh viên
// 9. Chức năng số 9: Xây dựng game FPOLY-LOTT
// 10. Chức năng số 10: Xây dựng chương trình tính toán phân số 
// Viết chương trình C thực hiện các chức năng trên

#include <stdio.h>
int main() {
    int chonChucNang;

    do {
        printf("Chon chuc nang:\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Tim Uoc so chung va boi so chung cua 2 so\n");
        printf("3. Tinh tien cho quan Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Chuc nang doi tien\n");
        printf("6. Tinh lai suat vay ngan hang vay tra gop\n");
        printf("7. Vay tien mua xe\n");
        printf("8. Sap xep thong tin sinh vien\n");
        printf("9. Game FPOLY-LOTT\n");
        printf("10. Tinh toan phan so\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &chonChucNang);

        switch (chonChucNang) {
            case 1: {
                // Khai bao bien x trong case thi phai co ngoac nhon bao quanh case 1
                float x;
                printf("\n--- DA CHON CHUC NANG 1: KIEM TRA SO NGUYEN ---\n");
                printf("Nhap vao mot so bat ky: ");
                scanf("%f", &x);

                if (x == (int)x) {
                    int n = (int)x;
                    printf("%d la so nguyen.\n", n);
                    
                    // Kiem tra so nguyen to
                    int isPrime = 1; 
                    if (n < 2) isPrime = 0; 
                    else {
                        for (int i = 2; i * i <= n; i++) {
                            if (n % i == 0) { isPrime = 0; break; }
                        }
                    }
                    if (isPrime == 1) printf("%d la so nguyen to.\n", n);
                    else printf("%d khong phai so nguyen to.\n", n);

                    // Kiem tra so chinh phuong
                    int isChinhPhuong = 0; 
                    if (n >= 0) {
                        for (int i = 0; i * i <= n; i++) {
                            if (i * i == n) { isChinhPhuong = 1; break; }
                        }
                    }
                    if (isChinhPhuong == 1) printf("%d la so chinh phuong.\n", n);
                    else printf("%d khong phai so chinh phuong.\n", n);
                } else {
                    printf("%f khong phai la so nguyen.\n", x);
                }
                break;
            } // Ket thuc ngoac nhon cua case 1
            
            case 2: {
                int a, b;
                printf("\n--- DA CHON CHUC NANG 2: TIM UCLN VA BCNN ---\n");
                printf("Nhap so nguyen a: "); scanf("%d", &a);
                printf("Nhap so nguyen b: "); scanf("%d", &b);

                if (a == 0 && b == 0) {
                    printf("Khong co UCLN va BCNN cho hai so 0.\n");
                } else {
                    int a1 = a;
                    int b1 = b;

                    if (a1 < 0) a1 = -a1;
                    if (b1 < 0) b1 = -b1;

                    if (a1 == 0) {
                        printf("UCLN la: %d\nKhong co BCNN vi co mot so bang 0.\n", b1);
                    } else if (b1 == 0) {
                        printf("UCLN la: %d\nKhong co BCNN vi co mot so bang 0.\n", a1);
                    } else {
                        int original_a1 = a1;
                        int original_b1 = b1;

                        while (a1 != b1) {
                            if (a1 > b1) a1 = a1 - b1;
                            else b1 = b1 - a1;
                        }
                        int ucln = a1;
                        int bcnn = (original_a1 * original_b1) / ucln;

                        printf("Uoc chung lon nhat cua %d va %d la: %d\n", a, b, ucln);
                        printf("Boi chung nho nhat cua %d va %d la: %d\n", a, b, bcnn);
                    }
                }
                break;
            }
            case 3: {
                int gioBatDau, gioKetThuc;
                printf("\n--- DA CHON CHUC NANG 3: TINH TIEN CHO QUAN KARAOKE ---\n");
                printf("Nhap gio bat dau (12 - 23): ");
                scanf("%d", &gioBatDau);
                printf("Nhap gio ket thuc (12 - 23): ");
                scanf("%d", &gioKetThuc);

                // Kiem tra dieu kien gio hop le (Quan chi mo tu 12h den 23h)
                if (gioBatDau >= gioKetThuc || gioBatDau < 12 || gioKetThuc > 23) {
                    printf("Gio nhap vao khong hop le! Vui long kiem tra lai.\n");
                } else {
                    int soGio = gioKetThuc - gioBatDau;
                    float tongTien = 0;
                    int giaTien1Gio = 150000; // Gia dinh muc gia 150.000 VND/1h

                    // Tinh tien theo so gio
                    if (soGio <= 3) {
                        tongTien = soGio * giaTien1Gio;
                    } else {
                        // Tu gio thu 4 tro di giam 30% (nhan voi 0.7)
                        tongTien = (3 * giaTien1Gio) + ((soGio - 3) * giaTien1Gio * 0.7);
                    }

                    // Giam them 10% neu bat dau trong khung gio vang (14h - 17h)
                    if (gioBatDau >= 14 && gioBatDau <= 17) {
                        tongTien = tongTien * 0.9;
                    }

                    printf("Tong tien Karaoke phai thanh toan: %.0f VND\n", tongTien);
                }
                break;
            } // Ket thuc ngoac nhon cua case 3

            case 4: {
                float soDien, tienDien = 0;
                printf("\n--- DA CHON CHUC NANG 4: TINH TIEN DIEN ---\n");
                printf("Nhap vao so dien tieu thu (kWh): ");
                scanf("%f", &soDien);

                if (soDien < 0) {
                    printf("So dien khong the am. Vui long kiem tra lai!\n");
                } else {
                    // Tinh tien dien theo bac thang
                    if (soDien <= 50) {
                        tienDien = soDien * 1678;
                    } else if (soDien <= 100) {
                        tienDien = 50 * 1678 + (soDien - 50) * 1734;
                    } else if (soDien <= 200) {
                        tienDien = 50 * 1678 + 50 * 1734 + (soDien - 100) * 2014;
                    } else if (soDien <= 300) {
                        tienDien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (soDien - 200) * 2536;
                    } else if (soDien <= 400) {
                        tienDien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (soDien - 300) * 2834;
                    } else {
                        tienDien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (soDien - 400) * 2927;
                    }
                    
                    printf("Tong tien dien phai tra: %.0f VND\n", tienDien);
                }
                break;
            } // Ket thuc ngoac nhon cua case 4
            case 5: {
                int soTien;
                printf("\n--- DA CHON CHUC NANG 5: DOI TIEN ---\n");
                printf("Nhap so tien can doi (boi so cua 10.000 VND): ");
                scanf("%d", &soTien);

                // Kiem tra dieu kien: tien phai > 0 va chia het cho 10.000
                if (soTien <= 0 || soTien % 10000 != 0) {
                    printf("So tien khong hop le! Vui long nhap so duong chia het cho 10.000.\n");
                } else {
                    // Mang chua 6 menh gia tu lon den be
                    int menhGia[6] = {500000, 200000, 100000, 50000, 20000, 10000};
                    int soLuongTo;
                    
                    printf("Chi tiet doi tien cho %d VND:\n", soTien);
                    for (int i = 0; i < 6; i++) {
                        // Lay phan nguyen de biet duoc may to
                        soLuongTo = soTien / menhGia[i]; 
                        
                        if (soLuongTo > 0) {
                            printf("- %d to %d VND\n", soLuongTo, menhGia[i]);
                            // Lay phan du de tinh so tien con lai chua the doi duoc bang menh gia nay
                            soTien = soTien % menhGia[i]; 
                        }
                    }
                }
                break;
            } // Ket thuc ngoac nhon cua case 5

            case 6: {
                float tienVay, laiSuatNam, tienGocThang, tienLaiThang, tongTienThang;
                int thoiHan;
                
                printf("\n--- DA CHON CHUC NANG 6: TINH LAI SUAT VAY TRA GOP ---\n");
                printf("Nhap so tien can vay (VND): ");
                scanf("%f", &tienVay);
                printf("Nhap lai suat 1 nam (vi du 5%% thi nhap 5): ");
                scanf("%f", &laiSuatNam);
                printf("Nhap thoi han vay (thang): ");
                scanf("%d", &thoiHan);

                if (tienVay <= 0 || laiSuatNam <= 0 || thoiHan <= 0) {
                    printf("Du lieu nhap khong hop le. Vui long kiem tra lai!\n");
                } else {
                    // Tinh lai suat tung thang = (Lai suat nam / 100) / 12
                    float laiSuatThang = laiSuatNam / 100 / 12; 
                    
                    // Tien goc phai tra co dinh moi thang
                    tienGocThang = tienVay / thoiHan; 
                    float duNoConLai = tienVay;
                    
                    printf("\nLich su tra no hang thang:\n");
                    printf("Thang | Goc phai tra | Lai phai tra | Tong tien tra | Du no con lai\n");
                    printf("--------------------------------------------------------------------\n");
                    
                    for (int i = 1; i <= thoiHan; i++) {
                        // Lai thang hien tai = Du no con lai * lai suat thang
                        tienLaiThang = duNoConLai * laiSuatThang; 
                        
                        tongTienThang = tienGocThang + tienLaiThang;
                        duNoConLai = duNoConLai - tienGocThang; // Giam du no
                        
                        // Xu ly de du no thang cuoi cung khong bi am (do sai so cua kieu float)
                        if (duNoConLai < 0) {
                            duNoConLai = 0;
                        }

                        // In bang can le dep mat (%6d la can phai 6 ky tu, %12.0f la in 12 ky tu khong lay so thap phan)
                        printf("%5d | %12.0f | %12.0f | %13.0f | %12.0f\n", i, tienGocThang, tienLaiThang, tongTienThang, duNoConLai);
                    }
                }
                break;
            } // Ket thuc ngoac nhon cua case 6
           case 7: {
                // Bai toan dac trung: Vay mua xe tra gop (thuong mac dinh lai suat co dinh 7.2%/nam)
                float giaXe, phanTramVay;
                int thoiHanVay;
                
                printf("\n--- DA CHON CHUC NANG 7: VAY TIEN MUA XE ---\n");
                printf("Nhap gia tri chiec xe ban muon mua (VND): ");
                scanf("%f", &giaXe);
                
                printf("Nhap phan tram muon vay tu ngan hang (Toi da 80%%): ");
                scanf("%f", &phanTramVay);
                
                if (phanTramVay > 80 || phanTramVay <= 0 || giaXe <= 0) {
                    printf("Phan tram vay hoac gia xe khong hop le! Ngan hang chi cho vay toi da 80%%.\n");
                } else {
                    printf("Nhap thoi han vay (tinh theo nam, toi da 24 nam): ");
                    scanf("%d", &thoiHanVay);
                    
                    if (thoiHanVay > 24 || thoiHanVay <= 0) {
                        printf("Thoi han vay khong hop le!\n");
                    } else {
                        float tienVay = giaXe * (phanTramVay / 100);
                        float tienTraTruoc = giaXe - tienVay;
                        float laiSuatNam = 0.072; // Co dinh 7.2%/nam theo form chuan
                        float laiSuatThang = laiSuatNam / 12;
                        
                        int soThang = thoiHanVay * 12;
                        float tienGocThang = tienVay / soThang;
                        float duNo = tienVay;
                        
                        printf("\n================ CHI TIET KHOAN VAY ================\n");
                        printf("Gia xe: %.0f VND\n", giaXe);
                        printf("Ban can thanh toan truoc: %.0f VND\n", tienTraTruoc);
                        printf("So tien vay ngan hang: %.0f VND\n", tienVay);
                        printf("Lai suat: 7.2%%/nam\n\n");
                        
                        printf("Ky han | Goc phai tra | Lai phai tra | Tong tien tra | Du no con lai\n");
                        printf("--------------------------------------------------------------------\n");
                        
                        // Chi in ra man hinh toi da 24 thang dau de tranh viec in qua dai (vi vay 24 nam len toi 288 thang)
                        int soThangHienThi = (soThang > 24) ? 24 : soThang;
                        
                        for (int i = 1; i <= soThang; i++) {
                            float tienLaiThang = duNo * laiSuatThang;
                            float tongTienThang = tienGocThang + tienLaiThang;
                            duNo = duNo - tienGocThang;
                            
                            if (duNo < 0) duNo = 0; // Lam tron so
                            
                            if (i <= soThangHienThi) {
                                printf("%6d | %12.0f | %12.0f | %13.0f | %12.0f\n", i, tienGocThang, tienLaiThang, tongTienThang, duNo);
                            }
                        }
                        if (soThang > 24) {
                            printf("... (Da an cac thang tiep theo de bang bot dai)\n");
                        }
                    }
                }
                break;
            } // Ket thuc ngoac nhon cua case 7

            case 8: {
                int n;
                printf("\n--- DA CHON CHUC NANG 8: SAP XEP THONG TIN SINH VIEN ---\n");
                printf("Nhap so luong sinh vien: ");
                scanf("%d", &n);
                
                if (n <= 0) {
                    printf("So luong sinh vien phai lon hon 0!\n");
                } else {
                    char ten[100][50]; 
                    float diem[100];
                    
                    // 1. Nhap thong tin
                    for (int i = 0; i < n; i++) {
                        printf("\nNhap ten sinh vien thu %d: ", i + 1);
                        while(getchar() != '\n'); // Xoa bo nho dem
                        scanf("%[^\n]", ten[i]); // Nhap chuoi co khoang trang
                        
                        printf("Nhap diem cua sinh vien %s: ", ten[i]);
                        scanf("%f", &diem[i]);
                    }
                    
                    // 2. Thuat toan sap xep noi bot (Bubble Sort) - Giam dan
                    for (int i = 0; i < n - 1; i++) {
                        for (int j = i + 1; j < n; j++) {
                            if (diem[i] < diem[j]) {
                                // Hoan vi diem
                                float tempDiem = diem[i];
                                diem[i] = diem[j];
                                diem[j] = tempDiem;
                                
                                // Hoan vi ten (SAO CHEP THU CONG, KHONG DUNG STRING.H)
                                char tempTen[50];
                                int k;
                                
                                // Buoc 1: Copy ten[i] sang tempTen
                                k = 0;
                                while (ten[i][k] != '\0') {
                                    tempTen[k] = ten[i][k];
                                    k++;
                                }
                                tempTen[k] = '\0'; // Chot so chuoi bang ky tu Null
                                
                                // Buoc 2: Copy ten[j] sang ten[i]
                                k = 0;
                                while (ten[j][k] != '\0') {
                                    ten[i][k] = ten[j][k];
                                    k++;
                                }
                                ten[i][k] = '\0';
                                
                                // Buoc 3: Copy tempTen sang ten[j]
                                k = 0;
                                while (tempTen[k] != '\0') {
                                    ten[j][k] = tempTen[k];
                                    k++;
                                }
                                ten[j][k] = '\0';
                            }
                        }
                    }
                    
                    // 3. Xuat danh sach ra man hinh
                    printf("\n--- DANH SACH SINH VIEN (TU CAO XUONG THAP) ---\n");
                    printf("%-20s | %-5s | %-15s\n", "Ho va ten", "Diem", "Hoc luc");
                    printf("------------------------------------------------\n");
                    
                    for (int i = 0; i < n; i++) {
                        // In ten va diem truoc, khong xuong dong
                        printf("%-20s | %5.1f | ", ten[i], diem[i]);
                        
                        // In truc tiep hoc luc roi moi xuong dong (\n) de ne viec dung string.h
                        if (diem[i] >= 9) printf("%-15s\n", "Xuat sac");
                        else if (diem[i] >= 8) printf("%-15s\n", "Gioi");
                        else if (diem[i] >= 6.5) printf("%-15s\n", "Kha");
                        else if (diem[i] >= 5) printf("%-15s\n", "Trung binh");
                        else printf("%-15s\n", "Yeu");
                    }
                }
                break;
            } // Ket thuc ngoac nhon cua case 8
            case 9:
                // Gọi hàm game FPOLY-LOTT
                printf("DA CHON CHUC NANG 9: GAME FPOLY-LOTT\n");
                break;
            case 10:
                // Gọi hàm tính toán phân số
                printf("DA CHON CHUC NANG 10: TINH TOAN PHAN SO\n");
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (chonChucNang != 0);
    

    return 0;
}