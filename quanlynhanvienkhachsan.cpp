#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void SetWindowSize(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width;
    WindowSize.Bottom = height;
 
    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}

void SetScreenBufferSize(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD NewSize;
    NewSize.X = width;
    NewSize.Y = height;

    SetConsoleScreenBufferSize(hStdout, NewSize);
}

void ShowScrollbar(BOOL Show)
{
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, Show);
}

BOOL WINAPI SetConsoleTitle(
    _In_ LPCTSTR lpConsoleTitle
);
    
class NhanVien{
    protected:
        string HoTen, QueQuan, MaNV;
        int SoNgayLam;
        long PhuCap;
        int NamVaoLam;
        long Tienthuong;
        string ChucVu;
    public:
    	NhanVien();
        ~NhanVien();
        virtual void Nhap();
        virtual void Xuat();
        virtual void CapNhat();
        virtual long TinhLuong() = 0;
        virtual void doc_File(ifstream& filein);
        virtual void xuat_File(ofstream& fileout);
        long getLuong(){
            return TinhLuong();
        }
        string getMaNV(){
        	return MaNV;
		}
        string getTen(){
            return HoTen;
        }
        string getQueQuan(){
        	return QueQuan;
		}
        int getSoNgayLam(){
            return SoNgayLam;
        }
        int getNamVaoLam(){
            return NamVaoLam;
        }
        void setChucVu(string cv);
        string getChucVu();
};

NhanVien::NhanVien(){
	HoTen = "";
	QueQuan = "";
    ChucVu = "";
	SoNgayLam = 0;
	PhuCap = 200000;
	NamVaoLam = 2021;
	Tienthuong = 0;
}

NhanVien::~NhanVien(){}

void NhanVien::setChucVu(string cv){
    this->ChucVu = cv;
}

string NhanVien::getChucVu(){
    return this->ChucVu;
}

void NhanVien::CapNhat() {
	int dem=0;  
    cout << "Nhap ma nhan vien: ";
    fflush(stdin);
    getline(cin, MaNV);
    cout << "Nhap ho va ten: ";
    fflush(stdin);
    getline(cin, HoTen);
    cout << "Nhap que quan: ";
    fflush(stdin);
    getline(cin, QueQuan);
    cout << "Nhap nam vao lam: ";
    cin >> NamVaoLam;
    cout << "Nhap so ngay lam: ";
    cin >> SoNgayLam;
    cout << "Nhap tien thuong: ";
    cin >> Tienthuong;
}

class LeTan:public NhanVien{
    protected:
    	long LuongCoBan = 450000;
    public:
        void Nhap();
        void Xuat();
        void CapNhat();
        long TinhLuong();
        void doc_File(ifstream& filein);
        void xuat_File(ofstream& fileout);
        
};

class BaoVe:public NhanVien{
    protected:
    	long LuongCoBan = 400000;
    public:
        void Nhap();
        void Xuat();
        void CapNhat();
        long TinhLuong();
        void doc_File(ifstream& filein);
        void xuat_File(ofstream& fileout);
};

class PhucVu:public NhanVien{
    protected:
    	long LuongCoBan = 500000;
    public:
        void Nhap();
        void Xuat();
        void CapNhat();
        long TinhLuong();
        void doc_File(ifstream& filein);
        void xuat_File(ofstream& fileout);
};

class DauBep:public NhanVien{
    protected:
    	long LuongCoBan = 600000;
    public:
        void Nhap();
        void Xuat();
        void CapNhat();
        long TinhLuong();
        void doc_File(ifstream& filein);
        void xuat_File(ofstream& fileout);
};

// doc file

void NhanVien::doc_File(ifstream& filein){
	getline(filein, MaNV, ',');
	filein.ignore();
	getline(filein, HoTen, ',');
	filein.ignore();
	getline(filein, QueQuan, ',');
	filein>>NamVaoLam;
	filein.ignore();
	filein>>SoNgayLam;
	filein.ignore();
	filein>>Tienthuong;
	filein.ignore();
}


void NhanVien::Nhap(){
	int dem =0;
    cout << "Cong thuc tinh luong: Luong co ban * So ngay lam + (Phu cap(200000 VND) * (2021-Nam vao lam)) + Tien thuong (VND)" << endl;
    cout << "Nhap ma nhan vien: ";
    fflush(stdin);
    getline(cin, MaNV);
    cout << "Nhap ho va ten: ";
    fflush(stdin);
    getline(cin, HoTen);
    cout << "Nhap que quan: ";
    fflush(stdin);
    getline(cin, QueQuan);
    cout << "Nhap nam vao lam: ";
    cin >> NamVaoLam;	
    cout << "Nhap so ngay lam: ";
    cin >> SoNgayLam;
    cout << "Nhap tien thuong: ";
    cin >> Tienthuong;
}

