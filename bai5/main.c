#include <stdio.h>

int main(void) {
    int N;
    long long gia_tri_don;

    int so_don_hop_le = 0;
    long long tong_doanh_thu_goc = 0;
    long long tong_tien_giam_gia = 0;
    long long tong_doanh_thu_thuc_thu = 0;

    printf("Nhap so luong hoa don: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("So luong hoa don phai lon hon 0!\n");
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        printf("Nhap gia tri don %d: ", i);
        scanf("%lld", &gia_tri_don);

        // Don am: dung ca ban hang
        if (gia_tri_don < 0) {
            printf("Don %d: Loi du lieu am! Dung he thong khan cap.\n", i);
            break;
        }

        // Don bang 0: don bi huy, bo qua
        if (gia_tri_don == 0) {
            printf("Don %d: Don hang bi huy - Bo qua\n", i);
            continue;
        }

        // Don hop le
        so_don_hop_le++;
        tong_doanh_thu_goc += gia_tri_don;

        long long tien_giam_gia = 0;
        long long thanh_tien = gia_tri_don;

        // Don tu 100000 tro len duoc giam 10%
        if (gia_tri_don >= 100000) {
            tien_giam_gia = gia_tri_don * 10 / 100;
            thanh_tien = gia_tri_don - tien_giam_gia;

            printf("Don %d: Ap dung giam gia 10%% (%lld VND) - Thanh tien: %lld VND\n", i, tien_giam_gia, thanh_tien);
        } else {
            printf("Don %d: Hop le - Thanh tien: %lld VND\n", i, thanh_tien);
        }

        tong_tien_giam_gia += tien_giam_gia;
        tong_doanh_thu_thuc_thu += thanh_tien;
    }

    printf("\n--- TONG KET CA BAN HANG ---\n");
    printf("So don hop le: %d\n", so_don_hop_le);
    printf("Tong doanh thu goc: %lld VND\n", tong_doanh_thu_goc);
    printf("Tong tien giam gia: %lld VND\n", tong_tien_giam_gia);
    printf("Tong doanh thu thuc thu: %lld VND\n", tong_doanh_thu_thuc_thu);

    return 0;
}