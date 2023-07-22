#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class NhanVien
{
protected:
	string maso;
	string hoten;
	int luongcb;
public:
	//get-set
	int getLuongCoBan();
	//khoi tao-huy
	NhanVien(string _hoten="hoten",string _maso="maso",int _luongcb=0);
	NhanVien(const NhanVien&nv);
	~NhanVien();
	//ham truu tuong
	virtual int getTinhLuong()=0;
	virtual string getLoaiNV()=0;
	//phuong thuc
	virtual void Nhap();
	virtual void Xuat();
};
class BienChe:public NhanVien
{
    protected:
    float hesoluong;
    int tienphucap;
    public:
    //get-set
    int getHeSoLuong();
    int getTienPhuCap();
    //khoi tao-huy
    BienChe(string _hoten="hoten",string _maso="maso",int _luongcb=0,
            int _hesoluong=0, int _tienphucap=0);
	BienChe(const BienChe&bc);
	~BienChe();
	
	virtual int getTinhLuong();
	virtual string getLoaiNV();
	virtual void Nhap();
	virtual void Xuat();
};
class HopDong:public NhanVien
{
    protected:
    int tiencong,songay;
    float hesovuotgio;
    public:
    HopDong(string _hoten="hoten",string _maso="maso",int _luongcb=0,
            int _tiencong=0, int _songay=0,float _hesovuotgio=0);
	HopDong(const HopDong&h);
	~HopDong();
	virtual int getTinhLuong();
	virtual string getLoaiNV();
	virtual void Nhap();
	virtual void Xuat();
};

int main()
{
	NhanVien *nv[100];
	int tongLuong=0;
	int luong;
	int n; cin>>n;
	string loai;
	for (int i=0;i<n;++i)
	{
	    cin>>loai;
		if(loai=="BC")
		{
			BienChe bc;
			bc.Nhap();
			nv[i]=new BienChe(bc);
		}
		else
		{
			HopDong hd;
			hd.Nhap();
			nv[i]=new HopDong(hd);
		}
	}
	for(int i=0;i<n;++i)
	{	
		nv[i]->Xuat();
		cout<<'\n';
		luong= nv[i]->getTinhLuong();
		tongLuong+=luong;

	}
	cout<<"Tong luong nhan vien: "<<tongLuong;
	return 0;
}

/***************HOP DONG***************/
HopDong::HopDong(string _hoten,string _maso,int _luongcb,
    int _tiencong, int _songay,float _hesovuotgio):NhanVien(_hoten,_maso,_luongcb)
{
    tiencong=_tiencong;
    songay=_songay;
    hesovuotgio=_hesovuotgio;
}
HopDong::HopDong(const HopDong&h):NhanVien(h)
{
    tiencong=h.tiencong;
    songay=h.songay;
    hesovuotgio=h.hesovuotgio;
}
HopDong::~HopDong(){};
int HopDong::getTinhLuong(){
    if (songay>22)
    {
        return luongcb+(songay-22)*hesovuotgio*tiencong;   
    }
    return luongcb;
}
string HopDong::getLoaiNV(){
    return "HD";
}
void HopDong::Nhap(){
    NhanVien::Nhap();
    cin>>tiencong>>songay>>hesovuotgio;
}
void HopDong::Xuat(){
    NhanVien::Xuat();
    cout<<"Tong luong: "<<getTinhLuong()<<'\n';
}
/***************BIEN CHE***************/
//get-set
int BienChe::getHeSoLuong()
{
    return hesoluong;
}
int BienChe::getTienPhuCap()
{
    return tienphucap;
}
//khoi tao-huy
BienChe::BienChe(string _hoten,string _maso,int _luongcb,
int _hesoluong, int _tienphucap):NhanVien(_hoten,_maso,_luongcb)
{
    hesoluong=_hesoluong;
    tienphucap=_tienphucap;
}
BienChe::BienChe(const BienChe&bc):NhanVien(bc)
{
    hesoluong=bc.hesoluong;
    tienphucap=bc.tienphucap;
}
BienChe::~BienChe(){};
//phuong thuc
int BienChe::getTinhLuong()
{
    return luongcb*hesoluong+tienphucap;
}
void BienChe::Nhap()
{
    NhanVien::Nhap();
    cin>>hesoluong>>tienphucap;
}
string BienChe::getLoaiNV()
{
    return "BC";    
}
void BienChe::Xuat()
{
    NhanVien::Xuat();
    cout<<"Tong luong: "<<getTinhLuong()<<'\n';
}
/***************NHAN VIEN***************/
//get-set
int NhanVien::getLuongCoBan() 
{ 
    return luongcb; 
}
//khoi tao-huy
NhanVien::NhanVien(string _hoten, string _maso, int _luongcb)
{
	hoten = _hoten;
	maso = _maso;
	luongcb = _luongcb;
}
NhanVien::NhanVien(const NhanVien& nv)
{
	hoten = nv.hoten;
	maso = nv.maso;
	luongcb = nv.luongcb;
}
NhanVien::~NhanVien() {};
//phuong thuc
void NhanVien::Nhap()
{
    cin>>maso;
    cin.ignore();
    getline(cin,hoten);
    cin>>luongcb;
}
void NhanVien::Xuat()
{
	cout << "Loai nhan vien: " << getLoaiNV() << '\n';
	cout << "Ma nhan vien: " << maso << '\n';
	cout << "Ho ten: " << hoten << '\n';
}