void NhanVien::Xuat(){
	cout << setw(12) << MaNV << setw(17) << this->getChucVu() << setw(20) << HoTen << setw(18);
	cout << QueQuan << setw(12) << NamVaoLam << setw(15) << SoNgayLam << setw(20) << TinhLuong() << " VND" << endl;
    
}

long LeTan::TinhLuong(){
	long Luong = 0;
    Luong = LuongCoBan * SoNgayLam + (PhuCap * (2021-NamVaoLam));
    return Luong;
}

long BaoVe::TinhLuong(){
    long Luong = 0;
    Luong = LuongCoBan * SoNgayLam + (PhuCap * (2021-NamVaoLam));
    return Luong;
}

long PhucVu::TinhLuong(){
    long Luong = 0;
    Luong = LuongCoBan * SoNgayLam + (PhuCap * (2021-NamVaoLam));
    return Luong;
}

long DauBep::TinhLuong(){
    long Luong = 0;
    Luong = LuongCoBan * SoNgayLam + (PhuCap * (2021-NamVaoLam));
    return Luong;
}

// Xuat file
void NhanVien::xuat_File(ofstream& fileout){
	fileout <<setw(12) << MaNV << setw(17) << this->getChucVu() << setw(20) << HoTen << setw(18);
	fileout <<QueQuan << setw(12) << NamVaoLam << setw(15) << SoNgayLam << setw(20) << TinhLuong() << " VND" << endl;
}


// le tan
void LeTan::doc_File(ifstream& filein){
	NhanVien::doc_File(filein);
}
void LeTan::Nhap(){
	cout << "Luong co ban mot ngay la 450000 VND." << endl;
	NhanVien::Nhap();
}

void LeTan::Xuat(){
	NhanVien::Xuat();
}
void LeTan::CapNhat() {
    NhanVien::CapNhat();
}
void LeTan::xuat_File(ofstream& fileout){
	NhanVien::xuat_File(fileout);
}

// bao ve
void BaoVe::doc_File(ifstream& filein){
	NhanVien::doc_File(filein);
}
void BaoVe::Nhap(){
	cout << "Luong co ban mot ngay la 400000 VND." << endl;
	NhanVien::Nhap();
}

void BaoVe::Xuat(){
	NhanVien::Xuat();
}
void BaoVe::CapNhat() {
    NhanVien::CapNhat();
}
void BaoVe::xuat_File(ofstream& fileout){
	NhanVien::xuat_File(fileout);
}

// phuc vu
void PhucVu::doc_File(ifstream& filein){
	NhanVien::doc_File(filein);
}
void PhucVu::Nhap(){
	cout << "Luong co ban mot ngay la 500000 VND." << endl;
	NhanVien::Nhap();
}

void PhucVu::Xuat(){
	NhanVien::Xuat();
}

void PhucVu::CapNhat() {
    NhanVien::CapNhat();
}
void PhucVu::xuat_File(ofstream& fileout){
	NhanVien::xuat_File(fileout);
}

// dau bep
void DauBep::doc_File(ifstream& filein){
	NhanVien::doc_File(filein);
}
void DauBep::Nhap(){
	cout << "Luong co ban mot ngay la 600000 VND." << endl;
	NhanVien::Nhap();
}

void DauBep::Xuat(){
	NhanVien::Xuat();
}

void DauBep::CapNhat() {
    NhanVien::CapNhat();
}
void DauBep::xuat_File(ofstream& fileout){
	NhanVien::xuat_File(fileout);
}

class QuanLyNhanVien{
	private:
		vector<NhanVien *> dsNhanVien;
		int n;
	public:
		void NhapDS();
		void XuatDS();
		void Xoa();
		void XoaDS();
		void SapXep();
		void CapNhat();
		void MaxLong();
		void TongLuong();
		void TimKiem_NV();
		void doc_File(ifstream& filein);
		void xuat_File(ofstream& fileout);
};

 //doc file
void QuanLyNhanVien::doc_File(ifstream& filein){
	filein.open("dulieu.txt", ios_base::in);
	if(!filein.is_open()){
		cout<<"\t\tKhong tim thay file!!";
	}
	else{
		filein>>n;
		filein.ignore();
		for(int i=0 ; i<n ;i++){
			dsNhanVien[i]->doc_File(filein);			
	}
		cout<<"\t\tDoc file thanh cong! ";	
		filein.ignore();
	}
}


