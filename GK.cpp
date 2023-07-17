//#include<bits/stdc.h++>
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class NhanVien
{
	string maso;
	string hoten;
	float luongcb;
public:
	//get-set
	float getLuongcb(){return luongcb;}
	NhanVien(string _hoten="hoten",string _maso="maso",float _luongcb=0)
	{
		hoten=_hoten;
		maso=_maso;
		luongcb=_luongcb;
	}
	NhanVien(const NhanVien&nv)
	{
		hoten=nv.hoten;
		maso=nv.maso;
		luongcb=nv.luongcb;
	}
	~NhanVien(){};
	//ham truu tuong
	virtual double getTinhLuong()=0;
	virtual string getLoaiNV()=0;
	
	void Xuat()
	{
		cout<<"Loai nhan vien: "<<getLoaiNV()<<endl;
		cout<<"Ma nhan vien: "<<maso<<endl;
		cout<<"Ho ten:"<<hoten<<endl;
	}
	
};
class BC: public NhanVien
{
	float hesoluong;
	float hesophucap;
};
int main()
{
	return 0;
}
