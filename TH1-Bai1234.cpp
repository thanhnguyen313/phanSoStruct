#include <iostream>

using namespace std;

struct phanso
{
    int tu;
    int mau;
    phanso& operator=(const phanso &n2)
    {
        if(this != &n2)
        {
            tu = n2.tu;
            mau = n2.mau;
        }
        return *this;
    }
};
struct mangps {
    phanso* ps;
    int n;
};
istream& operator>>(istream& is, phanso& ps)
{
    cout << "Nhap tu so: ";
    is >> ps.tu;
    do
    {
        cout << "Nhap mau so khac 0: ";
        is >> ps.mau;
    } while (ps.mau == 0);
    return is;
}
ostream& operator<<(ostream& os, const phanso& ps) 
{
    os << ps.tu << "/" << ps.mau;
    return os;
}
void Khoitaops(phanso &n)
{
    n.tu = 0;
    n.mau = 1;
}
int UCLN(int a, int b)
{
    a = (a < 0) ? -a : a;
    b = (b < 0) ? -b : b;
    while(b != 0)
    {
        int temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}
void Rutgon(phanso &n)
{
    int ucln = UCLN(n.tu, n.mau);
    n.tu /= ucln;
    n.mau /= ucln;
}
void Nhap(phanso &n)
{
    cout << "Moi ban nhap phan so\n"; 
    cin >> n;
}
void Xuat(phanso &n)
{
    Rutgon(n);
    cout << n;
    cout << endl;
}
void Sosanh(phanso &n1, phanso &n2)
{
    Rutgon(n1);
    Rutgon(n2);
    if(n1.tu * n2.mau > n2.tu * n1.mau)
        cout << n1 << " > " << n2;
    if(n1.tu * n2.mau < n2.tu * n1.mau) 
        cout << n1 << " < " << n2;
    if(n1.tu * n2.mau == n2.tu * n1.mau)
        cout << n1 << " = " << n2;
}
phanso operator+(phanso n1, phanso n2)
{
    phanso psTong;
    psTong.tu = n1.tu*n2.mau + n2.tu*n1.mau;
    psTong.mau = n1.mau * n2.mau;
    return psTong;
}
phanso operator-(phanso n1, phanso n2)
{
    phanso psHieu;
    psHieu.tu = n1.tu*n2.mau - n2.tu*n1.mau;
    psHieu.mau = n1.mau * n2.mau;
    return psHieu;
}
phanso operator*(phanso n1, phanso n2)
{
    phanso psTich;
    psTich.tu = n1.tu * n2.tu;
    psTich.mau = n1.mau * n2.mau;
    return psTich;
}
phanso operator/(phanso n1, phanso n2)
{
    phanso psThuong;
    psThuong.tu = n1.tu * n2.mau;
    psThuong.mau = n1.mau * n2.tu;
    return psThuong;
}
bool operator>(phanso n1, phanso n2)
{
    return double(n1.tu)/n1.mau > double(n2.tu)/n2.mau;

}
bool operator<(phanso n1, phanso n2)
{
    return double(n1.tu)/n1.mau < double(n2.tu)/n2.mau;

}
bool operator>=(phanso n1, phanso n2)
{
    return double(n1.tu)/n1.mau >= double(n2.tu)/n2.mau;

}
bool operator<=(phanso n1, phanso n2)
{
    return double(n1.tu)/n1.mau <= double(n2.tu)/n2.mau;

}
bool operator==(phanso n1, phanso n2)
{
    return double(n1.tu)/n1.mau == double(n2.tu)/n2.mau;

}
void Sort(mangps &mps)
{
    for(int i = 0; i < mps.n; i++)
            {
                phanso temp;
                Khoitaops(temp);
                if(mps.ps[i] >= mps.ps[i+1])
                {
                    temp = mps.ps[i+1];
                    mps.ps[i+1] = mps.ps[i];
                    mps.ps[i] = temp;
                }
            }
}
void NhapMang(mangps &mps)
{
    cout << "Ban nhap so phan tu cua mang: \n";
    cin >> mps.n;
    mps.ps = new phanso[mps.n];
    for(int i = 0; i < mps.n; i++)
    {
        Nhap(mps.ps[i]);
    } 
}
void XuatMang(mangps &mps)
{
    cout << "\nMang phan so sau khi sap xep la: ";
    for(int i = 0; i < mps.n; i++)
    {
        cout << mps.ps[i] << " ";
    }
}


int main()
{
    phanso n1, n2;
    Khoitaops(n1);
    Khoitaops(n2);
    int chon;
    do
    {
        cout << "----------CHUONG TRINH STRUCT XU LY PHAN SO----------\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "1. Nhap mot phan so, rut gon phan so va xuat ket qua\n";
        cout << "2. Nhap hai phan so, tim phan so lon nhat va xuat ket qua\n";
        cout << "3. Nhap vao hai phan so, tinh tong, hieu, tich, thuong giua chung va xuat ket qua\n";
        cout << "4. Nhap day gom n phan so, sap xep day phan so, tim phan so lon nhat va xuat ket qua\n ";
        cout << "Ban chon: \n";
        cin >> chon;

        switch (chon)
        {
        case 0:
            cout << "Chuong trinh dang thoat...";
            break;
        case 1:
            Nhap(n1);
            Xuat(n1);
            break;
        case 2:
            Nhap(n1);
            Nhap(n2);
            Sosanh(n1, n2);
            break;
        case 3:
        {
            Nhap(n1);
            Nhap(n2);
            phanso psTong = n1 + n2;
            phanso psHieu = n1 - n2;
            phanso psTich = n1 * n2;
            Xuat(psTong);
            Xuat(psHieu);
            Xuat(psTich);
            if(n1.tu == 0 || n2.tu == 0)
                cout << "Hai phan so nay khong the chia cho nhau";
            else
            {
                phanso psThuong = n1 * n2;
                Xuat(psThuong);
            }
            break;
        }
        case 4:
        {
            mangps mps;
            NhapMang(mps);
            phanso psMAX;
            Khoitaops(psMAX);
            Sort(mps);
            psMAX = mps.ps[mps.n-1];
            XuatMang(mps);
            cout << "\nPhan so lon nhat trong mang la: ";
            Xuat(psMAX);
            break;
        }

        default:
        cout << "Ban chon sai, moi ban chon lai";
            break;
        }
        cout << endl;
    } while (chon != 0);
    return 0;
}