//void QuanLyNhanVien::doc_File(ifstream& filein){
//	filein.open("dulieu.txt", ios_base::in);
//	if(!filein.is_open()){
//		cout<<"\t\tKhong tim thay file!!";
//	}
//	else{
//		filein >> n;
//		filein.ignore();
//		for(int i=0 ; i<n ;i++){
//			NhanVien *NV;
//			char c;
//			filein >> c;
//			if( c == 'Le Tan'){
//				NV = new LeTan;
//				NV->doc_File(filein);
//			}
//			else if(c == 'Bao Ve'){
//				NV = new BaoVe;
//				NV->doc_File(filein);
//			}
//			else if( c == 'Phuc Vu'){
//				NV = new PhucVu;
//				NV->doc_File(filein);
//			}
//			else if( c = 'Dau Bep'){
//			NV = new DauBep;
//			NV->doc_File(filein);
//			}
//			dsNhanVien[i] = NV;
//		}
//		cout<<"\t\tDoc file thanh cong! ";	
//		filein.ignore();
//	}
//}

//Nhap danh sach nhan vien
void QuanLyNhanVien::NhapDS(){  
	NhanVien *nv;
	int k;
	do{
        system("cls");
        cout << "\n\n";
        cout << setw(125) << "* * * * * * * QUAN LY NHAN VIEN KHACH SAN * * * * * * *" << endl;
        cout << "\n\n\n";
        cout << setw(125) << "========================================================" << endl;
	cout << setw(125) << "|| STT ||                  CHUC NANG                  ||" << endl;
	cout << setw(125) << "||=====||=============================================||" << endl;       
        cout << setw(125) << "||  1  || Le tan                                      ||" << endl;
        cout << setw(125) << "||  2  || Bao ve                                      ||" << endl;
        cout << setw(125) << "||  3  || Phuc vu                                     ||" << endl;
        cout << setw(125) << "||  4  || Dau bep                                     ||" << endl;
        cout << setw(125) << "||  0  || Quay lai menu chinh                         ||" << endl;
        cout << setw(125) << "========================================================" << endl;
        cout << setw(124) << "Chon chuc vu muon them: ";
        cin >> k;
        switch(k){
        	case 1:
                nv = new LeTan; 
                nv->Nhap();
                nv->setChucVu("Le Tan");
                dsNhanVien.push_back(nv); 
                break;
            case 2:
                nv = new BaoVe;
                nv->Nhap();
                nv->setChucVu("Bao ve");
                dsNhanVien.push_back(nv);            
                break;
            case 3:
                nv = new PhucVu;
                nv->Nhap();
                nv->setChucVu("Phuc vu");
				dsNhanVien.push_back(nv);
                break;
            case 4:
                nv = new DauBep;
                nv->Nhap();
                nv->setChucVu("Dau bep");
				dsNhanVien.push_back(nv);
                break;
            default:
				break;
		}
	} while (k != 0);
}



//Xuat danh sach nhan vien
void QuanLyNhanVien::XuatDS(){
	cout << setw(5) << "========================================================================================================================" << endl;
	cout << setw(5) << "||  MA NHAN VIEN  ||  CHUC VU  ||      HO VA TEN      ||  QUE QUAN  ||  NAM VAO LAM  ||  SO NGAY LAM  ||  TIEN LUONG  ||" << endl;
	cout << setw(5) << "========================================================================================================================" << endl;
	for (int i = 0; i < dsNhanVien.size(); i++){
		dsNhanVien[i]->Xuat();
	}
}

//Cap nhat thong tin nhan vien
void QuanLyNhanVien::CapNhat() {
	int key;
    string tukhoa;
    int dem = 0;
    do{
        system("cls");
        cout << "\n\n";
        cout << setw(125) << "* * * * * * * QUAN LY NHAN VIEN KHACH SAN * * * * * * *" << endl;
        cout << "\n\n\n";
        cout << setw(125) << "========================================================" << endl;
	cout << setw(125) << "|| STT ||                  CHUC NANG                  ||" << endl;
	cout << setw(125) << "||=====||=============================================||" << endl;       
        cout << setw(125) << "||  1  || Theo ma nhan vien                           ||" << endl;
        cout << setw(125) << "||  2  || Theo ten nhan vien                          ||" << endl;
        cout << setw(125) << "||  0  || Quay lai                                    ||" << endl;
        cout << setw(125) << "========================================================" << endl;
        cout << setw(124) <<"Chon chuc nang : "; 
		cin >> key;
        switch (key){
        case 1:
            cout << "\nNhap ma cua nhan vien muon cap nhat thong tin: ";
            cin.ignore();
            getline(cin, tukhoa);
            for(int i=0; i<dsNhanVien.size(); i++){
                char* str1 = new char[tukhoa.length()];
                strcpy(str1, tukhoa.c_str());
                char* str2 = new char[dsNhanVien.at(i)->getMaNV().length()];
                strcpy(str2, dsNhanVien.at(i)->getMaNV().c_str());
                if(strcmp(str1, str2) == 0){
                    dsNhanVien.at(i)->CapNhat();
                    cout << "\nCap nhat thong tin thanh cong!" << endl;
                    dem++;
                }
            }
            if(dem == 0) 
                cout << "\nKhong co nhan vien nay trong danh sach!" << endl;
            system("pause");
            break;
        case 2:
            cout << "\nNhap ten nhan vien muon cap nhat thong tin: ";
    		cin.ignore();
    		getline(cin, tukhoa);
    		for(int i=0; i<dsNhanVien.size(); i++) {
        	char* str1 = new char[tukhoa.length()];
        	strcpy(str1, tukhoa.c_str());
        	char* str2 = new char[dsNhanVien.at(i)->getTen().length()];
        	strcpy(str2, dsNhanVien.at(i)->getTen().c_str());
        	if(strcmp(str1, str2) == 0) {
            	dsNhanVien.at(i)->CapNhat();
            	cout << "\nCap nhat thong tin thanh cong!" << endl;
            	dem++;
        		}			
    		}
            if(dem == 0) 
                cout << "\nKhong co nhan vien nay trong danh sach!" << endl;
            system("pause");
            break;
        }
    }while(key != 0);
}

//Xoa nhan vien
void QuanLyNhanVien::Xoa(){
	int key, nam;
	string tukhoa;
	do{
        system("cls");
        cout << "\n\n";
        cout << setw(125) << "* * * * * * * QUAN LY NHAN VIEN KHACH SAN * * * * * * *" << endl;
        cout << "\n\n\n";
        cout << setw(125) << "========================================================" << endl;
	cout << setw(125) << "|| STT ||                  CHUC NANG                  ||" << endl;
	cout << setw(125) << "||=====||=============================================||" << endl;       
        cout << setw(125) << "||  1  || Theo ma nhan vien                           ||" << endl;
        cout << setw(125) << "||  2  || Theo ten nhan vien                          ||" << endl;
        cout << setw(125) << "||  3  || Theo nam vao lam                            ||" << endl;
        cout << setw(125) << "||  4  || Theo que quan                               ||" << endl;
        cout << setw(125) << "||  5  || Xoa toan bo nhan vien                       ||" << endl;
        cout << setw(125) << "||  0  || Quay lai                                    ||" << endl;
        cout << setw(125) << "========================================================" << endl;
        cout << setw(125) << "Chon chuc nang : "; 
		cin >> key;
        switch (key){
        	case 1:
        		cout << "\nNhap ma nhan vien muon xoa: ";
				cin.ignore();
				getline(cin, tukhoa);
				for(int i=0;i<dsNhanVien.size();i++){
					if(dsNhanVien[i]->getMaNV()==tukhoa){
						dsNhanVien.erase(dsNhanVien.begin()+(i-1));
						cout << "\nDa xoa thanh cong!" << endl;
					}
				}
				system("pause");
            	break;
			case 2:
				cout << "\nNhap ten nhan vien muon xoa: ";
				cin.ignore();
				getline(cin, tukhoa);
				for(int i=0;i<dsNhanVien.size();i++){
					if(dsNhanVien[i]->getTen()==tukhoa){
						dsNhanVien.erase(dsNhanVien.begin()+(i-1));
						cout << "\nDa xoa thanh cong!" << endl;
					}
				}
				system("pause");
            	break;
			case 3:
				cout << "\nNhap nam vao lam cua nhan vien muon xoa: ";
				cin >> nam;
				for(int i=0;i<dsNhanVien.size();i++){
					if(dsNhanVien[i]->getNamVaoLam()==nam){
						dsNhanVien.erase(dsNhanVien.begin()+(i-1));
						cout << "\nDa xoa thanh cong!" << endl;
					}
				}
				system("pause");
            	break;
			case 4:
				cout << "\nNhap que quan nhan vien muon xoa: ";
				cin.ignore();
				getline(cin, tukhoa);
				for(int i=0;i<dsNhanVien.size();i++){
					if(dsNhanVien[i]->getQueQuan()==tukhoa){
						dsNhanVien.erase(dsNhanVien.begin()+(i-1));
						cout << "\nDa xoa thanh cong!" << endl;
					}
				}
				system("pause");
            	break;
			case 5:
				dsNhanVien.clear();
				//Da xoa toan bo danh sach nhan vien thanh cong
				system("pause");
            	break;
            default:
            	break;
		} 
	}while (key != 0);
}

//Sap xep nhan vien theo luong  
void QuanLyNhanVien::SapXep(){
    int key, choose;
    do {
        system("cls");
        cout << "\n\n";
        cout << setw(125) << "* * * * * * * QUAN LY NHAN VIEN KHACH SAN * * * * * * *" << endl;
        cout << "\n\n\n";
        cout << setw(125) << "========================================================" << endl;
	cout << setw(125) << "|| STT ||                  CHUC NANG                  ||" << endl;
	cout << setw(125) << "||=====||=============================================||" << endl;
	cout << setw(125) << "||  1  || Theo ma nhan vien                           ||" << endl;       
        cout << setw(125) << "||  2  || Theo ten nhan vien                          ||" << endl;
        cout << setw(125) << "||  3  || Theo nam vao lam                            ||" << endl;
        cout << setw(125) << "||  4  || Theo luong                                  ||" << endl;
        cout << setw(125) << "||  0  || Quay lai                                    ||" << endl;
        cout << setw(125) << "========================================================" << endl;
        cout << setw(124) <<"Chon chuc nang : "; 
		cin >> key;
        switch (key){
        case 1:
            do{
                system("cls");
                cout << "\n\n";
        		cout << setw(125) << "* * * * * * * QUAN LY NHAN VIEN KHACH SAN * * * * * * *" << endl;
        		cout << "\n\n\n";
		        cout << setw(125) << "========================================================" << endl;
			cout << setw(125) << "|| STT ||                  CHUC NANG                  ||" << endl;
			cout << setw(125) << "||=====||=============================================||" << endl;       
		        cout << setw(125) << "||  1  || Chieu xuoi                                  ||" << endl;
		        cout << setw(125) << "||  2  || Chieu nguoc                                 ||" << endl;
		        cout << setw(125) << "||  0  || Quay lai                                    ||" << endl;
		        cout << setw(125) << "========================================================" << endl;
		        cout << setw(124) << "Chon chuc nang : "; 
				cin >> choose;
                switch (choose){
                case 1:
                    for(int i=0; i<dsNhanVien.size() -1; i++){
                        for(int j = dsNhanVien.size() - 1; j>i; j--){
                            char* str1 = new char[dsNhanVien.at(i)->getMaNV().length()];
                            strcpy(str1, dsNhanVien.at(i)->getTen().c_str());
                            char* str2 = new char[dsNhanVien.at(j)->getMaNV().length()];
                            strcpy(str2, dsNhanVien.at(j)->getTen().c_str());
                            if(strcmp(str1, str2) > 0){
                                NhanVien *tmp;
                                tmp = dsNhanVien.at(i);
                                dsNhanVien.at(i) = dsNhanVien.at(j);
                                dsNhanVien.at(j) = tmp;
                            }
                        }
                    }
                    XuatDS();
                    system("pause");
                    break;
                case 2:
                    for(int i=0; i<dsNhanVien.size() -1; i++){
                        for(int j = dsNhanVien.size() - 1; j>i; j--){
                            char* str1 = new char[dsNhanVien.at(i)->getMaNV().length()];
                            strcpy(str1, dsNhanVien.at(i)->getTen().c_str());
                            char* str2 = new char[dsNhanVien.at(j)->getMaNV().length()];
                            strcpy(str2, dsNhanVien.at(j)->getTen().c_str());
                            if(strcmp(str1, str2) < 0){
                                NhanVien *tmp;
                                tmp = dsNhanVien.at(i);
                                dsNhanVien.at(i) = dsNhanVien.at(j);
                                dsNhanVien.at(j) = tmp;
                            }
                        }
                    }
                    XuatDS();
                    system("pause");
                    break;
                default:
                    break;
                }
            }while(choose != 0);
            break;
                    
        case 2:
            do{
                system("cls");
                	cout << "\n\n";
        		cout << setw(125) << "* * * * * * * QUAN LY NHAN VIEN KHACH SAN * * * * * * *" << endl;
        		cout << "\n\n\n";
		        cout << setw(125) << "========================================================" << endl;
			cout << setw(125) << "|| STT ||                  CHUC NANG                  ||" << endl;
			cout << setw(125) << "||=====||=============================================||" << endl;       
		        cout << setw(125) << "||  1  || Chieu xuoi                                  ||" << endl;
		        cout << setw(125) << "||  2  || Chieu nguoc                                 ||" << endl;
		        cout << setw(125) << "||  0  || Quay lai                                    ||" << endl;
		        cout << setw(125) << "========================================================" << endl;
		        cout << setw(124) << "Chon chuc nang : "; 
				cin >> choose;
                switch (choose){
                case 1:
                    for(int i=0; i<dsNhanVien.size() -1; i++){
                        for(int j = dsNhanVien.size() - 1; j>i; j--){
                            char* str1 = new char[dsNhanVien.at(i)->getTen().length()];
                            strcpy(str1, dsNhanVien.at(i)->getTen().c_str());
                            char* str2 = new char[dsNhanVien.at(j)->getTen().length()];
                            strcpy(str2, dsNhanVien.at(j)->getTen().c_str());
                            if(strcmp(str1, str2) > 0){
                                NhanVien *tmp;
                                tmp = dsNhanVien.at(i);
                                dsNhanVien.at(i) = dsNhanVien.at(j);
                                dsNhanVien.at(j) = tmp;
                            }
                        }
                    }
                    XuatDS();
                    system("pause");
                    break;
                case 2:
                    for(int i=0; i<dsNhanVien.size() -1; i++){
                        for(int j = dsNhanVien.size() - 1; j>i; j--){
                            char* str1 = new char[dsNhanVien.at(i)->getTen().length()];
                            strcpy(str1, dsNhanVien.at(i)->getTen().c_str());
                            char* str2 = new char[dsNhanVien.at(j)->getTen().length()];
                            strcpy(str2, dsNhanVien.at(j)->getTen().c_str());
                            if(strcmp(str1, str2) < 0){
                                NhanVien *tmp;
                                tmp = dsNhanVien.at(i);
                                dsNhanVien.at(i) = dsNhanVien.at(j);
                                dsNhanVien.at(j) = tmp;
                            }
                        }
                    }
                    XuatDS();
                    system("pause");
                    break;
                default:
                    break;
                }
            }while(choose != 0);
            break;
        case 3:
            do{
                system("cls");
                cout << "\n\n";
                cout << setw(125) << "* * * * * * * QUAN LY NHAN VIEN KHACH SAN * * * * * * *" << endl;
        	cout << "\n\n\n";
		cout << setw(125) << "========================================================" << endl;
		cout << setw(125) << "|| STT ||                  CHUC NANG                  ||" << endl;
		cout << setw(125) << "||=====||=============================================||" << endl;       
		cout << setw(125) << "||  1  || Chieu xuoi                                  ||" << endl;
		cout << setw(125) << "||  2  || Chieu nguoc                                 ||" << endl;
		cout << setw(125) << "||  0  || Quay lai                                    ||" << endl;
		cout << setw(125) << "========================================================" << endl;
		cout << setw(124) << "Chon chuc nang : "; 
		cin >> choose;
                switch (choose){
                case 1:
                    for(int i=0; i<dsNhanVien.size() -1; i++){
                        for(int j = dsNhanVien.size() - 1; j>i; j--){
                            if(dsNhanVien.at(i)->getNamVaoLam() > dsNhanVien.at(j)->getNamVaoLam()){
                                NhanVien *tmp;
                                tmp = dsNhanVien.at(i);
                                dsNhanVien.at(i) = dsNhanVien.at(j);
                                dsNhanVien.at(j) = tmp;
                            }
                        }
                    }
                    XuatDS();
                    system("pause");
                    break;
                case 2:
                    for(int i=0; i<dsNhanVien.size() -1; i++){
                        for(int j = dsNhanVien.size() - 1; j>i; j--){
                            if(dsNhanVien.at(i)->getNamVaoLam() < dsNhanVien.at(j)->getNamVaoLam()){
                                NhanVien *tmp;
                                tmp = dsNhanVien.at(i);
                                dsNhanVien.at(i) = dsNhanVien.at(j);
                                dsNhanVien.at(j) = tmp;
                            }
                        }
                    }
                    XuatDS();
                    system("pause");
                    break;
                default:
                    break;
                }
            }while(choose != 0);
            break;
        case 4:
            do{
                system("cls");
                cout << "\n\n";
        	cout << setw(125) << "* * * * * * * QUAN LY NHAN VIEN KHACH SAN * * * * * * *" << endl;
        	cout << "\n\n\n";
		cout << setw(125) << "========================================================" << endl;
		cout << setw(125) << "|| STT ||                  CHUC NANG                  ||" << endl;
		cout << setw(125) << "||=====||=============================================||" << endl;       
		cout << setw(125) << "||  1  || Chieu xuoi                                  ||" << endl;
		cout << setw(125) << "||  2  || Chieu nguoc                                 ||" << endl;
		cout << setw(125) << "||  0  || Quay lai                                    ||" << endl;
		cout << setw(125) << "========================================================" << endl;
		cout << setw(124) << "Chon chuc nang : "; 
		cin >> choose;
                switch (choose){
                case 1:
                    for(int i=0; i<dsNhanVien.size() -1; i++){
                        for(int j = dsNhanVien.size() - 1; j>i; j--){
                            if(dsNhanVien.at(i)->getLuong() > dsNhanVien.at(j)->getLuong()){
                                NhanVien *tmp;
                                tmp = dsNhanVien.at(i);
                                dsNhanVien.at(i) = dsNhanVien.at(j);
                                dsNhanVien.at(j) = tmp;
                            }
                        }
                    }
                    XuatDS();
                    system("pause");
                    break;
                case 2:
                    for(int i=0; i<dsNhanVien.size() -1; i++){
                        for(int j = dsNhanVien.size() - 1; j>i; j--){
                            if(dsNhanVien.at(i)->getLuong() < dsNhanVien.at(j)->getLuong()){
                                NhanVien *tmp;
                                tmp = dsNhanVien.at(i);
                                dsNhanVien.at(i) = dsNhanVien.at(j);
                                dsNhanVien.at(j) = tmp;
                            }
                        }
                    }
                    XuatDS();
                    system("pause");
                    break;
                default:
                    break;
                }
            }while(choose != 0);
            break;
        default:
            break;
        }
    }while(key != 0);
}

//Nhan vien co luong cao nhat
void QuanLyNhanVien::MaxLong(){
    NhanVien *max=dsNhanVien.at(0);
    for(int i=1;i<dsNhanVien.size();i++){
        if(dsNhanVien.at(i)->getLuong() > max->getLuong())
            max = dsNhanVien.at(i);
    }
    cout<<endl<<"Nhan Vien co Luong cao nhat: "<<endl;
    max->Xuat();
}

//Tim kiem nhan vien
void QuanLyNhanVien::TimKiem_NV(){
    int key, nam, dem = 0;
    string tukhoa;
    do{
        system("cls");
        cout << "\n\n";
        cout << setw(125) << "* * * * * * * QUAN LY NHAN VIEN KHACH SAN * * * * * * *" << endl;
        cout << "\n\n\n";
        cout << setw(125) << "========================================================" << endl;
	cout << setw(125) << "|| STT ||                  CHUC NANG                  ||" << endl;
	cout << setw(125) << "||=====||=============================================||" << endl;       
        cout << setw(125) << "||  1  || Theo ma nhan vien                           ||" << endl;
        cout << setw(125) << "||  2  || Theo ten nhan vien                          ||" << endl;
        cout << setw(125) << "||  3  || Theo nam vao lam                            ||" << endl;
        cout << setw(125) << "||  4  || Theo que quan                               ||" << endl;
        cout << setw(125) << "||  0  || Quay lai                                    ||" << endl;
        cout << setw(125) << "========================================================" << endl;
        cout << setw(124) << "Chon chuc nang : "; 
	cin >> key;
        switch (key){
        case 1:
            cout << "\nNhap ma nhan vien muon tim: ";
            cin.ignore();
            getline(cin, tukhoa);
            for(int i=0; i<dsNhanVien.size(); i++){
                char* str1 = new char[tukhoa.length()];
                strcpy(str1, tukhoa.c_str());
                char* str2 = new char[dsNhanVien.at(i)->getMaNV().length()];
                strcpy(str2, dsNhanVien.at(i)->getMaNV().c_str());
                if(strcmp(str1, str2) == 0){
                    dsNhanVien.at(i)->Xuat();
                    dem++;
                }
            }
            if(dem == 0) 
                cout << "\nKhong co nhan vien nay trong danh sach!" << endl;
            system("pause");
            break;
        case 2:
            cout << "\nNhap ten nhan vien muon tim: ";
            cin.ignore();
            getline(cin, tukhoa);
            for(int i=0; i<dsNhanVien.size(); i++){
                char* str1 = new char[tukhoa.length()+1];
                strcpy(str1, tukhoa.c_str());
                char* str2 = new char[dsNhanVien.at(i)->getTen().length()];
                strcpy(str2, dsNhanVien.at(i)->getTen().c_str());
                if(strcmp(str1, str2) == 0){
                    dsNhanVien.at(i)->Xuat();
                    dem++;
                }
            }
            if(dem == 0) 
                cout << "\nKhong co nhan vien nay trong danh sach!" << endl;
            system("pause");
            break;
        case 3:
            cout << "\nNhap nam vao lam muon tim: ";
            cin >> nam;
            for(int i=0; i<dsNhanVien.size(); i++){
                if(nam == dsNhanVien.at(i)->getNamVaoLam()){
                    dsNhanVien.at(i)->Xuat();
                    dem++;
                }
            }
            if(dem == 0) 
                cout << "\nKhong co nhan vien nay trong danh sach!" << endl;
            system("pause");
            break;
        case 4:
            cout << "\nNhap que quan nhan vien muon tim: ";
            cin.ignore();
            getline(cin, tukhoa);
            for(int i=0; i<dsNhanVien.size(); i++){
                char* str1 = new char[tukhoa.length()];
                strcpy(str1, tukhoa.c_str());
                char* str2 = new char[dsNhanVien.at(i)->getQueQuan().length()];
                strcpy(str2, dsNhanVien.at(i)->getQueQuan().c_str());
                if(strcmp(str1, str2) == 0){
                    dsNhanVien.at(i)->Xuat();
                    dem++;
                }
            }
            if(dem == 0) 
                cout << "\nKhong co nhan vien nay trong danh sach!" << endl;
            system("pause");
            break;
        default:
            break;
        }
    }while(key != 0);
}

//Tong tien khach san tra luong cho nhan vien
void QuanLyNhanVien::TongLuong(){
    long tong=0;
    for(int i=0;i<dsNhanVien.size();i++){
        tong += dsNhanVien.at(i)->getLuong();
    }
    cout<<endl<<"Tong tien khach san tra luong cho nhan vien: "<<tong<< " VND" << endl;
}

// xuat file

void QuanLyNhanVien::xuat_File(ofstream& fileout){
	fileout.open("xuatdulieu.txt", ios_base::out);
	fileout << "========================================================================================================================" << endl;
	fileout << "||  MA NHAN VIEN  ||  CHUC VU  ||      HO VA TEN      ||  QUE QUAN  ||  NAM VAO LAM  ||  SO NGAY LAM  ||  TIEN LUONG  ||" << endl;
	fileout << "========================================================================================================================" << endl;
	for(int i=0 ; i<n ;i++){
			dsNhanVien[i]->xuat_File(fileout);
			fileout<<"========================================================================================================================" <<endl;
	}
	fileout.close();
}


//Menu
int Menu(){
    int k;
    ifstream filein;
    ofstream fileout;
    bool daDoc = false;
    QuanLyNhanVien qlnv;
    system("Color B0");
	do{
        system("cls");
        cout << "\n\n";
        cout << setw(125) << "* * * * * * * QUAN LY NHAN VIEN KHACH SAN * * * * * * *" << endl;
        cout << "\n\n\n";
        cout << setw(125) << "========================================================" << endl;
	cout << setw(125) << "|| STT ||                  CHUC NANG                  ||" << endl;
	cout << setw(125) << "||=====||=============================================||" << endl;        
        cout << setw(125) << "||  1  || Nhap nhan vien                              ||" << endl;
        cout << setw(125) << "||  2  || Xuat nhan vien                              ||" << endl;
        cout << setw(125) << "||  3  || Cap nhat thong tin nhan vien                ||" << endl;
        cout << setw(125) << "||  4  || Xoa nhan vien                               ||" << endl;
        cout << setw(125) << "||  5  || Sap xep luong nhan vien                     ||" << endl;
        cout << setw(125) << "||  6  || Nhan vien co luong cao nhat                 ||" << endl;
        cout << setw(125) << "||  7  || Tim kiem nhan vien                          ||" << endl;
        cout << setw(125) << "||  8  || Tong luong khach san phai tra cho nhan vien ||" << endl;
        cout << setw(125) << "||  9  || Doc du lieu tu file                         ||" << endl;
        cout << setw(125) << "||  10 || Xuat file                                   ||" << endl;
        cout << setw(125) << "||  0  || Thoat chuong trinh                          ||" << endl;
        cout << setw(125) << "========================================================" << endl;
        cout << setw(124) << "Chon chuc nang: ";
        cin >> k;
        switch(k){
            case 1:
                qlnv.NhapDS();
                break;
            case 2:
            	qlnv.XuatDS();
                system("pause");
    			break;
    		case 3:
                qlnv.CapNhat();
                system("pause");
                break;
            case 4:
            	qlnv.Xoa();
            	system("pause");
            	break;
            case 5:
                qlnv.SapXep();
                system("pause");
                break;
            case 6:
                qlnv.MaxLong();
                system("pause");
                break;
            case 7:   
                qlnv.TimKiem_NV();
                system("pause");
                break;
            case 8:
                qlnv.TongLuong();
                system("pause");
                break;
            case 9:
            	cout<<"\nBan da doc file thanh cong!\n ";
            	system("cls");
            	qlnv.doc_File(filein);
            	daDoc = true;
            	cout<<"\n\tNhan phim bat ky de tiep tuc! \n";
            	getch();
            	break;
            case 10:
            	system("cls");
            	if(daDoc){
            		cout<<"\nBan da Chon xuat file !\n";
            		qlnv.xuat_File(fileout);
            		cout<<"\nXuat file thanh cong!\n";
				}
				else{
					cout<<"\n\t\tVui long doc file truoc!\n";
				}
				cout<<"\n\t\tNhan phim bat ky de tiep tuc\n";
				getch();
				break;
    		default:
    			return 0;
				break;
        }
    } while(k != 0);
}

int main(){
	SetWindowSize(1000,250);
	SetScreenBufferSize(1000,250);
	ShowScrollbar(0);
	SetConsoleTitle("QUAN LY NHAN VIEN KHACH SAN");
	Menu();
}
